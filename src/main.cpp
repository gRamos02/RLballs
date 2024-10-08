#include "raylib.h"
#include "stdio.h"
#include "application.h"

int main(void)
{
    Application game = Application("Test",  800, 400);
    game.run();
    return 0;
}