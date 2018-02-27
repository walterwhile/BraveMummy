#include <GL/glut.h>
#include <chrono>

double rotation = 0;
double size = 0.7;
std::chrono::time_point<std::chrono::system_clock> startTime;

void display()
{
  rotation = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - startTime).count()/30.0 ;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  
  glRotated(rotation, 0, 0, 1);
  glBegin(GL_TRIANGLES);
    glColor3d(1, 0, 0);  glVertex2d(-size*0.866, -size*0.5);
    glColor3d(0, 1, 0);  glVertex2d(size*0.866, -size*0.5);
    glColor3d(0, 0, 1);  glVertex2d(0, size);
  glEnd();

  glutSwapBuffers();
  glutPostRedisplay();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("glut test");
  glutDisplayFunc(display);

  startTime = std::chrono::system_clock::now();
  glutMainLoop();
  return 0;
}
