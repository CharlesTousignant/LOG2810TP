#include "TP_LOG2810_Qt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TP_LOG2810_Qt w;
    w.show();
    return a.exec();
}
