#include <GL/glut.h>
float X=0,Y=0;///step02-2
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///step02-2清背景
    glPushMatrix();///備份矩陣
        glTranslatef( X, Y, 0 );///只有這行還不夠 step01-2
        glutSolidTeapot( 0.3 );
    glPopMatrix();///還原矩陣 step01-2

    glutSwapBuffers();
}
#include <stdio.h>
void mouse(int button, int state, int x, int y)
{
    X=(x-150)/150.0;///step02-2 減一半除一半
    Y=-(y-150)/150.0;
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week03");

	glutDisplayFunc(display);
	glutMouseFunc(mouse);///step02-1 請MOUSE函式幫忙

	glutMainLoop();
}
