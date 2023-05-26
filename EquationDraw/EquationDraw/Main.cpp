#include <iostream>
#include <string>
#include <vector>
#include <GL/glut.h>

// Base class: Point
class Point {
protected:
    double x;
    double y;

public:
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }
};

// Base class: Equation
class Equation {
public:
    virtual double evaluate(double x) const = 0;
};

// Derived class: QuadraticEquation
class QuadraticEquation : public Point, public Equation {
private:
    double a;
    double b;
    double c;

public:
    QuadraticEquation(double xCoord, double yCoord, double coeffA, double coeffB, double coeffC)
        : Point(xCoord, yCoord), a(coeffA), b(coeffB), c(coeffC) {}

    double evaluate(double x) const override {
        return a * x * x + b * x + c;
    }
};

// Derived class: LinearEquation
class LinearEquation : public Point, public Equation {
private:
    double slope;
    double yIntercept;

public:
    LinearEquation(double xCoord, double yCoord, double m, double b)
        : Point(xCoord, yCoord), slope(m), yIntercept(b) {}

    double evaluate(double x) const override {
        return slope * x + yIntercept;
    }
};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white

    // Draw x-axis
    glBegin(GL_LINES);
    glVertex2d(-10, 0);
    glVertex2d(10, 0);
    glEnd();

    // Draw y-axis
    glBegin(GL_LINES);
    glVertex2d(0, -10);
    glVertex2d(0, 10);
    glEnd();

    // Prompt the user to enter an equation
    std::cout << "Enter an equation (linear or quadratic): ";
    std::string equation;
    std::getline(std::cin, equation);
    double xMin = -10.0;
    double xMax = 10.0;
    double step = 0.1;

    if (equation.find("x^2") != std::string::npos) {
        // Quadratic equation
        double a, b, c;
        std::cout << "Enter the coefficients (a, b, c): ";
        std::cin >> a >> b >> c;
        QuadraticEquation quadraticEquation(xMin, a * xMin * xMin + b * xMin + c, a, b, c);

        glBegin(GL_POINTS);
        for (double x = xMin; x <= xMax; x += step) {
            double y = quadraticEquation.evaluate(x);
            glVertex2d(x, y);
        }
        glEnd();
    }
    else {
        // Linear equation
        double m, b;
        std::cout << "Enter the coefficients (m, b): ";
        std::cin >> m >> b;
        LinearEquation linearEquation(xMin, m * xMin + b, m, b);

        glBegin(GL_POINTS);
        for (double x = xMin; x <= xMax; x += step) {
            double y = linearEquation.evaluate(x);
            glVertex2d(x, y);
        }
        glEnd();
    }

    glFlush();
}

 //multi equation
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 1.0, 1.0); // Set color to white
//
//    // Draw x-axis
//    glBegin(GL_LINES);
//    glVertex2d(-10, 0);
//    glVertex2d(10, 0);
//    glEnd();
//
//    // Draw y-axis
//    glBegin(GL_LINES);
//    glVertex2d(0, -10);
//    glVertex2d(0, 10);
//    glEnd();
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
//            QuadraticEquation quadraticEquation(0, 0, a, b, c);
//
//            glBegin(GL_POINTS);
//            for (double x = -10; x <= 10; x += 0.1) {
//                double y = quadraticEquation.evaluate(x);
//                glVertex2d(x, y);
//            }
//            glEnd();
//        }
//        else if (equationType == "linear") {
//            std::cout << "Enter the coefficients (m, b): ";
//            std::cin >> m >> bIntercept;
//
//            LinearEquation linearEquation(0, 0, m, bIntercept);
//            glBegin(GL_POINTS);
//            for (double x = -10; x <= 10; x += 0.1) {
//                double y = linearEquation.evaluate(x);
//                glVertex2d(x, y);
//            }
//            glEnd();
//        }
//    }
//
//    glFlush();
//}




int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Graph Plotter");
    gluOrtho2D(-10, 10, -10, 10);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}