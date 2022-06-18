#pragma once

#include <QMainWindow>
#include "ui_MainWindowAfterLog.h"

class MainWindowAfterLog : public QMainWindow
{
	Q_OBJECT

public:
	MainWindowAfterLog(QWidget *parent = nullptr);
	~MainWindowAfterLog();

private:
	Ui::MainWindowAfterLogClass ui1;//window for main room of bank///
};
