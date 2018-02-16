#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <bits/stdc++.h>
#include "arcfaceengine.h"
#include "inc/asvloffscreen.h"
#include "bmp.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected slots:
    int onStartBtnClicked();
    int onStopBtnClicked();
    int onWorkBtnClick();
private:
    Ui::MainWindow *ui;
    ARCFaceEngine engine;
};

#endif // MAINWINDOW_H
