#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

protected:
	void paintEvent(QPaintEvent *) override;

private slots:
	void on_actionSave_triggered();

	void on_actionNext_triggered();

	void on_actionPrevious_triggered();

private:
	Ui::MainWindow *ui;
	int step;
};

#endif // MAINWINDOW_H
