#include "header.h"

// draw/render the screen buffer on screen
void render(char **screen, int screenWidth, int screenHeight) {
    for (int y = 0; y < screenHeight; y++) {
        for (int x = 0; x < screenWidth; x++) {
            putchar(screen[y][x]);
        }
        putchar('\n');
    }
}

// clear the screen buffer
void clear(char **screen, int screenWidth, int screenHeight) {
    for (int y = 0; y < screenHeight; y++) {
        for (int x = 0; x < screenWidth; x++) {
            screen[y][x] = ' ';
        }
    }
}

// convert any cordinate to the screen cordinate
void toScreenCoord(Vector3 point, int *screenX, int *screenY, int screenWidth, int screenHeight) {
    *screenX = (int)((point.x + 1.0f) * 0.5f * screenWidth);   // Map x from [-1, 1] to [0, screenWidth]
    *screenY = (int)((1.0f - point.y) * 0.5f * screenHeight);  // Map y from [-1, 1] to [0, screenHeight]
}

