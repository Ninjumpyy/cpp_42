#include <iostream>

class Rectangle {
private:
    // Data members (usually kept private for encapsulation)
    double width;
    double height;

public:
    // Constructor to initialize the object
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    // Member function to calculate area
    double area() {
        return width * height;
    }

    // Member function to display dimensions
    void display() {
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
    }

    // Setter functions to modify private data members
    void setWidth(double w) {
        width = w;
    }

    void setHeight(double h) {
        height = h;
    }

    // Getter functions to access private data members
    double getWidth() {
        return width;
    }

    double getHeight() {
        return height;
    }
};

int main() {
    // Creating an object of the Rectangle class
    Rectangle rect(5.0, 3.0);

    // Using member functions
    rect.display();
    std::cout << "Area: " << rect.area() << std::endl;

    // Modifying object state
    rect.setWidth(6.5);
    rect.setHeight(4.2);
    rect.display();
    std::cout << "New Area: " << rect.area() << std::endl;

    return 0;
}
