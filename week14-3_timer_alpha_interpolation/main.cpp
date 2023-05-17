///week14-3_timer_alpha_interpolation
#include <GL/glut.h>
float angle=0, oldAngle=0, newAngle=0;
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
    if(t<100) glutTimerFunc(500, timer, t+1);///�]�w�U�@�Ӿx��
    float alpha = t/100.0;///step02-1 alpha����0.00~1.00����
    angle = newAngle * alpha + (1-alpha) * oldAngle;///step02-1 alpha��������
    glutPostRedisplay();///���e�e��
}
void motion(int x,int y)///step02-1
{
    angle = x;///step02-1�Y�ɧ�s����
    glutPostRedisplay();///step02-1���e�e��
}
void mouse(int button, int state, int x, int y)///step02-1
{
    if(state==GLUT_DOWN) oldAngle = x;///step02-1���U�h
    if(state==GLUT_UP) newAngle = x;///step02-1��}
    glutPostRedisplay();///step02-1���e�e��
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
	glutMouseFunc(mouse);///step02-1���ƹ��k���ܰ_�I,��}��ܲ��I
	glutMotionFunc(motion);///step02-1��mouse�bmotion��,�Y�ɧ�s�e��
	glutKeyboardFunc(keyboard);///step01-2��keyboard()

	glutMainLoop();
}
