#include <iostream>
#include <string>
#include <cmath>

#include <fstream>
#include <vector>
#include <algorithm>

const auto PI = 3.141592653589793;

enum class coordinate_system {
    Cartesian, Polar
};

class Point {
private:
    double x;
    double y;

    double r;
    double phi;

    coordinate_system coord_system;

public:
    Point(double a1 = 0, double a2 = 0, coordinate_system coord_system = coordinate_system::Cartesian)
    {
        if (coord_system == coordinate_system::Cartesian)
        {
            x = a1;
            y = a2;
            r = sqrt(a1 * a1 + a2 * a2);
            phi = 1 / tan(a2 / a1);
        }
        else
        {
            r = a1;
            phi = a2;
            x = r * cos(phi);
            y = r * sin(phi);
        }
    }

    virtual ~Point() {}

    double get_x()
    {
        return x;
    }

    double get_y()
    {
        return y;
    }

    double get_r()
    {
        return r;
    }

    double get_phi()
    {
        return phi;
    }

    void set_x(double x)
    {
        this->x = x;
    }

    void set_y(double y)
    {
        this->y = y;
    }
    void set_r(double r)
    {
        this->r = r;
    }

    void set_phi(double phi)
    {
        this->phi = phi;
    }

    double round_to_10_decimal_places(double x)
    {
        if (x > 0)
            return round(x * pow(10, 10)) / pow(10, 10);
        else
            return round(-x * pow(10, 10)) / pow(10, 10);

    }

    bool operator==(const Point& rhs)
    {
        if (round_to_10_decimal_places(this->x) == round_to_10_decimal_places(rhs.x)
        && round_to_10_decimal_places(this->y) == round_to_10_decimal_places(rhs.y))
            return true;
        return false;
    }

    bool operator!=(const Point& rhs)
    {
        return !(*this == rhs);
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& point)
    {
        out << '(' << point.x << ',' << point.y << ')';
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Point& point)
    {
        char a, b, c;
        in >> a >> point.x >> b >> point.y >> c;

        return in;
    }
};
