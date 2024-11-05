#include "../src/header.h"

void matrix() {
    Vector3 v = {1.0f, 2.0f, 3.0f};

    TMatrix transMat = translationMatrix(3.0f, 4.0f, 5.0f);
    Vector3 translatedV = multiplyMatrixVector(transMat, v);
    printf("Translated Vector: (%.2f, %.2f, %.2f)\n", translatedV.x, translatedV.y, translatedV.z);

    TMatrix scaleMat = scalingMatrix(2.0f, 2.0f, 2.0f);
    Vector3 scaledV = multiplyMatrixVector(scaleMat, v);
    printf("Scaled Vector: (%.2f, %.2f, %.2f)\n", scaledV.x, scaledV.y, scaledV.z);

    float forty5degrees = M_PI / 4;  // Rotate 45 degrees around X-axis
    TMatrix rotMatX = rotationMatrixX(forty5degrees);
    Vector3 rotatedV = multiplyMatrixVector(rotMatX, v);
    printf("Rotated Vector around X: (%.2f, %.2f, %.2f)\n", rotatedV.x, rotatedV.y, rotatedV.z);
}
