#include <GL/glut.h>
float angle=0;///step02-2
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///step02-2�M�I��
    glPushMatrix();///�ƥ��x�}
        glRotatef(angle, 0, 1, 0);///step02-1����angle
        glutSolidTeapot( 0.3 );
    glPopMatrix();///�٭�x�} step01-2

    glutSwapBuffers();
    angle++;///step02-1 �⨤��++
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week04");

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
}
