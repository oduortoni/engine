#ifndef _HEADER_H
#define _HEADER_H

typedef struct {
    float x;
    float y;
    float z;
} Vector3;

Vector3 add(Vector3 a, Vector3 b);
Vector3 subtract(Vector3 a, Vector3 b);
float dot(Vector3 a, Vector3 b);
Vector3 cross(Vector3 a, Vector3 b);
float magnitude(Vector3 v);
Vector3 normalize(Vector3 v);

#endif // _HEADER_H