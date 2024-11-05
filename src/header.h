#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif // M_PI

typedef struct {
    float x;
    float y;
    float z;
} Vector3;

typedef struct {
    float x, y, z, w;
} Vector4;

Vector3 add(Vector3 a, Vector3 b);
Vector3 subtract(Vector3 a, Vector3 b);
float dot(Vector3 a, Vector3 b);
Vector3 cross(Vector3 a, Vector3 b);
float magnitude(Vector3 v);
Vector3 normalize(Vector3 v);
void printV3(const char* label, Vector3 v);
void printV4(const char* label, Vector4 v);

typedef struct TransformationMatrix {
    float m[4][4];
} TMatrix;

TMatrix identityMatrix();
TMatrix translationMatrix(float tx, float ty, float tz);
TMatrix scalingMatrix(float sx, float sy, float sz);
TMatrix rotationMatrixX(float angle);
TMatrix rotationMatrixY(float angle);
TMatrix rotationMatrixZ(float angle);
Vector4 multiplyMatrixVector(TMatrix mat, Vector3 v);

TMatrix initProjectionMatrix(float fov, float aspect_ratio, float z_near, float z_far);
Vector3 project(Vector3 v, TMatrix projMatrix);

// triangle
typedef struct {
    Vector3 v0;
    Vector3 v1;
    Vector3 v2;
} Triangle;

Vector3 triNormal(Triangle tri);
bool isFacingCamera(Triangle tri);

void triangle(Triangle tri, TMatrix projMatrix, char **screen, int screenWidth, int screenHeight);
void line(int x0, int y0, int x1, int y1, char **screen, int screenWidth, int screenHeight);

// screen
void render(char **screen, int screenWidth, int screenHeight);
void clear(char **screen, int screenWidth, int screenHeight);
void toScreenCoord(Vector3 point, int *screenX, int *screenY, int screenWidth, int screenHeight);
void renderTriangle(Triangle tri, TMatrix projMatrix, char **screen, int screenWidth, int screenHeight);

#endif // _HEADER_H