///week06-3_TRT_robot_arm_hand_right_left從上週的week05-2拿來用
#include <GL/glut.h>
float angle=0;///step02-2
void drawHand()
{
    glPushMatrix();
    glScalef(1, 0.3, 0.3);
    glutSolidCube(0.5);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///step02-2²M­I´º

    glPushMatrix();
    ///要掛上去
        glTranslatef(0.25, 0, 0);///(3)要掛上去
        glRotatef(angle, 0, 0, 1);///(2)轉動
        glTranslatef(0.25, 0.5, 0);///(1)把中心放在正中心
        drawHand();///右上手臂

        glPushMatrix();
            glTranslatef(0.25, 0, 0);///(3)要掛上去
            glRotatef(angle, 0, 0, 1);///(2)轉動
            glTranslatef(0.25, 0, 0);///(1)把中心放在正中心
            drawHand();///右下手肘
        glPopMatrix();
    glPopMatrix();

   glPushMatrix();
    ///要掛上去
        glTranslatef(-0.25, 0, 0);///(3)要掛上去
        glRotatef(angle, 0, 0, 1);///(2)轉動
        glTranslatef(-0.25, 0.5, 0);///(1)把中心放在正中心
        drawHand();///上手臂

        glPushMatrix();
            glTranslatef(-0.25, 0, 0);///(3)要掛上去
            glRotatef(angle, 0, 0, 1);///(2)轉動
            glTranslatef(-0.25, 0, 0);///(1)把中心放在正中心
            drawHand();///下手肘
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
