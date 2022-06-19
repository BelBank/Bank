#include "MainWindowAfterLog.h"
#include <qpixmap.h>

MainWindowAfterLog::MainWindowAfterLog(QWidget *parent)
	: QMainWindow(parent)
{
	ui1.setupUi(this);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::Dialog);
	QPixmap fon{ ": / MainWindow / fon.jpg" };
	setAttribute(Qt::WA_TranslucentBackground, true);
	setWindowFlags(Qt::FramelessWindowHint);
}


MainWindowAfterLog::~MainWindowAfterLog()
{}
