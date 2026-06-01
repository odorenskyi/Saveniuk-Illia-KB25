#ifndef MODULESSAVENIUK_H
#define MODULESSAVENIUK_H

#include <cmath>

class ClassLab12_Saveniuk {
private:
    double radius;

public:
    ClassLab12_Saveniuk(double r = 1.0);
    bool setRadius(double r);
    double getRadius() const;
    double getArea() const;
};

inline ClassLab12_Saveniuk::ClassLab12_Saveniuk(double r) {
    if (!setRadius(r)) {
        radius = 1.0;
    }
}

inline bool ClassLab12_Saveniuk::setRadius(double r) {
    if (r > 0) {
        radius = r;
        return true;
    }
    return false;
}

// ќсь тут тепер усе ч≥тко:
inline double ClassLab12_Saveniuk::getRadius() const {
    return radius;
}

inline double ClassLab12_Saveniuk::getArea() const {
    return 3.141592653589793 * radius * radius;
}

#endif
