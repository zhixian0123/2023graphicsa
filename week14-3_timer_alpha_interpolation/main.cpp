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
void timer(int t)///step01-1你的timer函式,做對應動作
{
    if(t<100) glutTimerFunc(500, timer, t+1);///設定下一個鬧鐘
    float alpha = t/100.0;///step02-1 alpha介於0.00~1.00之間
    angle = newAngle * alpha + (1-alpha) * oldAngle;///step02-1 alpha內插公式
    glutPostRedisplay();///重畫畫面
}
void motion(int x,int y)///step02-1
{
    angle = x;///step02-1即時更新角度
    glutPostRedisplay();///step02-1重畫畫面
}
void mouse(int button, int state, int x, int y)///step02-1
{
    if(state==GLUT_DOWN) oldAngle = x;///step02-1按下去
    if(state==GLUT_UP) newAngle = x;///step02-1放開
    glutPostRedisplay();///step02-1重畫畫面
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
	glutMouseFunc(mouse);///step02-1按滑鼠右鍵表示起點,放開表示終點
	glutMotionFunc(motion);///step02-1當mouse在motion時,即時更新畫面
	glutKeyboardFunc(keyboard);///step01-2用keyboard()

	glutMainLoop();
}
