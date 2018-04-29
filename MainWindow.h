#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QSettings>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow() override;

protected:
	void paintEvent(QPaintEvent *) override;

private slots:
	void on_actionSave_triggered();

	void on_actionNext_triggered();

	void on_actionPrevious_triggered();

private:
	void paint(QPainter *painter, int width, int height, int step);

	Ui::MainWindow *ui;
	QSettings _settings;
	int _step;
};

#endif // MAINWINDOW_H
