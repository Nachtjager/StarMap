#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <datastruct.h>
#include <dataworker.h>

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class MapScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit MapScene(QObject *parent = 0);
    ~MapScene();
    void paint(QList<object> data);
    void changeData(QString name);

private:

    DataWorker worker;


private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);


};

#endif // MAPSCENE_H
