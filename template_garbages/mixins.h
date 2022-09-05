#pragma once
#include <string>

template<typename... Mixins>
class Point : public Mixins...
{
public:
    double x, y;
    Point() : Mixins()..., x(0.0), y(0.0) { }
    Point(double x, double y) : Mixins()..., x(x), y(y) { }
};

class Label
{
public:
    std::string label;
    Label() : label("") { }
};

class Color
{
public:
    unsigned char red = 0, green = 0, blue = 0;
};