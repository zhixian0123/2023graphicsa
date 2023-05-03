///week12-4_keyboard_mouse要用鍵盤滑鼠操控茶壺
///存檔會在工作執行目錄working dir
///在Codeblocks Project-Properties裡面的build targets可以設定
///把它從Desktop\freeglut\bin改成.(現在目錄的意思)DEBUG和Release都要設定才會將.cbp檔存檔
#include <stdio.h>
#include <GL/glut.h>
FILE * fout = NULL;///step02-2一開始檔案沒有開,NULL
FILE * fin = NULL;
float teapotX=0,teapotY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX,teapotY,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state,int x, int y)
{
    if(state==GLUT_DOWN)
    {
        teapotX = (x-150)/150.0;
        teapotY = (150-y)/150.0;
        if(fout==NULL) fout = fopen("file4.txt", "w");
        fprintf(fout, "%f %f\n", teapotX, teapotY);
    }
    display();
}
void keyboard(unsigned char key, int x, int y)
{
    if(fin==NULL)
    {
        fclose(fout);
        fin = fopen("file4.txt","r");
    }
    fscanf(fin, "%f %f", &teapotX, &teapotY);
    display();
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week12");

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
