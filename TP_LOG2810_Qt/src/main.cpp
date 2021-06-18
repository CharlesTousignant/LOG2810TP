
#include <QtWidgets/QApplication>

#include "ChoixApplication.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChoixApplication w;
	w.show();
	return a.exec();
}
