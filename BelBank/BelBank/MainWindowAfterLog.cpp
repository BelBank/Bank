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


#include "MainWindowAfterLog.h"
#include "MainWindow.h"
#include <qpixmap.h>

MainWindowAfterLog::MainWindowAfterLog(QWidget *parent)
	: QMainWindow(parent)
{
	ui1.setupUi(this);
	new_card_window = new QMainWindow();
	new_card_ui.setupUi(new_card_window);
	new_card_window->setWindowFlag(Qt::WindowStaysOnTopHint);
	new_card_window->setWindowModality(Qt::ApplicationModal);
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::Dialog);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setWindowFlags(Qt::FramelessWindowHint);
	ui1.LE_password_to_create_new_card->setEchoMode(QLineEdit::Password);
}


void MainWindowAfterLog::on_PB_log_out_clicked()
{
	/*this->close();
	MainWindow *w = new MainWindow();
	w->show();*/
}

void MainWindowAfterLog::on_PB_new_card_clicked()
{
	std::string passsword = ui1.LE_password_to_create_new_card->text().toStdString();
//	soci::session sql(*database.get_pool());
	
	
	new_card_window->show();
}


MainWindowAfterLog::~MainWindowAfterLog()
{
}

