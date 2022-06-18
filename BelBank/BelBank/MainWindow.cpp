#include "MainWindow.h"
#include "MainWindowAfterLog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	ui.LE_2->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_PB_clicked() {
    MainWindowAfterLog *m = new MainWindowAfterLog();
	m->show();
	this->hide();
	
}


