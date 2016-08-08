#include "nehewidget.h"

NeheWidget::NeheWidget(QWidget *parent, bool fs)
    :QGLWidget(parent)
{
    fullScreen = fs;
}

void NeheWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);
//    glShadeModel(GL_FLAT);
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glEnable(GL_DEPTH_TEST);
}

void NeheWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w/(GLfloat)h, 0.1f, 100.f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void NeheWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawTriangle();
    drawSquare();

}

void NeheWidget::drawTriangle()
{
    glLoadIdentity();
    glTranslatef(-1.5f, 0.f, -6.f);

    glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(0.f, 1.f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(1.f, -1.f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(-1.f, -1.f, 0.f);
        glEnd();
}

void NeheWidget::drawSquare()
{
    glLoadIdentity();
    glTranslatef(1.5, 0.0, -6.f);

    // 会为蓝色，因为在paintGL()中，先调用了drawTriangle(), 最后一个顶点用的深蓝色，之后为做改动，
    // 所以，这里仍为蓝色.
    glBegin( GL_QUADS );
        glVertex3f( -1.0,  1.0,  0.0 );
        glVertex3f(  1.0,  1.0,  0.0 );
        glVertex3f(  1.0, -1.0,  0.0 );
        glVertex3f( -1.0, -1.0,  0.0 );
    glEnd();
}
