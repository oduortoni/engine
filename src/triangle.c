#include "header.h"

Vector3 triNormal(Triangle tri) {
    Vector3 edge1 = subtract(tri.v1, tri.v0);
    Vector3 edge2 = subtract(tri.v2, tri.v0);
    return cross(edge1, edge2);
}

/*
* Used to decide whether to cull a triangle
* (dot > 0) cull
* (dot <= 0) draw
*/
bool isFacingCamera(Triangle tri) {
    Vector3 normal = triNormal(tri);
    return dot(normal, (Vector3){0, 0, -1}) < 0;
}

int abs(int n) {
    if(n < 0) {
        return -n;
    }
    return n;
}

/*
* Bresenham line algorithm to plot a line between vertices
*/
void line(int x0, int y0, int x1, int y1, char **screen, int screenWidth, int screenHeight) {
    // check if starting and ending points are within screen bounds
    if (x0 < 0 || x0 >= screenWidth || y0 < 0 || y0 >= screenHeight ||
        x1 < 0 || x1 >= screenWidth || y1 < 0 || y1 >= screenHeight) {
        fprintf(stderr, "Error: Line coordinates out of bounds\n");
        return;
    }

    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        // check if we are still within bounds before drawing
        if (y0 >= 0 && y0 < screenHeight && x0 >= 0 && x0 < screenWidth) {
            screen[y0][x0] = '.';
        }

        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

// renders a triangle on screen
void triangle(Triangle tri, TMatrix projMatrix, char **screen, int screenWidth, int screenHeight) {
    if (!isFacingCamera(tri)) return;

    Vector3 pV0 = project(tri.v0, projMatrix);
    Vector3 pV1 = project(tri.v1, projMatrix);
    Vector3 pV2 = project(tri.v2, projMatrix);

    // printf("After projection:\n");
    // printf("pV0 "); pvec(pV0); printf("\n");
    // printf("pV1 "); pvec(pV1); printf("\n");
    // printf("pV2 "); pvec(pV2); printf("\n");

    int x0, y0, x1, y1, x2, y2;
    toScreenCoord(pV0, &x0, &y0, screenWidth, screenHeight);
    toScreenCoord(pV1, &x1, &y1, screenWidth, screenHeight);
    toScreenCoord(pV2, &x2, &y2, screenWidth, screenHeight);

    // printf("After screen conversion:\n");
    // printf("x0: %d, y0: %d\n", x0, y0);
    // printf("x1: %d, y1: %d\n", x1, y1);
    // printf("x2: %d, y2: %d\n", x2, y2);

    // Render points and edges if within bounds
    // place '.' characters at each vertex
    if (x0 >= 0 && x0 < screenWidth && y0 >= 0 && y0 < screenHeight) {
        screen[y0][x0] = '.';
    }
    if (x1 >= 0 && x1 < screenWidth && y1 >= 0 && y1 < screenHeight) {
        screen[y1][x1] = '.';
    }
    if (x2 >= 0 && x2 < screenWidth && y2 >= 0 && y2 < screenHeight) {
        screen[y2][x2] = '.';
    }

    // draw edges between the vertices
    line(x0, y0, x1, y1, screen, screenWidth, screenHeight);
    line(x1, y1, x2, y2, screen, screenWidth, screenHeight);
    line(x2, y2, x0, y0, screen, screenWidth, screenHeight);
}
