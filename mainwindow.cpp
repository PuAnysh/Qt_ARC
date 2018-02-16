#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startBtn , &QPushButton::clicked , this , &MainWindow::onStartBtnClicked);
    connect(ui->stopBtn , &QPushButton::clicked , this , &MainWindow::onStopBtnClicked);
    connect(ui->workBtn , &QPushButton::clicked , this , &MainWindow::onWorkBtnClick);
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
int MainWindow::onWorkBtnClick()
{
    char* filename = "/home/huangyc/0/5.jpg";
    QImage img(filename);
    uchar* bits =  img.bits();
    uchar* tmp = (uchar*) malloc(img.byteCount()/4*3);
    int top = 0;
    qDebug()<<img.byteCount()<<endl;
    for(int i = 0 ; i < img.byteCount() ; i++){
        if((i+1)%4 == 0) continue;
        tmp[top++] = bits[i];
    }
    return engine.addFeature((uchar*) tmp , img.width() , img.height() , ASVL_PAF_RGB24_B8G8R8);

}
