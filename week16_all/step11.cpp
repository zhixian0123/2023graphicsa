#include <stdio.h>
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
GLMmodel * arm1 = NULL, * arm2 = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float teapotX=0, teapotY=0, angle=0, angle2=0, oldX=0, oldY=0;  ///�����P
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX += (x - oldX)/10.0; ///�����P
    teapotY += (oldY - y)/10.0; ///�����P
    angle += x - oldX;
    angle2 += y - oldY; ///�����P
    oldX = x;
    oldY = y; ///�����P
    printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(2,2,2);
        glTranslatef(0, -0.4, 0);
        glPushMatrix();
            glColor3f(1,1,1);///glColor3f(1,0,0);
            glScalef(0.03, 0.03, 0.03);
            ///glRotatef(angle, 0, 1, 0);
            glmDraw(body, GLM_MATERIAL | GLM_TEXTURE); ///glmDraw(gundam, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();
                glTranslatef(0.000 , +22.300 , 0 );
                //glRotatef(angle, 0, 1, 0);
                //glRotatef(angle2, 1, 0, 0);
                glTranslatef(0.000 , -22.300 , 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-3.800 , +21.200 , 0 );
                glRotatef(angle, 0, 1, 0);
                glRotatef(angle2, 1, 0, 0);
                glTranslatef(3.800 , -21.200 , 0 );
                ///glTranslatef(teapotX, teapotY, 0);
                glmDraw(arm1, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

        glPopMatrix();
        glColor3f(0,1,0);///�����I����m
        glutSolidTeapot( 0.01 );///�����I����m
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/gundam.obj");
    arm1 = glmReadOBJ("model/arm1.obj");
    arm2 = glmReadOBJ("model/arm1.obj");
    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
