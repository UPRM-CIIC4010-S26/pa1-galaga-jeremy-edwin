#include "Animation.hpp"

void Animation::draw() {
    DrawTexturePro(this->spriteSheet, Rectangle{this->startX + (this->width * this->frame), this->startY, this->width, this->height},
                Rectangle{(float)(this->x), (float)(this->y), this->xSize, this->ySize},
                Vector2{0, 0}, 0, WHITE);
}

void Animation::update() {
    frameDelay--;

    if (this->frame >= this->duration && frameDelay <= 0) this->done = true;

    if (frameDelay <= 0) {
        this->frame++;
        frameDelay = 5;
    }
}