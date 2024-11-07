#include "header.h"

#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

void tiny_cube(char **screen);

int main() {
    int i;
    char grid[SCREEN_HEIGHT][SCREEN_WIDTH];
    char *screen[SCREEN_HEIGHT] = {0};
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        screen[i] = grid[i];
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            grid[i][j] = ' ';
        }
    }

    // a triangle in 3D space
    Triangle tri = {
        .v0 = {0.0f, 1.0f, 3.0f},
        .v1 = {-1.0f, -1.0f, 3.0f},
        .v2 = {1.0f, -1.0f, 3.0f}
    };

    // define projection parameters
    float fov = M_PI / 4.0f;         // 45 degrees
    float aspect_ratio = (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT;
    float z_near = 0.1f;
    float z_far = 100.0f;

    // create the projection matrix
    TMatrix projMatrix = initProjectionMatrix(fov, aspect_ratio, z_near, z_far);

    // clear the screen buffer
    clear(screen, SCREEN_WIDTH, SCREEN_HEIGHT);

    Vector3 lightDir = {0.0f, 1.0f, 0.6f}; // 0.7 intensity

    // draw the triangle
    // triangle(tri, projMatrix, screen, SCREEN_WIDTH, SCREEN_HEIGHT);
    tiny_cube(screen);

    // Render the screen
    render(screen, SCREEN_WIDTH, SCREEN_HEIGHT);

    return 0;
}

void tiny_cube(char **screen) {
    char shade = '.';
    line(1, 1, 5, 1, screen, SCREEN_WIDTH, SCREEN_HEIGHT, shade);
    line(5, 1, 7, 3, screen, SCREEN_WIDTH, SCREEN_HEIGHT, shade);
    line(7, 3, 3, 3, screen, SCREEN_WIDTH, SCREEN_HEIGHT, shade);
    line(3, 3, 1, 1, screen, SCREEN_WIDTH, SCREEN_HEIGHT, shade);
    line(7, 3, 7, 10, screen, SCREEN_WIDTH, SCREEN_HEIGHT, shade);
    line(3, 3, 3, 10, screen, SCREEN_WIDTH, SCREEN_HEIGHT, shade);
    line(7, 10, 3, 10, screen, SCREEN_WIDTH, SCREEN_HEIGHT, shade);
    line(1, 5, 3, 10, screen, SCREEN_WIDTH, SCREEN_HEIGHT, shade);
    line(1, 5, 1, 1, screen, SCREEN_WIDTH, SCREEN_HEIGHT, shade);
}
