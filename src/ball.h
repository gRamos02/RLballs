#pragma once
#include <utility>
#include <raylib.h>
#include <math.h>
using namespace std;

class Ball {
    Vector2 position;
    Vector2 acceleration;
    Color color;

    public:
    Ball(Vector2 position, Vector2 acceleration, Color color);

    void update(int screenWidth, int screenHeight);

    void draw();

    float inline getX(){ return position.x; }
    float inline getY(){ return position.y; }
    float inline getAccX(){ return acceleration.x; }
    float inline getAccY(){ return acceleration.y; }
};