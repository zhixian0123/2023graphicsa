///�⤧�e��10��{���X���ӥ�
#include<GL/glut.h>
#include "glm.h"///�U��source.zip
///glm.c���ɦW��glm.cpp��bweek10_glm�ؿ���
///��glm.cpp�[��M�׸�
GLMmodel * pmodel = NULL;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(pmodel==NULL)
    {
        pmodel = glmReadOBJ("Al.obj");
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90);
    }
    glmDraw(pmodel, GLM_MATERIAL);
    ///glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week10");

	glutDisplayFunc(display);
	glutMainLoop();
}
