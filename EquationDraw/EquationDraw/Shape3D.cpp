#include <GL/glut.h>

// Function to draw the cube
void drawCube() {
    // Front face
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glEnd();

    // Back face
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glEnd();

    // Top face
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glEnd();

    // Bottom face
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0); // Yellow
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glEnd();

    // Right face
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0); // Magenta
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glEnd();

    // Left face
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0); // Cyan
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glEnd();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0,  // Camera position
        0.0, 0.0, 0.0,  // Look-at point
        0.0, 1.0, 0.0); // Up vector

    // Rotate cube
    static float angle = 0.0;
    glRotatef(angle, 1.0, 1.0, 1.0);

    // Draw cube
    drawCube();

    // Swap buffers and flush OpenGL commands
    glutSwapBuffers();
}

// Reshape callback function
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// Idle callback function
void idle() {
    // Rotate cube continuously
    static float angle = 0.0;
    angle += 0.5;
    if (angle > 360.0)
        angle -= 360.0;

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Cube");

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Set callbacks
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    // Start main loop
    glutMainLoop();

    return 0;
}
