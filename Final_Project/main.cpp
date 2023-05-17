///week12-4_keyboard_mouse�n����L�ƹ��ޱ�����
///�s�ɷ|�b�u�@����ؿ�working dir
///�bCodeblocks Project-Properties�̭���build targets�i�H�]�w
///�⥦�qDesktop\freeglut\bin�令.(�{�b�ؿ����N��)DEBUG�MRelease���n�]�w�~�|�N.cbp�ɦs��
#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"///week13 step02-1
GLMmodel * head = NULL;///week13 step02-1
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4] = {1,1,1,1};
int ID = 0;///0:�Y  1:����  2:�W���u  3:�U���u
void keyboard(unsigned char key ,int x, int y)
{
    if(key=='0') ID = 0;
    if(key=='1') ID = 1;
    if(key=='2') ID = 2;
    if(key=='3') ID = 3;
    ///if(key=='0') show[0] = !show[0];///week13 step03-1
    ///if(key=='1') show[1] = !show[1];
    ///if(key=='2') show[2] = !show[2];
    ///if(key=='3') show[3] = !show[3];
    glutPostRedisplay();
}
FILE * fout = NULL;///step02-2�@�}�l�ɮרS���},NULL
FILE * fin = NULL;
float teapotX=0, teapotY=0;
float angle=0, angle2=0, angle3=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        ///glTranslatef(teapotX,teapotY,0);
        ///glutSolidTeapot(0.3);
        glScalef(0.2, 0.2, 0.2);///week13 step02-2
        if(body==NULL)///week13 step02-1
        {
            head = glmReadOBJ("model/head.obj");
            body = glmReadOBJ("model/body.obj");///week13 step02-1
            uparmR = glmReadOBJ("model/uparmR.obj");
            lowarmR = glmReadOBJ("model/lowarmR.obj");
            ///glmUnitize(body);///week13 step02-1
        }
        if(ID==0) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[0]) glmDraw(head,GLM_MATERIAL);///week13 step03-1

        if(ID==1) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[1]) glmDraw(body,GLM_MATERIAL);
        glPushMatrix();
            glTranslatef(teapotX, teapotY, 0);

            if(ID==2) glColor3f(1,0,0);
            else glColor3f(1,1,1);
            if(show[2]) glmDraw(uparmR,GLM_MATERIAL);
        glPopMatrix();

        if(ID==3) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[3]) glmDraw(lowarmR,GLM_MATERIAL);
    glPopMatrix();
    glutSwapBuffers();
}
int oldX = 0, oldY = 0;
void motion(int x, int y)
{
    teapotX += (x - oldX)/150.0;
    teapotY -= (y - oldY)/150.0;
    oldX = x;
    oldY = y;
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
    glutPostRedisplay();
}
void mouse(int button, int state,int x, int y)
{
    if(state==GLUT_DOWN)
    {
        oldX = x;
        oldY = y;
        angle = x;
        ///if(fout==NULL) fout = fopen("file4.txt", "w");
        ///fprintf(fout, "%f %f\n", teapotX, teapotY);
    }
    display();
}
///void keyboard(unsigned char key, int x, int y)
///{
    ///if(fin==NULL)
    ///{
        ///fclose(fout);
        ///fin = fopen("file4.txt","r");
    ///}
    ///fscanf(fin, "%f %f", &teapotX, &teapotY);
    ///display();
///}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week12");

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
