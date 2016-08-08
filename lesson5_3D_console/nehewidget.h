#ifndef NEHEWIDGET_H
#define NEHEWIDGET_H

#include <QtOpenGL>
//#include <GLUT/glut.h>
#include <glu.h>

class NeheWidget : public QGLWidget
{
    Q_OBJECT
public:
    NeheWidget(QWidget *parent = 0, bool fs = false);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void timerEvent(QTimerEvent * event);

private:
    bool fullScreen;

    GLfloat rTri;   // control the rotation of triangle
    GLfloat rQuad;   // control the degree of rotation of square

private:
    void drawTriangle();
    void drawSquare();
};

#endif // NEHEWIDGET_H
