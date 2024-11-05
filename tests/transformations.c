#include "../src/header.h"

// Identity Matrix Test
void testMultiplyByIdentityMatrix(Vector3 input) {
    printV3("Identity Matrix Input", input);
    TMatrix identity = identityMatrix();
    Vector4 output = multiplyMatrixVector(identity, input);
    printV4("Identity Matrix Output", output);
}

// Translation Test
void testTranslationMatrix(Vector3 input, float tx, float ty, float tz) {
    printV3("Translation Input", input);
    TMatrix translation = translationMatrix(tx, ty, tz);
    Vector4 output = multiplyMatrixVector(translation, input);
    printV4("Translation Output", output);
}

// Scaling Test
void testScalingMatrix(Vector3 input, float sx, float sy, float sz) {
    printV3("Scaling Input", input);
    TMatrix scaling = scalingMatrix(sx, sy, sz);
    Vector4 output = multiplyMatrixVector(scaling, input);
    printV4("Scaling Output", output);
}

// Rotation Test (around X-axis)
void testRotationMatrixX(Vector3 input, float angle) {
    printV3("Rotation X Input", input);
    TMatrix rotationX = rotationMatrixX(angle);
    Vector4 output = multiplyMatrixVector(rotationX, input);
    printV4("Rotation X Output", output);
}

// Rotation Test (around Y-axis)
void testRotationMatrixY(Vector3 input, float angle) {
    printV3("Rotation Y Input", input);
    TMatrix rotationY = rotationMatrixY(angle);
    Vector4 output = multiplyMatrixVector(rotationY, input);
    printV4("Rotation Y Output", output);
}

// Rotation Test (around Z-axis)
void testRotationMatrixZ(Vector3 input, float angle) {
    printV3("Rotation Z Input", input);
    TMatrix rotationZ = rotationMatrixZ(angle);
    Vector4 output = multiplyMatrixVector(rotationZ, input);
    printV4("Rotation Z Output", output);
}

// Perspective Projection Test
void testPerspectiveProjection(Vector3 input3d, TMatrix projMatrix) {
    printV3("Perspective Projection Input", input3d);
    Vector3 projectedto2d = project(input3d, projMatrix);
    printV3("Perspective Projection Output", projectedto2d);
}

void transformations() {
    Vector3 v3 = { 1.0f, 2.0f, 3.0f };

    puts(" ");

    // multiplying by the identity matrix produces a homogenous vector v4
    // with the w-component set to 1.0f, all others unchanged
    testMultiplyByIdentityMatrix(v3);
    puts("");

    // simply adds the components coordinate wise
    // v3.x translated by tx (here tx = 1.0f)
    // v3.y translated by ty (here ty = 2.0f)
    // v3.z translated by tz (here tz = 3.0f)
    testTranslationMatrix(v3, 1.0f, 2.0f, 3.0f);
    puts("");

    // scaling is more like magnification that makes things larger or smaller
    // good for putting things into perspective
    // for that we need a scaling factor
    testScalingMatrix(v3, 2.0f, 2.0f, 2.0f);
    puts("");

    // rotation tests with 90 degrees (in radians)
    // takes a coord from one plane to another plane
    float angle = M_PI / 2.0f;
    testRotationMatrixX(v3, angle);
    puts("");
    testRotationMatrixY(v3, angle);
    puts("");
    testRotationMatrixZ(v3, angle);
    puts("");

    // setup: perspective projection matrix
    float fov = M_PI / 4.0f;
    float aspect_ratio = 4.0f / 3.0f;
    float z_near = 0.1f;
    float z_far = 100.0f;
    TMatrix projMatrix = initProjectionMatrix(fov, aspect_ratio, z_near, z_far);
    // projects a 3d coordinate onto a 2d plane, taking into account perspective
    // if w gt than 1 then farther objects appear smaller
    testPerspectiveProjection(v3, projMatrix);
    puts("");
}
