#include "nehewidget.h"

NeheWidget::NeheWidget(QWidget *parent, bool fs)
    :QGLWidget(parent)
{
    fullScreen = fs;

    tRot = 10.0;
    qRot = 10.0;
}

void NeheWidget::initializeGL()
{
//    glShadeModel(GL_SMOOTH);
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


    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
      glLoadIdentity();
      glTranslatef( -1.5,  0.0, -6.0 );
      glRotatef( tRot,  0.0,  1.0,  0.0 );

      glBegin( GL_TRIANGLES );
        glColor3f( 1.0, 0.0, 0.0 );
        glVertex3f(  0.0,  1.0,  0.0 );
        glColor3f( 0.0, 1.0, 0.0 );
        glVertex3f( -1.0, -1.0,  0.0 );
        glColor3f( 0.0, 0.0, 1.0 );
        glVertex3f(  1.0, -1.0,  0.0 );
      glEnd();

      glLoadIdentity();
      glTranslatef(  1.5,  0.0, -6.0 );
      glRotatef( qRot,  0.0,  1.0,  0.0 );

      glColor3f( 0.5, 0.5, 1.0 );
      glBegin( GL_QUADS );
        glVertex3f( -1.0,  1.0,  0.0 );
        glVertex3f(  1.0,  1.0,  0.0 );
        glVertex3f(  1.0, -1.0,  0.0 );
        glVertex3f( -1.0, -1.0,  0.0 );
      glEnd();

      tRot += 2;
      qRot -= 1;


}

void NeheWidget::drawTriangle()
{
    glLoadIdentity();

    glTranslatef(-1.5f, 0.f, -6.f);
glRotatef(45, 1.0, 0.0, 0.0);


    glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(0.f, 1.f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(1.f, -1.f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(-1.f, -1.f, 0.f);
    glEnd();
    tRot += 1;

}

void NeheWidget::drawSquare()
{
    glLoadIdentity();
    glTranslatef(1.5, 0.0, -6.f);


    glBegin( GL_QUADS );
        glVertex3f( -1.0,  1.0,  0.0 );
        glVertex3f(  1.0,  1.0,  0.0 );
        glVertex3f(  1.0, -1.0,  0.0 );
        glVertex3f( -1.0, -1.0,  0.0 );
    glEnd();
}
