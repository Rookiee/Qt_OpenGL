#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "view.h"

#include "help.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widget->show();

    connect(ui->actionXZ_Plane, SIGNAL(triggered(bool)), this, SLOT(View_actionXZ_Plane_Slot()));
    connect(ui->actionHelp, SIGNAL(triggered(bool)), this, SLOT(Help_actionHelp_Slot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    ui->widget->keyPressEvent(event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    ui->widget->mousePressEvent(event);
}



void MainWindow::on_pushButton_clicked()
{
    ui->widget->lighting = ! (ui->widget->lighting);
    if(ui->widget->lighting)
        ui->widget->EnableLighting();
    else
        ui->widget->DisableLighting();

}

void MainWindow::View_actionXZ_Plane_Slot()
{
    ui->widget->XZPlaneView();
}

void MainWindow::Help_actionHelp_Slot()
{
    Help *windowHelp = new Help();
    windowHelp->show();

}
