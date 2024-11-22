#include <stdio.h>
#include <stdbool.h>

struct Rectangle {
    float length;
    float width;
};

bool check(float length, float width) {
    return length > 0.0 && length < 20.0 && width > 0.0 && width < 20.0;
}

float calculatePerimeter(struct Rectangle r) {
    return 2 * (r.length + r.width);
}

float calculateArea(struct Rectangle r) {
    return r.length * r.width;
}

int main() {
    struct Rectangle r;
    printf("Enter length and width of the rectangle: ");
    scanf("%f %f", &r.length, &r.width);

    if (check(r.length, r.width)) {
        printf("Perimeter: %.2f\n", calculatePerimeter(r));
        printf("Area: %.2f\n", calculateArea(r));
    } else {
        printf("Invalid dimensions. Length and width must be between 0.0 and 20.0.\n");
    }
    return 0;
}
