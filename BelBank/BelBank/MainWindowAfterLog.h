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

#include <QMainWindow>
#include "ui_MainWindowAfterLog.h"
#include <qtabwidget.h>


class MainWindowAfterLog : public QMainWindow
{
	Q_OBJECT

public:
	MainWindowAfterLog(QWidget *parent = nullptr);
	~MainWindowAfterLog();

private slots:
	void on_PB_log_out_clicked();

private:
	Ui::MainWindowAfterLog ui1;//window for main room of bank///
};
