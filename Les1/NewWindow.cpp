#include <GL/glut.h>

void display()
{
  glClear(GL_COLOR_BUFFER_BIT); // cleaning of frame buffer
  glutSwapBuffers(); // change background buffer and frame buffer 
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv); // GLUT inicialization

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // settings

  glutInitWindowSize(1024, 1024);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Les1.Window"); // creation of window

  glutDisplayFunc(display);

  glutMainLoop(); // giving control to GLUT

  return 0;
}

