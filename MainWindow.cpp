#include <QPainter>

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QRect rect(0, 0, width() / 2, height() / 2);
	painter.setBrush(QBrush(Qt::red));
	painter.drawRect(rect);
}
