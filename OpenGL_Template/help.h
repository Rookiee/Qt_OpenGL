#ifndef HELP_H
#define HELP_H

#include <QWidget>

namespace Ui {
class Help;
}

class Help : public QWidget
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = 0);
    ~Help();

private:
    Ui::Help *ui;
    QString keyContent;
};

#endif // HELP_H
