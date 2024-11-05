#include "../src/header.h"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

void triangle() {
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


    // draw the triangle
    triangle(tri, projMatrix, screen, SCREEN_WIDTH, SCREEN_HEIGHT);
    // line(10, 10, 26, 16, screen, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Render the screen
    render(screen, SCREEN_WIDTH, SCREEN_HEIGHT);
}
