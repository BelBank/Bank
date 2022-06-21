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
	setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::Dialog);
	setAttribute(Qt::WA_TranslucentBackground, true);
	setWindowFlags(Qt::FramelessWindowHint);
}


void MainWindowAfterLog::on_PB_log_out_clicked()
{
	this->close();
	MainWindow n;
	n.show();
}

MainWindowAfterLog::~MainWindowAfterLog()
{
}
