#pragma once
#include "raylib-cpp/raylib-cpp.hpp"

class Animation {
    private:
        float width, height;
        float xSize, ySize, startX, startY;
        int duration;
        int frame = 0;
        int frameDelay = 5;
        double x, y;
        Texture2D spriteSheet;
        
    public: 
        bool done = false;
        inline static std::vector<Animation> animations;

        Animation(double x, double y, float startX, float startY, int width, int height, int xSize, int ySize, int duration, Texture2D spriteSheet) {
            this->x = x;
            this->y = y;
            this->startX = startX;
            this->startY = startY;
            this->width = width;
            this->height = height;
            this->xSize = xSize;
            this->ySize = ySize;
            this->duration = duration;
            this->spriteSheet = spriteSheet;
        }

        void draw();
        void update();

        ~Animation() {}
    
};