#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "collapsibleframe.h"

class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

};

#endif // MAINWINDOW_H
