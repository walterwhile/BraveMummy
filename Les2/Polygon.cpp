#include <GL/glut.h>

double size = 0.7;

GLvoid DrawGLScene(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

  	glBegin(GL_TRIANGLES);
		glVertex2d(-size*0.866, -size*0.5);
		glVertex2d(size*0.866, -size*0.5);
		glVertex2d(0, size);
	glEnd();

	glutSwapBuffers();
	glutPostRedisplay(); 
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv); // GLUT inicialization
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // settings
  glutCreateWindow("Les3.Polygon"); // creation of window

  glutDisplayFunc(DrawGLScene);

  glutMainLoop(); // giving control to GLUT

  return 0;
}

