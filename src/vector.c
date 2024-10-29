#include <math.h>

#include "header.h"

/*
* add/2 addition of two vectors
* input: 2 vectors
* output: a vector that is the component by component sum of the inputs
*/
Vector3 add(Vector3 a, Vector3 b) {
    return (Vector3){a.x + b.x, a.y + b.y, a.z + b.z};
}

/*
* subtract/2 subtraction of two vectors
* input: 2 vectors
* output: a vector that is the component by component difference
*/
Vector3 subtract(Vector3 a, Vector3 b) {
    return (Vector3){a.x - b.x, a.y - b.y, a.z - b.z};
}

/*
* dot/2 the dot product of two vectors
* input: 2 vectors
* output: a scalar (number) that is used to tell the angle between the two vectors
*/
float dot(Vector3 a, Vector3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

/*
* cross/2  the cross product
* input: two vectors
* output: a vector that is orthogonal(perpendicular) to the two input vectors. The normal vector
*/
Vector3 cross(Vector3 a, Vector3 b) {
    return (Vector3){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

/*
* magnitude/1 calculate the magnitude (length) of a vector. Useful during vector normalization
* input: a vector
* output: a scalar (number)
*/
float magnitude(Vector3 v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

/*
* normalize/1 used tonNormalize a vector (make it unit length)
* input: vector
* output: a vector that has all its components less than 1. Used to determine direction of the vector
*/
Vector3 normalize(Vector3 v) {
    float mag = magnitude(v);
    return (Vector3){v.x / mag, v.y / mag, v.z / mag};
}
