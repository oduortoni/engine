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
    *screenX = (int)((point.x + 1) * 0.5 * screenWidth);
    *screenY = (int)((1 - point.y) * 0.5 * screenHeight);
}
