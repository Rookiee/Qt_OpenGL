#ifndef NEHEWIDGET_H
#define NEHEWIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <QKeyEvent>
#ifdef Q_OS_MAC
    #include <GLUT/glut.h>
#endif
#ifdef Q_OS_WIN32
    #include <GL/glut.h>
#endif
class NeheWidget : public QGLWidget
{
//    Q_OBJECT
private:
    GLfloat xRot, yRot, zRot;
    GLfloat xSpeed, ySpeed;

    GLfloat zoom;
    GLuint textures[3];
    GLint filter;       // Indicate the texture used.
    bool lighting;      // lighting switch

    bool fullScreen;
    bool pause;

//    QPoint lastPos;     // 加了就报错

public:
    NeheWidget(QWidget *parent, bool fs = false);

public:
    void initializeGL();
    void resizeGL(GLsizei width, GLsizei height);
    void paintGL();

protected:
    void loadTexutre();
    void draw();

    void keyPressEvent(QKeyEvent *event);
//    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);  // 加了，编译通过，运行报错
    void timerEvent(QTimerEvent *event);
//    void QWheelEvent(QWheelEvent *event);


};

#endif // NEHEWIDGET_H
