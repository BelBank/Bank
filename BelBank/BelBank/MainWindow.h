#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include ""
#include <qpushbutton.h>
#include <qlineedit.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
	
    void on_PB_clicked();
	

private:
    Ui::MainWindow ui; ///log window///
};
