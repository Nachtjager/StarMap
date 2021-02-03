#ifndef DATAWORKER_H
#define DATAWORKER_H

#include <datastruct.h>

#include <QtXml>
#include <QList>
#include <QString>

class DataWorker
{
public:
    DataWorker();
    QString compare (QGraphicsItem* item);
    void readData(QString path);
    QList<object>& getMass();
    QRectF getSize();
private:
    QList<object>currentDataMass;
    int maxx;
    int maxy;
};

#endif // DATAWORKER_H
