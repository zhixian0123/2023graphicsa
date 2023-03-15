///week05-2程式來自week05-1
///畫出大身體、手臂
#include <GL/glut.h>
float angle=0;///step02-2
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///step02-2²M­I´º

    glColor3f(0, 1, 0);
    glPushMatrix();
        glutSolidCube(0.5);

    glPushMatrix();
        glTranslatef(0.25, 0.25, 0);///(3)掛在右上角
        glRotatef(angle, 0, 0, 1);///(2)轉動
        glTranslatef(0.25, 0.25, 0);///(1)把旋轉中心放到中心
        ///glTranslatef(0.5, 0.5, 0);///step03-3先註解掉
        glColor3f(1, 0, 0);///紅色的手臂
        glutSolidCube(0.5);

    glPopMatrix();

    glutSwapBuffers();
    angle++;
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
