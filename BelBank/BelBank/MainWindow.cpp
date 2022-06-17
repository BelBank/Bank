#include "MainWindow.h"

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

}


