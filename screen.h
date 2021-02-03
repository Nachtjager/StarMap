#ifndef SCREEN_H
#define SCREEN_H

#include <mapscene.h>

#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QListWidgetItem>


namespace Ui {
class Screen;
}

class Screen : public QWidget
{
    Q_OBJECT

public:
    explicit Screen(QWidget *parent = 0);
    ~Screen();

private slots:

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::Screen *ui;
    MapScene *scene;
};

#endif // SCREEN_H
