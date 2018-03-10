#include <QPainter>
#include <QFileDialog>

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	step(0)
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
	painter.fillRect(this->rect(), QBrush(Qt::black));

	if ( step % 2 == 0) {
		painter.setBrush(QBrush(Qt::yellow));
		painter.drawEllipse(this->rect());//, width() / 2, height() / 2);
	}

	QRect rect;
	if ((step  / 2) % 2) {
		rect.setX(width() / 2);
	}
	if ((step / 4) % 2) {
		rect.setY(height() / 2);
	}
	rect.setWidth(width() / 2);
	rect.setHeight(height() / 2);
	painter.setBrush(QBrush(Qt::red));
	painter.drawRect(rect);
}

void MainWindow::on_actionSave_triggered()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save..."), "", "*.png");

	if (!fileName.isEmpty()) {
		QImage image = grab().toImage();
		image.save(fileName);
	}
}

void MainWindow::on_actionNext_triggered()
{
	step++;
	this->update();
}

void MainWindow::on_actionPrevious_triggered()
{
	step--;
	this->update();
}
