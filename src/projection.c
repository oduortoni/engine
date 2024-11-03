#include "header.h"

TMatrix initProjectionMatrix(float fov, float aspect_ratio, float z_near, float z_far) {
    TMatrix mat = {0};
    float f = 1.0f / tan(fov / 2.0f);

    mat.m[0][0] = f / aspect_ratio;
    mat.m[1][1] = f;
    mat.m[2][2] = z_far / (z_far - z_near);
    mat.m[2][3] = 1.0f;
    mat.m[3][2] = (-z_near * z_far) / (z_far - z_near);
    
    return mat;
}

Vector3 project(Vector3 v, TMatrix projMatrix) {
    Vector3 result;
    float w;

    result.x = v.x * projMatrix.m[0][0] + v.y * projMatrix.m[0][1] + v.z * projMatrix.m[0][2] + projMatrix.m[0][3];
    result.y = v.x * projMatrix.m[1][0] + v.y * projMatrix.m[1][1] + v.z * projMatrix.m[1][2] + projMatrix.m[1][3];
    result.z = v.x * projMatrix.m[2][0] + v.y * projMatrix.m[2][1] + v.z * projMatrix.m[2][2] + projMatrix.m[2][3];
    w        = v.x * projMatrix.m[3][0] + v.y * projMatrix.m[3][1] + v.z * projMatrix.m[3][2] + projMatrix.m[3][3];

    // Convert from 4D to 3D by dividing by w
    // dividing w by itself makes it 1 => homogenous matrix
    if (w != 0.0f) {
        result.x /= w;
        result.y /= w;
        result.z /= w;
    }

    return result;
}


