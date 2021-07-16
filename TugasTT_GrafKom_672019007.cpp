#include <iostream>
#include <vector>
#include <stdlib.h>
#include <GL/glut.h>
#include "imageloader.h"
//Radithya Airlangga-672019007
//Tugas Texturing dan Transformasi
//Grafika Komputer A
bool movement = false;
float xdiff = 0.0f;
float ydiff = 0.0f;
float xrot = 0.0f;
float yrot = 0.0f;
float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;
float sizes = 1.0f;
bool mouseDown = false;
GLuint _textureBrick, _textureDoor, _textureGrass, _textureRoof, _textureWindow, _textureSky;
static void resize(int width, int height){
    const float ar = (float)width / (float)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, _textureBrick);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTranslatef(0, 0, -6);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glTranslatef(xmov, ymov, zmov);
    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 2.0, 0);  glVertex3f(-2.2, -0.1, -1.25);
    glTexCoord3f(4.0, 2.0, 0);  glVertex3f(2.2, -0.1, -1.25);
    glTexCoord3f(4.0, 0.0, 0);  glVertex3f(2.2, -0.1, 1.25);
    glTexCoord3f(0.0, 0.0, 0);  glVertex3f(-2.2, -0.1, 1.25);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, _textureRoof);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 2.0, 0); glVertex3f(-2.2, 0.5, 0);
    glTexCoord3f(4.0, 2.0, 0); glVertex3f(2.2, 0.5, 0);
    glTexCoord3f(4.0, 0.0, 1.25); glVertex3f(2.2, -0.1, 1.25);
    glTexCoord3f(0.0, 0.0, 1.25); glVertex3f(-2.2, -0.1, 1.25);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureBrick);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTranslatef(0, 0, -6);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glTranslatef(xmov, ymov, zmov);
    glBindTexture(GL_TEXTURE_2D, _textureGrass);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);
    glTexCoord3f(0.0, 2.0, 0); glVertex3f(-2.2, 0.5, 0);
    glTexCoord3f(4.0, 2.0, 0); glVertex3f(2.2, 0.5, 0);
    glTexCoord3f(4.0, 0.0, -1.25); glVertex3f(2.2, -0.1, -1.25);
    glTexCoord3f(0.0, 0.0, -1.25); glVertex3f(-2.2, -0.1, -1.25);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, _textureDoor);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTranslatef(0, 0, -6);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glTranslatef(xmov, ymov, zmov);
    glBegin(GL_TRIANGLES);
    glTexCoord3f(0.0, 1.0, 0); glVertex3f(2.2, 0.5, 0);
    glTexCoord3f(1.0, 0.0, 1); glVertex3f(2.2, -0.1, 1.25);
    glTexCoord3f(-1.0, 0.0, -1); glVertex3f(2.2, -0.1, -1.25);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, _textureSky);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTranslatef(0, 0, -6);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glTranslatef(xmov, ymov, zmov);
    glBegin(GL_TRIANGLES);
    glTexCoord3f(0.0, 1.0, 0);    glVertex3f(-2.2, 0.5, 0);
    glTexCoord3f(1.0, 0.0, 1);    glVertex3f(-2.2, -0.1, 1.25);
    glTexCoord3f(-1.0, 0.0, -1);    glVertex3f(-2.2, -0.1, -1.25);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}
