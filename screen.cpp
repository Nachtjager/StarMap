#include "screen.h"
#include "ui_screen.h"

#include <QListWidgetItem>

Screen::Screen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Screen)
{
    ui->setupUi(this);

    scene = new MapScene();
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QColor(30,30,30));
    QDir dir("xml/");
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);   ///устанавливаем фильтр выводимых файлов/папок (см ниже)
    dir.setSorting(QDir::Name | QDir::Reversed);
    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        QString DataName = list.at(i).fileName();
        if (DataName.indexOf(".xml",DataName.size()-5) != -1)
        {
            DataName.chop(4);
            ui->listWidget->addItem(DataName);
        }
    }
}

Screen::~Screen()
{
    delete ui;
}

void Screen::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    scene->changeData(current->text());
}
