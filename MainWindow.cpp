#include <QPainter>
#include <QFileDialog>

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
	painter.fillRect(this->rect(), QBrush(Qt::black));
	QRect rect(0, 0, width() / 2, height() / 2);
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
