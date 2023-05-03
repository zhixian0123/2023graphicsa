///week12-4_keyboard_mouse�n����L�ƹ��ޱ�����
///�s�ɷ|�b�u�@����ؿ�working dir
///�bCodeblocks Project-Properties�̭���build targets�i�H�]�w
///�⥦�qDesktop\freeglut\bin�令.(�{�b�ؿ����N��)DEBUG�MRelease���n�]�w�~�|�N.cbp�ɦs��
#include <stdio.h>
#include <GL/glut.h>
FILE * fout = NULL;///step02-2�@�}�l�ɮרS���},NULL
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
