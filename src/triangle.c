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
void line(int x0, int y0, int x1, int y1, char **screen, int screenWidth, int screenHeight, char shade) {
    // are starting and ending points are within screen bounds
    if (x0 < 0 || x0 >= screenWidth || y0 < 0 || y0 >= screenHeight ||
        x1 < 0 || x1 >= screenWidth || y1 < 0 || y1 >= screenHeight) {
        fprintf(stderr, "Warning: Line coordinates out of bounds\n");
        return;
    }

    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        // check bounds before drawing
        if (y0 >= 0 && y0 < screenHeight && x0 >= 0 && x0 < screenWidth) {
            screen[y0][x0] = shade;
        }

        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}


// renders a triangle on screen
void triangle(Triangle tri, TMatrix projMatrix, char **screen, int screenWidth, int screenHeight, Vector3 lightDir) {
    if (!isFacingCamera(tri)) return;

    // project each vertex of the triangle onto 2d space
    Vector3 pV0 = project(tri.v0, projMatrix);
    Vector3 pV1 = project(tri.v1, projMatrix);
    Vector3 pV2 = project(tri.v2, projMatrix);

    // convert projected vertices to screen coordinates
    int x0, y0, x1, y1, x2, y2;
    toScreenCoord(pV0, &x0, &y0, screenWidth, screenHeight);
    toScreenCoord(pV1, &x1, &y1, screenWidth, screenHeight);
    toScreenCoord(pV2, &x2, &y2, screenWidth, screenHeight);

    // calculate surface normal of the triangle for lighting
    Vector3 normal = triangleSurfaceNormal(tri);

    // Calculate the intensity of light on the surface
    float intensity = lightIntensity(normal, lightDir);
    
    // select a representative token based on intensity
    char shade = lightIntensityShade(intensity);

    // draw edges between the vertices with lighting
    line(x0, y0, x1, y1, screen, screenWidth, screenHeight, shade);
    line(x1, y1, x2, y2, screen, screenWidth, screenHeight, shade);
    line(x2, y2, x0, y0, screen, screenWidth, screenHeight, shade);
}

/*
* The surface normal of a triangle is a vector that is perpendicular to the plane of the triangel
* We can get this through the cross product of two adjacent edges
* We eventually normalize the vector we get in order to make for simpler calculations
*/
Vector3 triangleSurfaceNormal(Triangle tri) {
    Vector3 u = { tri.v1.x - tri.v0.x, tri.v1.y - tri.v0.y, tri.v1.z - tri.v0.z };
    Vector3 v = { tri.v2.x - tri.v0.x, tri.v2.y - tri.v0.y, tri.v2.z - tri.v0.z };
    
    // cross product
    Vector3 normal = {
        .x = u.y * v.z - u.z * v.y,
        .y = u.z * v.x - u.x * v.z,
        .z = u.x * v.y - u.y * v.x
    };

    // normalization
    float length = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
    if (length != 0) {
        normal.x /= length;
        normal.y /= length;
        normal.z /= length;
    }

    return normal;
}
