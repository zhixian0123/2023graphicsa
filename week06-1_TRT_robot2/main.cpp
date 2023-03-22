///貼上上週的week05-2_TRT_robot
#include <GL/glut.h>
float angle=0;///step02-2
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///step02-2²M­I´º
    glutSolidSphere(0.02, 30, 30);///正中心的圓球

    glPushMatrix();

    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glTranslatef(0.46, 0.05, 0);///(1)把旋轉中心放到中心
        ///glTranslatef(0.5, 0.5, 0);///step03-3先註解掉
        glutSolidTeapot(0.3);

    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week06");

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
}
