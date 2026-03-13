#pragma once
#include "raylib-cpp/raylib-cpp.hpp"
#include <iostream>
#include "Hitbox.hpp"

class Background {
    private:
        std::vector<std::pair<int, Rectangle>> stars;
        float size;

    public:
        inline static std::pair<HitBox, HitBox> sideWalls;

        Background() {
            for (int i = 0; i < GetRandomValue(100, 150); i++) {
                size = GetRandomValue(1, 7);
                stars.push_back(std::pair<int, Rectangle>{GetRandomValue(90, 210),
                                Rectangle{(float)GetRandomValue(10, GetScreenWidth()), (float)GetRandomValue(10, GetScreenHeight()), size, size}});
            }
        }

        void Draw() {
            for (std::pair<int, Rectangle>& s : stars) {
                DrawRectangleRec(s.second, (Color){255, 255, 255, (unsigned char)s.first});
                s.second.y += s.first * 0.01f;

                if (s.second.y >= GetScreenHeight()) {
                    size = GetRandomValue(1, 7);
                    s.first = GetRandomValue(90, 210);
                    s.second.x = GetRandomValue(10, GetScreenWidth());
                    s.second.y = 0;
                    s.second.width = size;
                    s.second.height = size;
                } 
            }
        }
};