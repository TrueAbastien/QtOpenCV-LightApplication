#include "ImageModifierApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ImageModifierApp w;
	w.show();
	return a.exec();
}
