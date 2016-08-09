#ifndef VIEW_H
#define VIEW_H

#include <QtOpenGL>
/* for mac */
#ifdef Q_OS_MAC
    #include <GLUT/glut.h>
#endif
/* for windows */
#ifdef Q_OS_WIN32
    #include <GL/glut.h>
#endif

#include <QPoint>
#include <QMouseEvent>
#include <QWheelEvent>


class View : public QGLWidget
{
    Q_OBJECT
public:
    View(QWidget *parent);

public:
    void initializeGL();
    void resizeGL(GLsizei width, GLsizei height);
    void paintGL();


public:
    GLfloat zoom;
    GLfloat xRot, yRot, zRot;
    bool lighting;


public:

    QPoint lastPos;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);

public:
    void EnableLighting();
    void DisableLighting();
    void XZPlaneView();


private:
    void DrawCoords();
    void DrawTest();



};

#endif // VIEW_H
