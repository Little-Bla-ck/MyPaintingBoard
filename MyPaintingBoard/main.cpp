#include "MyPaintingBoard.h"
#include <QtWidgets/QApplication>
#include <qfile.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/MyPaintingBoard/resource/style.qss");
    file.open(QFile::ReadOnly);
    qApp->setStyleSheet(file.readAll());
    file.close();

    MyPaintingBoard w;
    w.show();
    return a.exec();
}
