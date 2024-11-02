#include <math.h>

#include "header.h"

TMatrix identityMatrix() {
    TMatrix mat = {0};
    for (int i = 0; i < 4; i++) {
        mat.m[i][i] = 1.0f;
    }
    return mat;
}

// movement ofobjects
TMatrix translationMatrix(float tx, float ty, float tz) {
    TMatrix mat = identityMatrix();
    mat.m[0][3] = tx;
    mat.m[1][3] = ty;
    mat.m[2][3] = tz;
    return mat;
}

// scaling adjust in size(scale)
TMatrix scalingMatrix(float sx, float sy, float sz) {
    TMatrix mat = identityMatrix();
    mat.m[0][0] = sx;
    mat.m[1][1] = sy;
    mat.m[2][2] = sz;
    return mat;
}

// rotation around the x-axis
TMatrix rotationMatrixX(float angle) {
    TMatrix mat = identityMatrix();
    float cosA = cos(angle);
    float sinA = sin(angle);

    mat.m[1][1] = cosA;
    mat.m[1][2] = -sinA;
    mat.m[2][1] = sinA;
    mat.m[2][2] = cosA;
    return mat;
}

// rotation around the y-axis
TMatrix rotationMatrixY(float angle) {
    TMatrix mat = identityMatrix();
    float cosA = cos(angle);
    float sinA = sin(angle);

    mat.m[0][0] = cosA;
    mat.m[0][2] = sinA;
    mat.m[2][0] = -sinA;
    mat.m[2][2] = cosA;
    return mat;
}

// rotation around the z-axis
TMatrix rotationMatrixZ(float angle) {
    TMatrix mat = identityMatrix();
    float cosA = cos(angle);
    float sinA = sin(angle);

    mat.m[0][0] = cosA;
    mat.m[0][1] = -sinA;
    mat.m[1][0] = sinA;
    mat.m[1][1] = cosA;
    return mat;
}

// transformation
// in order to apply a transformation to a vector, we multiply it by a matrix that has our desired effect
// it is a normal 3 by 3 multiplication but with the translation components added from the fourth column in order
// to apply whatever translation the matrix offers
Vector3 multiplyMatrixVector(TMatrix mat, Vector3 v) {
    Vector3 result;
    result.x = v.x * mat.m[0][0] + v.y * mat.m[0][1] + v.z * mat.m[0][2] + mat.m[0][3];
    result.y = v.x * mat.m[1][0] + v.y * mat.m[1][1] + v.z * mat.m[1][2] + mat.m[1][3];
    result.z = v.x * mat.m[2][0] + v.y * mat.m[2][1] + v.z * mat.m[2][2] + mat.m[2][3];
    return result;
}


