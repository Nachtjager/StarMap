#include "dataworker.h"

DataWorker::DataWorker()
{

}

QString DataWorker::compare(QGraphicsItem *item)
{
    for (int i = 0; i < currentDataMass.size(); i++)
    {
        if (currentDataMass[i].img == item)
        {
            qDebug() << currentDataMass[i].name;
            //TODO
        }
        else
        {
            qDebug() << "Мимо";
            //TODO
        }
    }
    return "test";
}

void DataWorker::readData(QString path)
{
    QFile file(path);
    maxx = -1;
    maxy = -1;
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"Файла нет";
        return;
    }
    else {
        QXmlStreamReader xmlReader;
        xmlReader.setDevice(&file);
        xmlReader.readNext();
        object tmp;
        while(!xmlReader.atEnd())
        {
            if(xmlReader.isStartElement())
            {
                if(xmlReader.name() == "ID")
                {
                    tmp.ID = xmlReader.readElementText().toInt();
                }
                else if(xmlReader.name() == "name")
                {
                    tmp.name = xmlReader.readElementText();
                }
                else if (xmlReader.name() == "pathToImage")
                {
                    QString path = xmlReader.readElementText();
                    QPixmap img(path);
                    QGraphicsPixmapItem * item = new QGraphicsPixmapItem(img);
                    tmp.img = item;
                }
                else if (xmlReader.name() == "x")
                {
                    tmp.x = xmlReader.readElementText().toInt();
                    if(tmp.x > maxx)
                        maxx = tmp.x;
                    tmp.x += 300;
                }
                else if (xmlReader.name() == "y")
                {
                    tmp.y = xmlReader.readElementText().toInt();
                    if(tmp.y > maxy)
                        maxy = tmp.y;
                    tmp.y += 300;
                }
                else if (xmlReader.name() == "parent")
                {
                    tmp.parent = xmlReader.readElementText().toInt();
                }
                else if (xmlReader.name() == "binary")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes())
                    {
                        if (attr.name().toString() == "boolean")
                        {
                            QString attribute_value = attr.value().toString();
                            if (QString::compare(attribute_value , "true") == 0)
                            {
                                tmp.flagBinary = true;
                                tmp.binary = xmlReader.readElementText().toInt();
                            }
                        }
                    }

                }
                else if (xmlReader.name() == "info")
                {
                    tmp.info = xmlReader.readElementText();
                }
                else if (xmlReader.name()== "end")
                {
                    tmp.img->setPos(tmp.x,tmp.y);
                    currentDataMass.append(tmp);
                }
            }
            xmlReader.readNext();
        }
        file.close();
    }
}

QList<object> &DataWorker::getMass()
{
    return currentDataMass;
}

QRectF DataWorker::getSize()
{
    QRectF tmp(0,0,maxx+600,maxy+600);
    return tmp;
}
