///week14-2_timer_play 用鍵盤播放
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
void timer(int t)///step01-1你的timer函式,做對應動作
{
    glutTimerFunc(500, timer, t+1);///設定下一個鬧鐘
    angle += 90;///增加90度
    glutPostRedisplay();///重畫畫面
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
	glutKeyboardFunc(keyboard);///step01-2用keyboard()
    ///glutTimerFunc(2000,timer,0);///step01-1設定timer函式
	glutMainLoop();
}
