#include "nehewidget.h"

NeheWidget::NeheWidget(QWidget *parent, bool fs)
    :QGLWidget(parent)
{
    fullScreen = fs;
}

void NeheWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);
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

    glTranslatef(0.f, 0.f, -6.f);
    glColor3f(1.f, 1.f, 1.f);
    glBegin(GL_TRIANGLES);
        glVertex3f(0.f, 1.f, 0.f);
        glVertex3f(1.f, -1.f, 0.f);
        glVertex3f(-1.f, -1.f, 0.f);
    glEnd();
}
