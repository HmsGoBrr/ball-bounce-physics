#ifndef UTILS_H
#define UTILS_H

#define GUNMETAL Color{ 18, 44, 52, 255 }
#define INDIGODYE Color{ 34, 72, 112, 255 }
#define DARKCONFLOWERBLUE Color{ 42, 68, 148, 255 }
#define CAROLINABLUE Color{ 78, 165, 217, 255 }

#include <iostream>
#define LOG(x) std::cout << x << std::endl;

struct Circle {
    float x;
    float y;
    float vx;
    float vy;
    float radius;
};

#endif
