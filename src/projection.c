#include "header.h"

TMatrix initProjectionMatrix(float fov, float aspect, float zNear, float zFar) {
    TMatrix proj = {{{0}}}; // Initialize all elements to zero

    float f = 1.0f / tan(fov / 2.0f);
    proj.m[0][0] = f / aspect;
    proj.m[1][1] = f;
    proj.m[2][2] = (zFar + zNear) / (zNear - zFar);
    proj.m[2][3] = (2.0f * zFar * zNear) / (zNear - zFar);
    proj.m[3][2] = -1.0f;
    return proj;
}

/*
* project necessary for projecting 3d cooord onto a 2d space
* Given a homogenous matrix with a homogenous coord, w, we perform perspective division
* i.e divide the other coordinates by w
* we then discard w and are left with a Vector that is a representation of a 3d vector projected onto a 2d space
**/
Vector3 project(Vector3 v, TMatrix projMatrix) {
    Vector4 transformed = multiplyMatrixVector(projMatrix, v);
    
    // iff w is non-zero, divide
    if (transformed.w != 0.0f) {
        transformed.x /= transformed.w;
        transformed.y /= transformed.w;
        transformed.z /= transformed.w;
    }
    
    // Convert back to Vector3
    return (Vector3){ transformed.x, transformed.y, transformed.z };
}

