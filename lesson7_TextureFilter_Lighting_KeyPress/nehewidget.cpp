#include "nehewidget.h"
#include <QImage>
#include <iostream>
#include <QDir>
#include <QString>
#include <QDebug>
GLfloat lightAmbient[4] = {0.5, 0.5, 0.5, 1.0};
GLfloat lightDiffuse[4] = {1.0, 1.0, 1.0, 1.0};
GLfloat lightPosition[4] = {0.0, 0.0, 2.0, 1.0};

NeheWidget::NeheWidget(QWidget *parent, bool fs)
    :QGLWidget(parent)
{
    xRot = yRot = zRot = 0.0;
    xSpeed = ySpeed  = 0.0;

    lighting = false;
    pause = false;
    fullScreen = fs;
    zoom = -5.0;
    resize(640, 480);
    setWindowTitle("TextureFilter-Lighting-KeyPress");
    filter = 0;
    if(fullScreen)
        showFullScreen();
    startTimer(15);

    introduction();


}

void NeheWidget::initializeGL()
{
    loadTexutre();
    glEnable(GL_TEXTURE_2D);

    glShadeModel(GL_SMOOTH);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glEnable(GL_LIGHT0);
}

void NeheWidget::resizeGL(GLsizei width, GLsizei height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (GLfloat)width/height, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    //    glLoadIdentity();
}

void NeheWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw();
}

void NeheWidget::loadTexutre()
{
    QImage tex, buf;
    QString path = QDir::currentPath();
#ifdef Q_OS_MAC
    if(!buf.load("/Users/Haoyang/Downloads/girl.png")){
#endif
#ifdef Q_OS_WIN32
    if (!buf.load("D:/11.png")){
#endif
        qWarning("Could not read Image");
//        QImage dummy(128, 128, QImage::Format_RGBX888);
//        dummy.fill(Qt::green);
//        buf = dummy;
    }
    tex = QGLWidget::convertToGLFormat(buf);

//    glGenTextures(3, textures);
//    glGenTextures(3, &textures[0]);
    glGenTextures(3, &textures[0]);

    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(), 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());

    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(), 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());

    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    /* GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST
     * 当图像在屏幕上变得很⼩小的时候,很多细节将会丢失 */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, tex.width(), tex.height(),
                       GL_RGBA, GL_UNSIGNED_BYTE, tex.bits() );
    }

    void NeheWidget::draw()
    {
        glLoadIdentity();

        glTranslatef(0, 0, zoom);
        glRotatef(xRot, 1.0, 0.0, 0.0);
        glRotatef(yRot, 0.0, 1.0, 0.0);

        glBindTexture(GL_TEXTURE_2D, textures[filter]);
        {
        glBegin( GL_QUADS );
            glNormal3f( 0.0, 0.0, 1.0 );
            glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );
            glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );
            glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0,  1.0 );
            glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0,  1.0 );
            glNormal3f( 0.0, 0.0, -1.0 );
            glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0, -1.0 );
            glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
            glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
            glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0, -1.0 );
            glNormal3f( 0.0, 1.0, 0.0 );
            glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
            glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0,  1.0,  1.0 );
            glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0,  1.0,  1.0 );
            glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
            glNormal3f( 0.0, -1.0, 0.0 );
            glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0, -1.0, -1.0 );
            glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0, -1.0, -1.0 );
            glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );
            glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );
            glNormal3f( 1.0, 0.0, 0.0 );
            glTexCoord2f( 1.0, 0.0 ); glVertex3f(  1.0, -1.0, -1.0 );
            glTexCoord2f( 1.0, 1.0 ); glVertex3f(  1.0,  1.0, -1.0 );
            glTexCoord2f( 0.0, 1.0 ); glVertex3f(  1.0,  1.0,  1.0 );
            glTexCoord2f( 0.0, 0.0 ); glVertex3f(  1.0, -1.0,  1.0 );
            glNormal3f( -1.0, 0.0, 0.0 );
            glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0, -1.0, -1.0 );
            glTexCoord2f( 1.0, 0.0 ); glVertex3f( -1.0, -1.0,  1.0 );
            glTexCoord2f( 1.0, 1.0 ); glVertex3f( -1.0,  1.0,  1.0 );
            glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0,  1.0, -1.0 );
        glEnd();
        }

        xRot += xSpeed;
        yRot += ySpeed;

    }

    void NeheWidget::keyPressEvent(QKeyEvent *event)
    {

        switch (event->key()) {
        case Qt::Key_L:
            lighting = !lighting;
            if (lighting)
                glEnable(GL_LIGHTING);
            else
                glDisable(GL_LIGHTING);
            updateGL();
            break;
        case Qt::Key_F:
            filter++;
            if(filter > 2)
                filter = 0;
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
        case Qt::Key_Left:
            xSpeed += 0.2;

            updateGL();
            break;
        case Qt::Key_Right:
            xSpeed -= 0.2;

            updateGL();
            break;
        case Qt::Key_Up:
            ySpeed += 0.2;

            updateGL();
            break;
        case Qt::Key_Down:
            ySpeed -= 0.2;

            updateGL();
            break;
        case Qt::Key_F2:
            fullScreen = !fullScreen;
            if(fullScreen)
                showFullScreen();
            else {
                showNormal();
                resize(640, 480);
            }
            updateGL();
            break;
        case Qt::Key_Space:
            xRot = yRot = zRot = 0.0;
            xSpeed = ySpeed = 0.0;

            updateGL();
            break;
        case Qt::Key_Escape:
            close();
        default:
            break;
        }
    }

    void NeheWidget::mousePressEvent(QMouseEvent *event)
    {
        lastPos = event->pos();
    }


    void NeheWidget::mouseMoveEvent(QMouseEvent *event)
    {
        GLfloat dx = ((GLfloat)event->x() - lastPos.x()) / width(); // Notice：lastPos.x()
        GLfloat dy = ((GLfloat)event->y() - lastPos.y()) / height();
//        GLfloat dz = ((GLfloat)event->x() - lastPos.x()) / 100.0;
        if(event->buttons() & Qt::LeftButton){
            yRot += 180 * dx;
            xRot += 180 * dy;

        }

        updateGL();
        lastPos = event->pos();

    }

    void NeheWidget::timerEvent(QTimerEvent *event)
    {
        //event = NULL;
        updateGL();
    }

    void NeheWidget::wheelEvent(QWheelEvent *event)
    {
        if(event->delta() > 0)
            zoom += 0.1;
        else
            zoom -= 0.1;
    }



    void NeheWidget::introduction()
    {
        using namespace std;

        cout << "Introduction: " <<endl;
        cout << "--------------------------" <<endl;
        cout << "L:     Lighting Switch" <<endl;
        cout << "F:     Filter Selection" <<endl;
        cout << "W:     Zoom In" <<endl;
        cout << "S:     Zoom Out" << endl;
        cout << "Left:  Reduce xSpeed"<<endl;
        cout << "Right: Increase xSpeed" <<endl;
        cout << "Up:    Increase ySpeed" <<endl;
        cout << "Down:  Reduce ySpeed" <<endl;
        cout << "F2:    FullScreen Switch" <<endl;
        cout << endl;
    }




