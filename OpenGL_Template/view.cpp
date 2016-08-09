#include "view.h"

GLfloat lightAmbient[4] = {0.5, 0.5, 0.5, 1.0};
GLfloat lightDiffuse[4] = {1.0, 1.0, 1.0, 1.0};
GLfloat lightPosition[4] = {2.0, 2.0, 2.0, 1.0};


View::View(QWidget *parent)
    :QGLWidget(parent)
{
    zoom = -5.0;
    xRot = yRot = zRot = 0.0;
    lighting = false;
}

void View::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glEnable(GL_LIGHT0);



}

void View::resizeGL(GLsizei width, GLsizei height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (GLfloat)width/height, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

void View::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DrawCoords();
    DrawTest();

}

void View::DrawTest()
{
    glLoadIdentity();
    glTranslatef(0, 0, zoom);

    glRotatef(xRot, 1.0, 0.0, 0.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);
    glRotatef(zRot, 0.0, 0.0, 1.0);

    glColor3f(0.3, 0.3, 0.3);
    glutSolidTeapot(1.0);




}

void View::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void View::mouseMoveEvent(QMouseEvent *event)
{
    GLfloat dx = ((GLfloat)event->x() - lastPos.x()) ;
    GLfloat dy = ((GLfloat)event->x() - lastPos.y()) ;

    if(event->buttons() & Qt::LeftButton){
        yRot += 0.05 * dx;
        xRot += 0.05 * dy;
        updateGL();
    }
    if(event->buttons() & Qt::RightButton){
        zRot += 15 * dx;
//        xRot -= 20 * dy;
        updateGL();
    }


    lastPos  = event->pos();
}

void View::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0)
        zoom += 0.1;
    else
        zoom -= 0.1;
    updateGL();
}

void View::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_L:
        lighting = !lighting;
        if (lighting)
            glEnable(GL_LIGHTING);
        else
            glDisable(GL_LIGHTING);
        updateGL();
        break;
    case Qt::Key_W:
        zoom += 0.1;
        updateGL();
        break;
    case Qt::Key_S:
        zoom -= 0.1;
        updateGL();
        break;
    case Qt::Key_A:
        yRot -= 5;
        updateGL();
        break;
    case Qt::Key_D:
        yRot += 5;
        updateGL();
        break;
    case Qt::Key_E:
        xRot -= 5;
        updateGL();
        break;
    case Qt::Key_C:
        xRot += 5;
        updateGL();
        break;
    case Qt::Key_Z:
        zRot += 5;
        updateGL();
        break;
    case Qt::Key_X:
        zRot -= 5;
        updateGL();
        break;
    case Qt::Key_Space:
        xRot = yRot = zRot = 0.0;
        zoom = -5.0;
        updateGL();
        break;
    default:
        break;
    }
}

void View::EnableLighting()
{
    glEnable(GL_LIGHTING);
    updateGL();
}
void View::DisableLighting(){
    glDisable(GL_LIGHTING);
    updateGL();
}

void View::XZPlaneView()
{
    xRot = 90.0;
    glRotated(xRot, 1.0, 1.0, 1.0);
    updateGL();
}

void View::DrawCoords()
{
    GLfloat length = 2.0;
    glLoadIdentity();
    glTranslated(0.0, 0.0, zoom);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    {
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(length, 0.0, 0.0);

        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, length, 0.0);

        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, length);
    }
    glEnd();

    glPushMatrix();
    glTranslatef(length, 0.0, 0.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glutWireCone(0.027,0.09,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, length, 0.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glutWireCone(0.027,0.09,10,10);
    glPopMatrix();
}




