#include <GL/glut.h>
float X=0,Y=0;///step02-2
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///step02-2�M�I��
    glPushMatrix();///�ƥ��x�}
        glTranslatef( X, Y, 0 );///�u���o���٤��� step01-2
        glutSolidTeapot( 0.3 );
    glPopMatrix();///�٭�x�} step01-2

    glutSwapBuffers();
}
#include <stdio.h>
void mouse(int button, int state, int x, int y)
{
    X=(x-150)/150.0;///step02-2 ��@�b���@�b
    Y=-(y-150)/150.0;
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week03");

	glutDisplayFunc(display);
	glutMouseFunc(mouse);///step02-1 ��MOUSE�禡����

	glutMainLoop();
}
