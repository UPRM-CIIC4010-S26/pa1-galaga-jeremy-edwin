#pragma once
#include "raylib-cpp/raylib-cpp.hpp"

class HitBox {
    public:
        Rectangle box;
        
    public:
        inline static bool drawHitbox = false;

        HitBox(float x, float y, float width, float height) {
            this->box = Rectangle { x, y, width, height }; 
        }

        HitBox() {
            this->box = Rectangle {0, 0, 0, 0 };
        }

        void setPosition(float x, float y) {
            this->box.x = x;
            this->box.y = y;
        }

        void setSize(float width, float height) {
            this->box.width = width;
            this->box.height = height;
        }

        float getWidth() { return this->box.width; }
        float getHeight() { return this->box.height; }
        double left() { return this->box.x; }
        double right() { return this->box.x + this->box.width; }
        double top() { return this->box.y; }
        double bottom() { return this->box.y + this->box.height; }

        static bool Collision(HitBox h1, HitBox h2);
        static std::pair<double, double> CollisionMargins(HitBox h1, HitBox h2);
        void draw();

        ~HitBox() {}

};