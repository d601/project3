#include <QApplication>
#include <QTime>

#include "Window.h"

int main(int argc, char **argv) {
	QApplication app(argc, argv);

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

	Window window;
	window.show();

	return app.exec();
}
