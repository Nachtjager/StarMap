#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include <QString>
#include <QGraphicsPixmapItem>

struct object{
    unsigned int ID;
    QString name = "unknown";
    QGraphicsPixmapItem* img;
    int x;
    int y;
    unsigned int parent;
    bool flagBinary = false;
    unsigned int binary;
    QString info;
    bool operator == (const object & a2)
    {
        if (ID == a2.ID)
            return true;
        else
            return false;
    }
};



#endif // DATASTRUCT_H
