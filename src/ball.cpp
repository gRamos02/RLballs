#include "ball.h"

Ball::Ball(Vector2 position, Vector2 acceleration, Color color)
    : position(position), acceleration(acceleration), color(color) {};

void Ball::update(int screenWidth, int screenHeight)
{
    if (position.x > screenWidth)
    {
        position.x = screenWidth;
        acceleration.x = -abs(acceleration.x);
    }
    else if (position.x < 0)
    {
        position.x = 0;
        acceleration.x = abs(acceleration.x);
    }

    if (position.y > screenHeight)
    {
        position.y = screenHeight;
        acceleration.y = -abs(acceleration.y);
    }
    else if (position.x < 0)
    {
        position.y = 0;
        acceleration.y = abs(acceleration.y);
    }

    position.x += acceleration.x;
    position.y += acceleration.y;

    if (position.x >= screenWidth || position.x <= 0)
    {
        acceleration.x = -acceleration.x;
    }
    if (position.y >= screenHeight || position.y <= 0)
    {
        acceleration.y = -acceleration.y;
    }
};

void Ball::draw()
{
    // DrawCircle(position.x, position.y, 10, color);
    // DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), 10, color);
    DrawCircle(position.x, position.y, 10, color);
    DrawText(
        TextFormat("X: %f, Y: %f, AccX: %f, AccY: %f ", position.x, position.y, acceleration.x, acceleration.y),
        position.x - 5, position.y - 5, 20, BLACK);
};
