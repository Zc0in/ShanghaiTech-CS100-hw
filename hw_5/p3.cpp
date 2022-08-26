#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string>
#include <list>
#include <iomanip>
using namespace std;

const float PI = 3.14159f;

/***********************************************************************
* Declaration/Definition of the base-class Shape *
***********************************************************************/
class Shape
{
public:
    // constructors and destructor
    Shape() {}
    virtual ~Shape() {}
    // Accessors; you should decide which should be virtual or pure virtual.
    virtual float CalculateArea() {}
    virtual float CalculatePerimeter() {}
    virtual int NumberCorners() {}

private:
    // member variables;
};

/***********************************************************************
* Declaration/Definition of the child-classes *
***********************************************************************/
class Rectangle : public Shape
{
public:
    Rectangle(float height, float width) : height(height), width(width){};
    ~Rectangle() { cout << "A Rectangle has been destroyed." << endl; }
    virtual float CalculateArea()
    {
        return height * width;
    }
    virtual float CalculatePerimeter()
    {
        return 2 * (height + width);
    }
    virtual int NumberCorners()
    {
        return 4;
    }

private:
    float height, width;
};
class Square : public Shape
{
public:
    Square(float side) : side(side){};
    ~Square() { cout << "A Square has been destroyed." << endl; }
    virtual float CalculateArea()
    {
        return side * side;
    }
    virtual float CalculatePerimeter()
    {
        return 4 * side;
    }
    virtual int NumberCorners()
    {
        return 4;
    }

private:
    float side;
};
class Triangle : public Shape
{
public:
    Triangle(float height, float width) : height(height), width(width){};
    ~Triangle() { cout << "A Triangle has been destroyed." << endl; }
    virtual float CalculateArea()
    {
        return (height * width) / 2;
    }
    virtual float CalculatePerimeter()
    {
        return height + width + sqrt(height * height + width * width);
    }
    virtual int NumberCorners()
    {
        return 3;
    }

private:
    float height, width;
};
class Circle : public Shape
{
public:
    Circle(float r) : r(r){};
    ~Circle() { cout << "A Circle has been destroyed." << endl; }
    virtual float CalculateArea()
    {
        return PI * r * r;
    }
    virtual float CalculatePerimeter()
    {
        return 2 * PI * r;
    }
    virtual int NumberCorners()
    {
        return 0;
    }

private:
    float r;
};

/************************************************************************
* Main Function which is creating/reporting database (do not change!) *
************************************************************************/
int main()
{
    //initialize an empty list of shapes
    std::list<Shape *> shapeDatabase;
    //interact with the user: ask the user to enter shapes one by one
    while (1)
    {
        //print instructions as to how to enter a shape
        std::cout << "Enter a type (Circle, Triangle, Square, or Rectangle) ";
        std::cout << "and one or two size parameters, ";
        std::cout << "separated with blank spaces:\n";
        float size1;
        float size2;
        //check which shape has been requested and store in the database
        std::string shapeType;
        std::cin >> shapeType;
        if (shapeType == std::string("Circle"))
        {
            std::cin >> size1;
            shapeDatabase.push_back(new Circle(size1));
        }
        else if (shapeType == std::string("Triangle"))
        {
            std::cin >> size1 >> size2;
            shapeDatabase.push_back(new Triangle(size1, size2));
        }
        else if (shapeType == std::string("Square"))
        {
            std::cin >> size1;
            shapeDatabase.push_back(new Square(size1));
        }
        else if (shapeType == std::string("Rectangle"))
        {
            std::cin >> size1 >> size2;
            shapeDatabase.push_back(new Rectangle(size1, size2));
        }
        else
        {
            std::cout << "Unrecognized shape!!\n";
        }
        //check if the user wants to add more shapes
        std::cout << "Do you want to add more shapes? (Enter Y or N)\n";
        std::string answer;
        std::cin >> answer;
        if (answer != std::string("Y"))
            break;
    }
    //iterate through the list and output the area, perimeter,
    //and number of corners of each entered shape
    std::list<Shape *>::iterator it = shapeDatabase.begin();
    int shapeCounter = 0;
    while (it != shapeDatabase.end())
    {
        std::cout << "Properties of shape " << shapeCounter++ << ":\n";
        std::cout << "Area: " << std::setprecision(5) << (*it)->CalculateArea() << "\n";
        std::cout << "Perimeter: " << std::setprecision(5) << (*it)->CalculatePerimeter() << "\n";
        std::cout << "Corners: " << (*it)->NumberCorners() << "\n";
        std::cout << std::endl;
        it++;
    }

    it = shapeDatabase.begin();
    while (it != shapeDatabase.end())
    {
        delete (*it);
        it = shapeDatabase.erase(it);
    }

    return 0;
}
