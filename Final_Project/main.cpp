///week12-4_keyboard_mouse要用鍵盤滑鼠操控茶壺
///存檔會在工作執行目錄working dir
///在Codeblocks Project-Properties裡面的build targets可以設定
///把它從Desktop\freeglut\bin改成.(現在目錄的意思)DEBUG和Release都要設定才會將.cbp檔存檔
///week15切換不同的關節改變不同的角度
///int angle[20];
///motion()時,用angle[ID]來改
#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"///week13 step02-1
GLMmodel * head = NULL;///week13 step02-1
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4] = {1,1,1,1};
int ID = 3;///0:頭  1:身體  2:上手臂  3:下手臂
FILE * fout = NULL;
FILE * fin = NULL;
float teapotX, teapotY=0;
float angle[20] = {};
void keyboard(unsigned char key ,int x, int y)
{
    if(key=='0') ID = 0;
    if(key=='1') ID = 1;
    if(key=='2') ID = 2;
    if(key=='3') ID = 3;
    if(key=='s')
    {
        if(fout==NULL) fout = fopen("motion.txt","w");
        for(int i=0;i<20;i++)///week15_step03-2
        {
            fprintf(fout, "%.2f ", angle[i]);///week15_step03-2
        }
        fprintf(fout,"\n");
    }
    else if(key=='r')
    {
        if(fin==NULL) fin = fopen("motion.txt","r");
        for(int i=0;i<20;i++)
        {
            fscanf(fin, "%f", &angle[i]);
        }
        glutPostRedisplay();
    }
    ///if(key=='0') show[0] = !show[0];///week13 step03-1
    ///if(key=='1') show[1] = !show[1];
    ///if(key=='2') show[2] = !show[2];
    ///if(key=='3') show[3] = !show[3];
    glutPostRedisplay();
}

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
            glTranslatef(-1.200000, +0.453333, 0);
            glRotatef(angle[2],0,0,1);///week15_step03-1改用陣列
            glTranslatef(1.200000,-0.453333,0);

            if(ID==2) glColor3f(1,0,0);
            else glColor3f(1,1,1);
            if(show[2]) glmDraw(uparmR,GLM_MATERIAL);

            glPushMatrix();
                glTranslatef(-2.026665, -0.026667, 0);
                glRotatef(angle[3],0,0,1);
                glTranslatef(2.026665, 0.026667, 0);
                //glTranslatef(teapotX, teapotY, 0);

                if(ID==3) glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[3]) glmDraw(lowarmR,GLM_MATERIAL);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glColor3f(0,1,0);
    glutSolidTeapot(0.02);
    glutSwapBuffers();
}
int oldX = 0, oldY = 0;
void motion(int x, int y)
{
    teapotX += (x - oldX)/150.0;
    teapotY -= (y - oldY)/150.0;
    angle[ID] +=(x-oldX);
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
        ///angle = x;
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
