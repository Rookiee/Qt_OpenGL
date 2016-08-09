#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGLWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);


private slots:
    void on_pushButton_clicked();
    void View_actionXZ_Plane_Slot();
    void Help_actionHelp_Slot();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
