#include "mapscene.h"

MapScene::MapScene(QObject *parent) : QGraphicsScene(parent)
{

}

MapScene::~MapScene()
{

}

void MapScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem* item = this->itemAt(event->scenePos(),QTransform());
    worker.compare(item);
}

//TODO: Delete this if don't need
void MapScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}

void MapScene::paint(QList<object> data)
{
    this->setSceneRect(worker.getSize());
    for(int i = 0; i < data.size(); i++)
    {
        this->addItem(data[i].img);
    }
}

void MapScene::changeData(QString name)
{
    worker.readData("xml/"+name+".xml");
    paint(worker.getMass());
}
