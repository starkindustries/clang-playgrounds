#include <stdio.h>
#include <math.h>

// Define the interface for a shape
typedef struct {
    double (*area)(void* self);
    double (*perimeter)(void* self);
} ShapeInterface;

// Define the circle implementation
typedef struct {
    ShapeInterface interface;
    double radius;
} Circle;

double circle_area(void* self) {
    Circle* circle = (Circle*)self;
    return M_PI * circle->radius * circle->radius;
}

double circle_perimeter(void* self) {
    Circle* circle = (Circle*)self;
    return 2 * M_PI * circle->radius;
}

// Define the square implementation
typedef struct {
    ShapeInterface interface;
    double side_length;
} Square;

double square_area(void* self) {
    Square* square = (Square*)self;
    return square->side_length * square->side_length;
}

double square_perimeter(void* self) {
    Square* square = (Square*)self;
    return 4 * square->side_length;
}

// Function to print shape details
void print_shape_details(ShapeInterface* shape, void* implementation) {
    printf("Area: %f\n", shape->area(implementation));
    printf("Perimeter: %f\n", shape->perimeter(implementation));
}

int main() {
    // Create a circle
    Circle circle = {{circle_area, circle_perimeter}, 5.0};
    print_shape_details(&circle.interface, &circle);

    // Create a square
    Square square = {{square_area, square_perimeter}, 4.0};
    print_shape_details(&square.interface, &square);

    return 0;
}
