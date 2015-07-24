#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>


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
    virtual void timerEvent( QTimerEvent* );

private:
    Ui::MainWindow *ui;
    int m_timer;

private slots:
    void on_actionQuit_triggered();
};

#endif // MAINWINDOW_H
