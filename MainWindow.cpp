#include <QFileDialog>

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	_step(0)
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
	paint(&painter, width(), height(), _step);
}

void MainWindow::on_actionSave_triggered()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save..."), _settings.value("lastDocument", QDir::homePath()).toString(), "*.png");

	if (!fileName.isEmpty()) {
		int width = 256;
		int height = 256;
		QPixmap pixmap(width, height);
		QPainter painter(&pixmap);
		paint(&painter, width, height, _step);
		QImage image = pixmap.toImage();
		image.save(fileName);
		_settings.setValue("lastDocument", fileName);
	}
}

void MainWindow::on_actionNext_triggered()
{
	_step++;
	this->update();
}

void MainWindow::on_actionPrevious_triggered()
{
	_step--;
	this->update();
}

void MainWindow::paint(QPainter *painter, int width, int height, int step)
{
	painter->fillRect(this->rect(), QBrush(Qt::black));

	if ( step % 2 == 0) {
		painter->setBrush(QBrush(Qt::yellow));
		painter->drawEllipse(QRect(0, 0, width, height));
	}

	QRect rect;
	if ((step  / 2) % 2) {
		rect.setX(width / 2);
	}
	if ((step / 4) % 2) {
		rect.setY(height / 2);
	}
	rect.setWidth(width / 2);
	rect.setHeight(height / 2);
	painter->setBrush(QBrush(Qt::red));
	painter->drawRect(rect);
}