void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}
void keyboard(unsigned char key, int x, int y) { //Melakukan Fungsi Keyboard
    switch (key) {
    case 'q':
    case 'Q': //zoom in
        zmov += 0.2f;
        break;
    case 'e':
    case 'E'://zoom out
        zmov -= 0.2f;
        break;
    case 't':
    case 'T': //zoom in
        zmov += 0.4f;
        break;
    case 'y':
    case 'Y'://zoom out
        zmov -= 0.4f;
        break;
    case 'u':
    case 'U': //zoom in
        zmov += 0.3f;
        break;
    case 'i':
    case 'I'://zoom out
        zmov -= 0.3f;
        break;
    case 'o':
    case 'O': //zoom in
        zmov += 0.1f;
        break;
    case 'p':
    case 'P'://zoom out
        zmov -= 0.1f;
        break;
    case 'a':
    case 'A'://putar kanan
        yrot -= 5.0f;
        break;
    case 'd':
    case 'D'://putar kiri
        yrot += 5.0f;
        break;
    case 'f':
    case 'F'://putar kanan
        yrot -= 3.0f;
        break;
    case 'g':
    case 'G'://putar kiri
        yrot += 3.0f;
        break;
    case 'h':
    case 'H'://putar kanan
        yrot -= 2.0f;
        break;
    case 'j':
    case 'J'://putar kiri
        yrot += 2.0f;
        break;
    case 'k':
    case 'K'://putar kanan
        yrot -= 1.0f;
        break;
    case 'l':
    case 'L'://putar kiri
        yrot += 1.0f;
        break;
    case 's':
    case 'S'://ke atas
        xrot += 5.0f;
        break;
    case 'w':
    case 'W'://kebawah
        xrot -= 4.0f;
        break;
    case 'z':
    case 'Z'://ke atas
        xrot += 4.0f;
        break;
    case 'x':
    case 'X'://kebawah
        xrot -= 3.0f;
        break;
    case 'c':
    case 'C'://ke atas
        xrot += 3.0f;
        break;
    case 'v':
    case 'V'://kebawah
        xrot -= 2.0f;
        break;
    case 'b':
    case 'B'://ke atas
        xrot += 2.0f;
        break;
    case 'n':
    case 'N'://kebawah
        xrot -= 1.0f;
        break;
    case 'm':
    case 'M'://ke atas
        xrot += 1.0f;
        break;
    case 'r':
    case 'R'://animasi berputar
        zmov += 1.0f;
        break;
    }
    glutPostRedisplay();
}
void mySpecialFunc(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_RIGHT:
        xmov += 1;
        if (xmov > 360) xmov = 0.0;
        break;
    case GLUT_KEY_LEFT:
        xmov -= 1;
        if (xmov > 360) xmov = 0.0;
        break;
    case GLUT_KEY_UP:
        ymov += 1;
        if (ymov > 360) ymov = 0.0;
        break;
    case GLUT_KEY_DOWN:
        ymov -= 1;
        if (ymov > 360) ymov = 0.0;
        break;
    }
    glutPostRedisplay();
}
GLuint loadTexture(Image* image) {
    GLuint textureId;
    glGenTextures(1, &textureId); 
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height,0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    return textureId; 
}
void Initialize() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    Image* image = loadBMP("C:/Users/LENOVO/source/repos/TugasTexturingTransformasi_GrafKom_672019007/TugasTexturingTransformasi_GrafKom_672019007/bricks.bmp");
    _textureBrick = loadTexture(image);
    image = loadBMP("C:/Users/LENOVO/source/repos/TugasTexturingTransformasi_GrafKom_672019007/TugasTexturingTransformasi_GrafKom_672019007/door.bmp");
    _textureDoor = loadTexture(image);
    image = loadBMP("C:/Users/LENOVO/source/repos/TugasTexturingTransformasi_GrafKom_672019007/TugasTexturingTransformasi_GrafKom_672019007/grass.bmp");
    _textureGrass = loadTexture(image);
    image = loadBMP("C:/Users/LENOVO/source/repos/TugasTexturingTransformasi_GrafKom_672019007/TugasTexturingTransformasi_GrafKom_672019007/roof.bmp");
    _textureRoof = loadTexture(image);
    image = loadBMP("C:/Users/LENOVO/source/repos/TugasTexturingTransformasi_GrafKom_672019007/TugasTexturingTransformasi_GrafKom_672019007/window.bmp");
    _textureWindow = loadTexture(image);
    image = loadBMP("C:/Users/LENOVO/source/repos/TugasTexturingTransformasi_GrafKom_672019007/TugasTexturingTransformasi_GrafKom_672019007/sky.bmp");
    _textureSky = loadTexture(image);
    delete image;
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Tugas TT-Radithya Airlangga-672019007");
    glEnable(GL_DEPTH_TEST);

    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(mySpecialFunc);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutDisplayFunc(renderScene);
    Initialize();

    glutMainLoop();
    return 0;
}
