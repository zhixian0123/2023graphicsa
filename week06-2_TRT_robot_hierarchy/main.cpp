///week06-2_TRT_robot_hierarchy改自week06-1
#include <GL/glut.h>
float angle=0;///step02-2
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///step02-2²M­I´º
    ///glutSolidSphere(0.02, 30, 30);///正中心的圓球

    glutSolidTeapot(0.3);///step02-1身體

    glPushMatrix();
    ///step02-1先註解掉///glTranslatef
        glTranslatef(0.5, 0.13, 0);///step02-2新的
        glRotatef(angle, 0, 0, 1);///(2)就可以轉動
        glTranslatef(0.46, -0.05, 0);///(1)把旋轉中心放到中心
        glutSolidTeapot(0.3);

        glPushMatrix();
    ///step02-1先註解掉///glTranslatef
            glTranslatef(0.5, 0.13, 0);///step02-2新的
            glRotatef(angle, 0, 0, 1);///(2)就可以轉動
            glTranslatef(0.46, -0.05, 0);///(1)把旋轉中心放到中心
            glutSolidTeapot(0.3);
        glPopMatrix();

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
