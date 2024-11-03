#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h>
#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif // M_PI

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

typedef struct TransformationMatrix {
    float m[4][4];
} TMatrix;

TMatrix identityMatrix();
TMatrix translationMatrix(float tx, float ty, float tz);
TMatrix scalingMatrix(float sx, float sy, float sz);
TMatrix rotationMatrixX(float angle);
TMatrix rotationMatrixY(float angle);
TMatrix rotationMatrixZ(float angle);
Vector3 multiplyMatrixVector(TMatrix mat, Vector3 v);

TMatrix initProjectionMatrix(float fov, float aspect_ratio, float z_near, float z_far);
Vector3 project(Vector3 v, TMatrix projMatrix);

#endif // _HEADER_H