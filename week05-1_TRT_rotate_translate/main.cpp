#include <GL/glut.h>
float angle=0;///step02-2
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///step02-2²M­I´º

    glColor3f(0, 1, 0);
    glPushMatrix();///³Æ¥÷¯x°}
        glTranslatef(0.8, 0, 0);///最後是綠色的移動
        glRotatef(angle, 0, 0, 1);///改對z軸轉
        glutSolidTeapot( 0.3 );
    glPopMatrix();///ÁÙ­ì¯x°} step01-2

    glColor3f(1, 0, 0);
    glPushMatrix();///³Æ¥÷¯x°}
        glRotatef(angle, 0, 0, 1);///step02-1±ÛÂàangle
        glTranslatef(0.8, 0, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();///ÁÙ­ì¯x°} step01-2


    glutSwapBuffers();
    angle++;///step02-1 §â¨¤«×++
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
