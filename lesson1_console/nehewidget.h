#ifndef NEHEWIDGET_H
#define NEHEWIDGET_H

#include <QtOpenGL>
#include <GLUT/glut.h>

class NeheWidget : public QGLWidget
{
    Q_OBJECT
public:
    NeheWidget(QWidget *parent = 0, bool fs = false);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    bool fullScreen;
};

#endif // NEHEWIDGET_H
