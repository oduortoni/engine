#include "../src/header.h"

void project() {
    Vector3 point = {1.0f, 1.0f, 5.0f}; // A point in 3D space

    // Define a field of view (in radians), aspect ratio, near and far clipping planes
    float fov = M_PI / 4.0f; // 45 degrees
    float aspect_ratio = 16.0f / 9.0f;
    float z_near = 0.1f;
    float z_far = 100.0f;

    // Create the projection matrix
    TMatrix projMatrix = initProjectionMatrix(fov, aspect_ratio, z_near, z_far);

    // Project the point
    Vector3 projectedPoint = project(point, projMatrix);

    printf("Projected Point: (%.2f, %.2f, %.2f)\n", projectedPoint.x, projectedPoint.y, projectedPoint.z);
}
