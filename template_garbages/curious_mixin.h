#pragma once

template<typename Derived>
class Label2
{
public:
    std::string label;
    Label2() : label("") { }
};

template<typename Derived>
class Color2
{
public:
    unsigned char red = 0, green = 0, blue = 0;
};

template<template<typename> class...  Mixins>
class Point2 : public Mixins<Point2<Mixins...>>...
{
public:
    double x, y;
    Point2() : Mixins<Point2>()..., x(0.0), y(0.0) { }
    Point2(double x, double y) : Mixins<Point2>()..., x(x), y(y) { }
};