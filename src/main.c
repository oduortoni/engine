#include <stdio.h>

#include "header.h"


int main() {
    Vector3 v1 = {1.0f, 2.0f, 3.0f};
    Vector3 v2 = {4.0f, 5.0f, 6.0f};

    Vector3 result = add(v1, v2);
    printf("Add: (%.2f, %.2f, %.2f)\n", result.x, result.y, result.z);

    result = subtract(v1, v2);
    printf("Subtract: (%.2f, %.2f, %.2f)\n", result.x, result.y, result.z);

    float dotResult = dot(v1, v2);
    printf("Dot Product: %.2f\n", dotResult);

    result = cross(v1, v2);
    printf("Cross Product: (%.2f, %.2f, %.2f)\n", result.x, result.y, result.z);

    result = normalize(v1);
    printf("Normalized v1: (%.2f, %.2f, %.2f)\n", result.x, result.y, result.z);

    return 0;
}

