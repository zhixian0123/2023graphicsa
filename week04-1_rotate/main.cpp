#include <GL/glut.h>
float angle=0;///step02-2
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///step02-2清背景
    glPushMatrix();///備份矩陣
        glRotatef(angle, 0, 1, 0);///step02-1旋轉angle
        glutSolidTeapot( 0.3 );
    glPopMatrix();///還原矩陣 step01-2

    glutSwapBuffers();
    angle++;///step02-1 把角度++
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
