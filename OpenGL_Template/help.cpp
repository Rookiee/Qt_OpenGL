#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    ui->keysLabel->clear();
    if(ui->keysTab->isEnabled()){
        setWindowTitle( "Help -- Keys");
    }

    keyContent = "L:    Lighting Control\n"
                 "W:    Zoom In\n"
                 "S:    Zoom Out\n"
                 "A:    Rotate Toward Left Around Y\n"
                 "D:    Rotate Toward Right Around Y\n"
                 "E:    Rotate Toward Up Around X\n"
                 "C:    Rotate Toward Down Around X\n"
                 "Z:    Rotate Toward Left Around Z\n"
                 "X:    Rotate Toward Right Around Z\n";
    ui->keysLabel->setText(keyContent);
}

Help::~Help()
{
    delete ui;
}
