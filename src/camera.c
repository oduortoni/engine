#include "header.h"


/*
* takes user input and updates the camera reference
* reference is defined by position and rotation
*/
void cameraUpdateReference(Camera *camera, char input) {
    const float moveSpeed = 0.1f;
    const float rotateSpeed = 0.05f;

    switch (input) {
        case 'w': camera->position.z += moveSpeed; break; // Move forward
        case 's': camera->position.z -= moveSpeed; break; // Move backward
        case 'a': camera->rotationY -= rotateSpeed; break; // Rotate left
        case 'd': camera->rotationY += rotateSpeed; break; // Rotate right
    }
}
