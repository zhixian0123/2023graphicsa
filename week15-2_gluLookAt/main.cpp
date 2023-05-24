///week15-2_gluLookAt
///�禡reshape(), display()
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void reshape(int w,int h)
{
    glViewport(0, 0, w, h);///�����̷|�ݨ쪺2D�d��

    float ar= w / (float) h;///aspect ratio���e��

    glMatrixMode(GL_PROJECTION);///��������projection�x�}
    glLoadIdentity();///�x�}�M��,�������x�}(�̤@�}�l���x�})
    gluPerspective(60, ar, 0.01, 1000);

    glMatrixMode(GL_MODELVIEW);///���n�ᰨ�W���^modelview�x�}
    glLoadIdentity();///�x�}�M��,�������x�}(�̤@�}�l���x�})
    gluLookAt(0,0,1, 0,0,0, 0,1,0);
    ///�b0,0,1 �ݵۯ���0,0,0, up�O0,1,0

    glutPostRedisplay();
}
float eyeX = 0, eyeY = 0;
void motion(int x,int y)
{
    eyeX=(x-150.0)/150.0;
    eyeY=(150.0-y)/150.0;
    glMatrixMode(GL_MODELVIEW);///���n�ᰨ�W���^modelview�x�}
    glLoadIdentity();///�x�}�M��,�������x�}(�̤@�}�l���x�})
    gluLookAt(eyeX, eyeY, 1, 0,0,0, 0,1,0);
    glutPostRedisplay();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week15");

	glutMotionFunc(motion);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);///�W����reshape
	glutMainLoop();
}
