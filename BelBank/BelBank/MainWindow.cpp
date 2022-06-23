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


#include "MainWindow.h"
#include "MainWindowAfterLog.h"


MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	window_sign_up = new QMainWindow;
	ui_sign_up.setupUi(window_sign_up);
	window_sign_up->setWindowFlag(Qt::WindowStaysOnTopHint);
	window_sign_up->setWindowModality(Qt::ApplicationModal);
	database.connect("postgresql://host='postgresql-81012-0.cloudclusters.net' port='12018' dbname='bank' user='root' password='drakonkapusta'");
	ui.LE_password->setEchoMode(QLineEdit::Password);
	ui_sign_up.LE_new_password->setEchoMode(QLineEdit::Password);
	ui_sign_up.LE_confirm_password->setEchoMode(QLineEdit::Password);
	//setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::Dialog);
	setAttribute(Qt::WA_TranslucentBackground, true);
	//setWindowFlags(Qt::FramelessWindowHint);
	connect(ui_sign_up.PB_sign_up, SIGNAL(clicked()), this, SLOT(on_PB_sign_up_clicked()));
}

MainWindow::~MainWindow()
{

}
//void MainWindow::on_PB_clicked() {
////    MainWindowAfterLog *m = new MainWindowAfterLog();
////	this->close();
////	m->show();
////}


void MainWindow::on_PB_clicked()
{
	try
	{
		soci::session sql(*database.get_pool());
		std::string login = ui.LE_login->text().toStdString();
		std::string password = ui.LE_password->text().toStdString();
		Client info;
		soci::indicator ind;
		info.password = info.hash_password(password);
		sql << "SELECT * FROM bank_login WHERE login = :login AND password = :password", soci::into(info, ind), soci::use(login), soci::use(info.password);
		if (info.login == "" || info.password == "")
		{
			QMessageBox::warning(this, "Error", "Wrong login or password!");
		}
		else
		{
			MainWindowAfterLog* m = new MainWindowAfterLog();
			this->close();
			m->show();
		}
	}
	catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
}


void MainWindow::on_PB_registration_clicked()
{
	window_sign_up->show();
}

void MainWindow::on_PB_sign_up_clicked()
{
	if (ui_sign_up.LE_new_login->text().isEmpty() ||
		ui_sign_up.LE_new_password->text().isEmpty() ||
		ui_sign_up.LE_confirm_password->text().isEmpty())
	{
		QMessageBox* message = new QMessageBox(QMessageBox::Warning, "Error", "Fill all fields!");
		message->setWindowFlag(Qt::WindowStaysOnTopHint);
		message->show();
		return;
	}
	else if (ui_sign_up.LE_new_password->text() != ui_sign_up.LE_confirm_password->text())
	{
		QMessageBox* message = new QMessageBox(QMessageBox::Warning, "Error", "Passwords are not equal!");
		message->setWindowFlag(Qt::WindowStaysOnTopHint);
		message->show();
		return;
	}
	else
	{
		try
		{
			soci::session sql(*database.get_pool());
			std::string login = ui_sign_up.LE_new_login->text().toStdString();
			std::string password = ui_sign_up.LE_new_password->text().toStdString();
			Client info;
			soci::indicator ind;
			sql << "SELECT * FROM bank_login WHERE login = :login", soci::into(info, ind), soci::use(login);
			if (info.login == "")
			{
				info.password = info.hash_password(password);
				sql << "INSERT INTO bank_login (login, password) VALUES (:login, :password)", soci::use(login), soci::use(info.password);
				QMessageBox* message = new QMessageBox(QMessageBox::Information, "Success", "You are registered!");
				message->setWindowFlag(Qt::WindowStaysOnTopHint);
				message->show();
				if (message->exec() == QMessageBox::Ok)
				{
					message->close();
					window_sign_up->close();
				}
				return;
			}
			else
			{
				QMessageBox* message = new QMessageBox(QMessageBox::Warning, "Error", "Login is already used!");
				message->setWindowFlag(Qt::WindowStaysOnTopHint);
				message->show();
				return;
			}
		}
		catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
	}
}