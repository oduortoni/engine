#include "header.h"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24

void animateObject(Triangle *triangles, int numTriangles, float angle);
void getUserInput(int *ch);

void main() {
    int i;
    char grid[SCREEN_HEIGHT][SCREEN_WIDTH];
    char *screen[SCREEN_HEIGHT] = {0};
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        screen[i] = grid[i];
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            grid[i][j] = ' ';
        }
    }

    // vertices for a simple cube
    Vector3 vertices[8] = {
        {-1.0, -1.0, -1.0}, {1.0, -1.0, -1.0},
        {1.0,  1.0, -1.0}, {-1.0,  1.0, -1.0},
        {-1.0, -1.0,  1.0}, {1.0, -1.0,  1.0},
        {1.0,  1.0,  1.0}, {-1.0,  1.0,  1.0}
    };
    // a rectandle can be split into 2 triangles
    // since a cube is composed of rectangles, we can compose triangles to create one
    // triangles for the cube
    Triangle cubeTriangles[12] = {
        {vertices[0], vertices[1], vertices[2]}, {vertices[0], vertices[2], vertices[3]}, // front face
        {vertices[4], vertices[5], vertices[6]}, {vertices[4], vertices[6], vertices[7]}, // back face
        {vertices[0], vertices[4], vertices[7]}, {vertices[0], vertices[7], vertices[3]}, // left face
        {vertices[1], vertices[5], vertices[6]}, {vertices[1], vertices[6], vertices[2]}, // right face
        {vertices[3], vertices[2], vertices[6]}, {vertices[3], vertices[6], vertices[7]}, // top face
        {vertices[0], vertices[1], vertices[5]}, {vertices[0], vertices[5], vertices[4]}  // bottom face
    };


    // define projection parameters
    float fov = M_PI / 4.0f;         // 45 degrees
    float aspect_ratio = (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT;
    float z_near = 0.1f;
    float z_far = 100.0f;

    // create the projection matrix
    TMatrix projMatrix = initProjectionMatrix(fov, aspect_ratio, z_near, z_far);
    // direction of light on the scene
    Vector3 lightDir = {0.0f, 1.0f, 0.6f}; // 0.7 intensity
    // setup the camera's initial references
    Camera camera = {{0.0f, 0.0f, -5.0f}, 0.0f};

    float angle = 0.0f;
    int input;
    // while (1) {
        clear(screen, SCREEN_WIDTH, SCREEN_HEIGHT);

        // take in user input to reorient camera
        // getUserInput(&input);

        cameraUpdateReference(&camera, input);
        animateObject(cubeTriangles, 12, angle);

        // apply camera transformations and render each triangle
        // for (int i = 0; i < 12; i++) {
            // triangle(cubeTriangles[i], projMatrix, screen, SCREEN_WIDTH, SCREEN_HEIGHT, lightDir);
            triangle(cubeTriangles[0], projMatrix, screen, SCREEN_WIDTH, SCREEN_HEIGHT, lightDir);
        // }

        // rerender the screen
        render(screen, SCREEN_WIDTH, SCREEN_HEIGHT);

        // increment angle of rotation
        angle += 0.05f;
        getchar();
    // }
}


void animateObject(Triangle *triangles, int numTriangles, float angle) {
    TMatrix rotation = rotationMatrixY(angle);
    for (int i = 0; i < numTriangles; i++) {
        Vector4 v = multiplyMatrixVector(rotation, triangles[i].v0);
        triangles[i].v0.x = v.x;
        triangles[i].v0.y = v.y;
        triangles[i].v0.z = v.z;
        v = multiplyMatrixVector(rotation, triangles[i].v1);
        triangles[i].v1.x = v.x;
        triangles[i].v1.y = v.y;
        triangles[i].v1.z = v.z;
        v = multiplyMatrixVector(rotation, triangles[i].v2);
        triangles[i].v2.x = v.x;
        triangles[i].v2.y = v.y;
        triangles[i].v2.z = v.z;
    }
}

void getUserInput(int *ch) {
    printf("\n\nDirections\nw) forward\ns)back\na) left\nd) right");
    printf("\n>_ ");
    scanf("%d", ch);
}
