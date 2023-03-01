#include <GL/glut.h>
float X=0,Y=0;///step02-2
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///step02-2清背景
    glBegin(GL_POLYGON);///開始畫多邊形
        glVertex2f(-0.236,0.108);
        glVertex2f(-0.212,0.144);
        glVertex2f(-0.032,0.180);
        glVertex2f(-0.052,0.224);
        glVertex2f(0.040,0.220);
        glVertex2f(0.028,0.172);
        glVertex2f(0.132,0.156);
        glVertex2f(0.208,0.156);
        glVertex2f(0.252,0.068);
        glVertex2f(0.288,-0.008);
        glVertex2f(0.368,0.068);
        glVertex2f(0.412,0.136);
        glVertex2f(0.480,0.132);
        glVertex2f(0.520,0.132);
        glVertex2f(0.456,0.096);
        glVertex2f(0.392,-0.028);
        glVertex2f(0.340,-0.116);
        glVertex2f(0.292,-0.128);
        glVertex2f(0.228,-0.208);
        glVertex2f(-0.216,-0.216);
        glVertex2f(-0.304,-0.140);
        glVertex2f(-0.452,0.004);
        glVertex2f(-0.452,0.064);
        glVertex2f(-0.348,0.104);
        glVertex2f(-0.244,0.104);
    glEnd();///結束
    glPushMatrix();///備份矩陣
        glTranslatef( X, Y, 0 );///只有這行還不夠 step01-2
        glutSolidTeapot( 0.3 );
    glPopMatrix();///還原矩陣 step01-2

    glutSwapBuffers();
}
#include <stdio.h>
void mouse(int button, int state, int x, int y)
{
    float X=(x-250)/250.0;///step02-2 減一半除一半
    float Y=-(y-250)/250.0;
    if(state==GLUT_DOWN)
    {
        printf("glVertex2f(%.3f,%.3f):\n",X,Y);
    }
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
	glutCreateWindow("week03");

	glutDisplayFunc(display);
	glutMouseFunc(mouse);///step02-1 請MOUSE函式幫忙

	glutMainLoop();
}
