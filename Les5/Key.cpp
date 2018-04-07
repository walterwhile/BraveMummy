#include <GL/glut.h>
#include <chrono>

double rotation = 0;
double size = 100;
std::chrono::time_point<std::chrono::system_clock> startTime;

void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27)
		exit(0);
}

void resize(int width, int height){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-width/2.0, width/2.0, -height/2.0, height/2.0, 10, 100);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	rotation = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count()/30.0 ;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // Очистка экрана и буфера глубины
	glLoadIdentity();  
	glTranslatef(0.0f, 0.0f, -15.0f);
	glPushMatrix();
		glTranslatef(-1.5f*size, 0.0f, 0.0f);
		glRotated(rotation, 0, 0, 1);

		glBegin(GL_TRIANGLES);
			glColor3f(1.0f,0.0f,0.0f);      // Красный цвет
		        glVertex3f( 0.0f, size, 0.0f);
			glColor3f(0.0f,1.0f,0.0f);      // Зеленный цвет
		        glVertex3f(-size,-size, 0.0f);
			glColor3f(0.0f,0.0f,1.0f);      // Синий цвет
		        glVertex3f( size,-size, 0.0f);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.5f*size,0.0f,0.0f);
		glRotated(rotation, 0, 0, 1);

		glColor3f(0.5f,0.5f,1.0f);      // Установим синий цвет только один раз
		glBegin(GL_QUADS);
		        glVertex3f(-size, size, 0.0f);
		        glVertex3f( size, size, 0.0f);
		        glVertex3f( size,-size, 0.0f);
		        glVertex3f(-size,-size, 0.0f);
		glEnd();
	glPopMatrix();

	glutSwapBuffers();
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv); // GLUT inicialization

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // settings

	glutInitWindowSize(512, 512);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("glut"); // creation of window

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	resize(512, 512);
	startTime = std::chrono::system_clock::now();
	glutKeyboardFunc(processNormalKeys);

	glutMainLoop(); // giving control to GLUT

	return 0;
}

