#include <GL/glut.h>
#include <windows.h>

int w = 1200, h = 800, z = -10;
int y1 = 50, z1 = -30;
float x1 = 0.2, sudut = 0;


void balok(double panjang, double lebar, double tinggi) {
    glScalef(panjang, tinggi, lebar);
    glutSolidCube(1);
}

void renderScene(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glLoadIdentity();
    glTranslatef(0,0,z);
    glRotatef(sudut, x1, y1, z1);
    glColor3f(1,0,0);

    glPushMatrix(); //matahari
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(4.0, 4.0, 0.0);
    glutSolidSphere(0.8, 80.0, 80.0);
    glPopMatrix();

    glPushMatrix();//kepala
    glTranslatef(0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.5);
    glutSolidSphere(1.0, 20.0, 20.0);
    glPopMatrix();

    glPushMatrix();//badan bawah
    glTranslatef(0.0, -1.0, 0.0);
    glColor3f(0.5, 0.5, 0.5);
    glutSolidSphere(1.0, 20.0, 20.0);
    glPopMatrix();

    glPushMatrix();//hidung
    glTranslatef(0.0, -0.3, 0.8);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCone(0.3, 1.0, 20.0, 20.0);
    glPopMatrix();

    glPushMatrix();//mata kanan
    glTranslatef(0.5, -0.1, 0.5);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.1, 20.0, 20.0);
    glPopMatrix();

    glPushMatrix(); //mata kiri
    glTranslatef(-0.5, -0.1, 0.5);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidSphere(0.1, 20.0, 20.0);
    glPopMatrix();

    glPushMatrix(); //tangan kanan
    glTranslatef(1.4, -0.8, 0.0);
    glRotatef(90.0, 1.0, -0.5, 0.0);
    glColor3f(1.0, 0.0, 0.5);
    balok(1.0, 0.3, 0.3);
    glPopMatrix();

    glPushMatrix();//tangan kiri
    glTranslatef(-1.4, -0.8, 0.0);
    glRotatef(-90.0, -1.0, -0.5, 0.0);
    glColor3f(1.0, 0.0, 0.5);
    balok(1.0, 0.3, 0.3);
    glPopMatrix();

    glPushMatrix();//kaki kiri
    glTranslatef(-0.3,-2.1,0);
    glRotatef(180, 2, 2, 0);
    glColor3f(0.0, 0.0, 1.0);
    balok(0.5, 0.3, 0.3);
    glPopMatrix();

    glPushMatrix();//kaki kanan
    glTranslatef(0.3, -2.1, 0.0);
    glRotatef(180.0, 2.0, 2.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    balok(0.5, 0.3, 0.3);
    glPopMatrix();

    glPushMatrix(); //topi
    glTranslatef(0.0, 0.5, 0.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 1.0);
    glutSolidCone(1.5 , 2.0, 80.0, 50.0);
    glPopMatrix();

    glPushMatrix();//aksesoris bola diatas topi
    glTranslatef(0.0, 2.5, 0.0);
    glColor3f(0.0, 1.0, 1.0);
    glutSolidSphere(0.2, 20.0, 20.0);
    glPopMatrix();

    sudut += 0.5;
    glutSwapBuffers();
}


void resize(int w1, int h1){
    glViewport(0,0,w1,h1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w1/ (float)h1, 1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void timer(int value){
    glutPostRedisplay();
    glutTimerFunc(15, timer, 0);
}

void KeyboardAssign(GLubyte key, GLint x, GLint y){
    switch(key){
         case 'f':
        glutFullScreen();
        glutPostRedisplay();
        break;

    case 'g':
        glutReshapeWindow(900, 600);
        glutPositionWindow(0,0);
        glutPostRedisplay();
        break;

    case 'q':
        exit(0);
    }
}


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(w, h);
    glutCreateWindow("3D Kurcaci by Muhammad Allam Ridha ");
    gluOrtho2D(-w/2, w/2, -h/2, h/2);
    glutDisplayFunc(renderScene);
    glutReshapeFunc(resize);
    glutTimerFunc(1, timer, 0);
    glutKeyboardFunc(KeyboardAssign);
    glutMainLoop();
}
