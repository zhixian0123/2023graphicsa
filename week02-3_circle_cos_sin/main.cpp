///week02-3_circle_cos_sin
#include <GL/glut.h>
#include <math.h>///cos()�Msin()�n��
void myCircle(float r,float x,float y)
{
    glBegin(GL_POLYGON);///�}�l�e�h���
        for(float a = 0;a<2*3.1415926; a+=0.01)
        {
            glVertex2f(r*cos(a)+x,r*sin(a)+y);
        }
	glEnd();///����
}
void display()
{
	glColor3f(1,0,1); myCircle(0.6,0,0);///������

	glColor3f(1,0,0); myCircle(0.3,0.5,0.5);///�k�W��
	glColor3f(0,1,0); myCircle(0.3,-0.5,0.5);///���W��
	glColor3f(1,1,0); myCircle(0.3,-0.5,-0.5);///���U��
	glColor3f(0,0,1); myCircle(0.3,0.5,-0.5);///�k�U��

	glutSwapBuffers();///��GLUT��e��swap�e����ܪ��a��
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);///��GLUT�}�_��
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("GLUT Shapes"); ///�n�}����
	glutDisplayFunc(display);///�n��ܪ������禡
	glutMainLoop();///�̫��main�j�����b�̫᭱
}
