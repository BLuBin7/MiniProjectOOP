#include <iostream>
#include <string>
#include <vector>
#include <GL/glut.h>

// Base class: Point
class Point {
protected:
    double x;
    double y;
    double z;

public:
    Point(double xCoord, double yCoord, double zCoord) : x(xCoord), y(yCoord), z(zCoord) {}

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getZ() const {
        return z;
    }
};

// Base class: Equation
class Equation {
public:
    virtual double evaluate(double x, double z) const = 0;
};

// Derived class: QuadraticEquation
class QuadraticEquation : public Point, public Equation {
private:
    double a;
    double b;
    double c;

public:
    QuadraticEquation(double xCoord, double yCoord, double zCoord, double coeffA, double coeffB, double coeffC)
        : Point(xCoord, yCoord, zCoord), a(coeffA), b(coeffB), c(coeffC) {}

    double evaluate(double x, double z) const override {
        return a * x * x + b * z + c;
    }
};

// Derived class: LinearEquation
class LinearEquation : public Point, public Equation {
private:
    double slope;
    double yIntercept;

public:
    LinearEquation(double xCoord, double yCoord, double zCoord, double m, double b)
        : Point(xCoord, yCoord, zCoord), slope(m), yIntercept(b) {}

    double evaluate(double x, double z) const override {
        return slope * x + yIntercept * z;
    }
};

//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0); // Set color to white
//
//    // Set up the camera
//    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//
//    // Prompt the user for the number of equations
//    int numEquations;
//    std::cout << "Enter the number of equations: ";
//    std::cin >> numEquations;
//
//    // Draw the equations
//    for (int i = 0; i < numEquations; i++) {
//        std::cout << "Equation " << i + 1 << std::endl;
//
//        // Prompt the user for the equation type
//        std::cout << "Enter the equation type (linear or quadratic): ";
//        std::string equationType;
//        std::cin >> equationType;
//
//        // Prompt the user for the equation coefficients
//        double a, b, c;
//        double m, bIntercept;
//        if (equationType == "quadratic") {
//            std::cout << "Enter the coefficients (a, b, c): ";
//            std::cin >> a >> b >> c;
//
//            QuadraticEquation quadraticEquation(0, 0, 0, a, b, c);
//
//            glBegin(GL_POINTS);
//            for (double x = -10; x <= 10; x += 0.1) {
//                for (double z = -10; z <= 10; z += 0.1) {
//                    double y = quadraticEquation.evaluate(x, z);
//                    glVertex3d(x, y, z);
//                }
//            }
//            glEnd();
//        }
//        else if (equationType == "linear") {
//            std::cout << "Enter the coefficients (m, b): ";
//            std::cin >> m >> bIntercept;
//
//            LinearEquation linearEquation(0, 0, 0, m, bIntercept);
//
//            glBegin(GL_POINTS);
//            for (double x = -10; x <= 10; x += 0.1) {
//                for (double z = -10; z <= 10; z += 0.1) {
//                    double y = linearEquation.evaluate(x, z);
//                    glVertex3d(x, y, z);
//                }
//            }
//            glEnd();
//        }
//    }
//
//    glFlush();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(400, 400);
//    glutCreateWindow("Graph Plotter");
//    gluOrtho2D(-10, 10, -10, 10);
//    glutDisplayFunc(display);
//    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D drawing
//    glutMainLoop();
//
//    return 0;
//}

