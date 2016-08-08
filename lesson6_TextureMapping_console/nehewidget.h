#ifndef NEHEWIDGET_H
#define NEHEWIDGET_H

#include <QtOpenGL>
#ifdef Q_OS_MAC
    #include <GLUT/glut.h>
#endif

#ifdef Q_OS_WIN32
    #include <GL/glut.h>
#endif


class NeheWidget : public QGLWidget
{
    Q_OBJECT
public:
    NeheWidget(QWidget *parent = 0, bool fs = false);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void loadGLTextures();

    void timerEvent(QTimerEvent * event);

private:
    bool fullScreen;

    GLfloat xRot, yRot, zRot;
    GLuint texture[1];

private:
    void drawTriangle();
    void drawSquare();
};

#endif // NEHEWIDGET_H
