#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameworld.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GameWorld* scene = new GameWorld();
    scene->init();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

    m_timer = startTimer(50);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionQuit_triggered()
{
    killTimer(m_timer);
    close();
}


void MainWindow::timerEvent(QTimerEvent *)
{
    GameWorld* scene = dynamic_cast<GameWorld*>(ui->graphicsView->scene());
    if ( !scene->advance())
    {
        killTimer(m_timer);
    }
}
