///week14-2_timer_play ����L����
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
void timer(int t)///step01-1�A��timer�禡,�������ʧ@
{
    glutTimerFunc(500, timer, t+1);///�]�w�U�@�Ӿx��
    angle += 90;///�W�[90��
    glutPostRedisplay();///���e�e��
}
void keyboard(unsigned char key, int x, int y)
{
    glutTimerFunc(0, timer, 0);
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week14");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);///step01-2��keyboard()
    ///glutTimerFunc(2000,timer,0);///step01-1�]�wtimer�禡
	glutMainLoop();
}
