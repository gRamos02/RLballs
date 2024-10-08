#pragma once

class Application {
    public:
    Application(char *title, int screenWidth, int screenHeight);
    ~Application();
    void run();
    char *title;

    private:
    int screenWidth;
    int screenHeight;
};