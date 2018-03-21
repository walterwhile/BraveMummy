#include <GL/glut.h>

double size = 0.7;

GLvoid display(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        glTranslatef(-1.5f,0.0f,-6.0f);

        glBegin(GL_TRIANGLES);
		glColor3f(1.0f,0.0f,0.0f);      // Красный цвет
                glVertex3f( 0.0f, 1.0f, 0.0f);
		glColor3f(0.0f,1.0f,0.0f);      // Зеленный цвет
                glVertex3f(-1.0f,-1.0f, 0.0f);
		glColor3f(0.0f,0.0f,1.0f);      // Синий цвет
                glVertex3f( 1.0f,-1.0f, 0.0f);
        glEnd();

        glTranslatef(3.0f,0.0f,0.0f);

	glColor3f(0.5f,0.5f,1.0f);      // Установим синий цвет только один раз
        glBegin(GL_QUADS);
                glVertex3f(-1.0f, 1.0f, 0.0f);
                glVertex3f( 1.0f, 1.0f, 0.0f);
                glVertex3f( 1.0f,-1.0f, 0.0f);
                glVertex3f(-1.0f,-1.0f, 0.0f);
        glEnd();

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv); // GLUT inicialization

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // settings

	glutInitWindowSize(512, 512);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("glut"); // creation of window

	glutDisplayFunc(display);

	glutMainLoop(); // giving control to GLUT

	return 0;
}

