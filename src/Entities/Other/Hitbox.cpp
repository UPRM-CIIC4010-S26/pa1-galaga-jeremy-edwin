#include "Hitbox.hpp"

bool HitBox::Collision(HitBox h1, HitBox h2) {
    return (h1.left() <= h2.right() && h1.right() >= h2.left()) && 
        (h1.bottom() >= h2.top() && h1.top() <= h2.bottom());
}

std::pair<double, double> HitBox::CollisionMargins(HitBox h1, HitBox h2) {
    double xa = h2.left() - h1.right();
    double xb = h2.right() - h1.left();
    double xMin = abs(xa) < abs(xb) ? xa : xb;

    double ya = h2.top() - h1.bottom();
    double yb = h2.bottom() - h1.top();
    double yMin = abs(ya) < abs(yb) ? ya : yb;

    return std::pair(xMin, yMin);
}

void HitBox::draw() {
    DrawRectangleLinesEx(this->box, 1.0f, LIME);
}