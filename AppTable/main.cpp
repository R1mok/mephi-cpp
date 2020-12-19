#include "AppTable.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	AppTable w;
	w.setFixedHeight(500);
	w.setFixedWidth(500);
	w.show();


	return app.exec();
}