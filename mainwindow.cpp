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
    engine.setDB(&db);
}

int MainWindow::onStopBtnClicked()
{
    engine.UninitialEngine();
}
int MainWindow::onWorkBtnClick()
{
    char* filename = "/home/huangyc/0/0.jpg";
    QImage img(filename);
    uchar* bits =  img.bits();
    uchar* tmp = (uchar*) malloc(img.byteCount()/4*3);
    int top = 0;
    for(int i = 0 ; i < img.byteCount() ; i++){
        if((i+1)%4 == 0) continue;
        tmp[top++] = bits[i];
    }
    engine.addFeature((uchar*) tmp , img.width() , img.height() , ASVL_PAF_RGB24_B8G8R8);
    char* filename2 = "/home/huangyc/0/1.jpg";
    QImage img2(filename2);
    uchar* bits2 =  img.bits();
    uchar* tmp2 = (uchar*) malloc(img2.byteCount()/4*3);
    int top2 = 0;
    for(int i = 0 ; i < img2.byteCount() ; i++){
        if((i+1)%4 == 0) continue;
        tmp2[top2++] = bits2[i];
    }
    engine.compareFeature(tmp2 , img2.width() , img2.height() ,ASVL_PAF_RGB24_B8G8R8 );

}
