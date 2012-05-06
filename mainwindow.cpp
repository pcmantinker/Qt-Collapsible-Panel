#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
{
    QHBoxLayout* layout = new QHBoxLayout;
    CollapsibleFrame* cf = new CollapsibleFrame("Test");
    CollapsibleFrame* cf2 = new CollapsibleFrame("Test2");
    cf->addWidget(cf2);
    layout->addWidget(cf);
    this->setLayout(layout);
}

MainWindow::~MainWindow()
{

}
