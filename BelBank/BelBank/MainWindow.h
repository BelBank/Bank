//    That's an example of an internet banking system and this is a practice project
//    Copyright(C) 2022 Shchirov P.D, Skvortsov A. V, Kosmin P. M.
//
//    This program is free software : you can redistribute it and /or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
//    GNU General Public License for more details.




#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "ui_Registration.h"
#include "Client.h"
#include "qmessagebox.h"
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qradiobutton.h>
#include "MainWindowAfterLog.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
	
    void on_PB_clicked();
	void on_PB_registration_clicked();
    void on_PB_sign_up_clicked();

    //void on_PB_sign_in_clicked();
	

private:
    
    Ui::MainWindow ui; ///log window///
    Ui::Registration ui_sign_up;
    QMainWindow* window_sign_up;
    db_pool database;
};



