#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startBtn , &QPushButton::clicked , this , &MainWindow::onStartBtnClicked);
    connect(ui->stopBtn , &QPushButton::clicked , this , &MainWindow::onStopBtnClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::onStartBtnClicked()
{
    engine.InitEngine();
}

int MainWindow::onStopBtnClicked()
{
    engine.UninitialEngine();
}
