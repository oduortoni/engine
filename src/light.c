#include "header.h"

/*
* When light falls on an object, there are surfaces that receive light directly and hence appear brighter
* Other surfaces are almost at an angle away, hence appear dimmer
* This function calculates the light intensity at a point 
* To do this, we need a vector that represents the direction of light 
* and a normalized vector that represents the normal of a surface.
* When we do the dot product of the two vectors, we can know the intensity of light that the surface receives
* The intensity is a number between 0 and 1
* 
*/
float lightIntensity(Vector3 normal, Vector3 lightDir) {
    // normalize the light direction
    float length = sqrt(lightDir.x * lightDir.x + lightDir.y * lightDir.y + lightDir.z * lightDir.z);
   
    if (length != 0) {
        lightDir.x /= length;
        lightDir.y /= length;
        lightDir.z /= length;
    }
    
    // calculate the dot product to get the light intensity
    float intensity = normal.x * lightDir.x + normal.y * lightDir.y + normal.z * lightDir.z;
    
    // clamp intensity between 0 (dark) and 1 (fully lit)
    if (intensity < 0) intensity = 0;
    return intensity;
}

/*
* abstracts away the intensity representation
* there are different shades to represent different intensities of light hitting a surface
* given the intensity, this function returns an appropriate shade representation
*/
char lightIntensityShade(float intensity) {
    if (intensity > 0.75) return '@';           // high intensity
    if (intensity > 0.7f) return '#';           // well lit
    else if (intensity > 0.5) return 'o';       // room lighting
    if (intensity > 0.3f) return ':';           // medium
    else if (intensity > 0.1f) return '.';      // low intensity
    else return ' ';                            // very low intensity
}

