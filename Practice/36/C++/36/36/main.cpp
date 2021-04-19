#include < iostream > #include < string > #include < cmath > #include < fstream > #include < vector > #include < algorithm > const auto PI = 3.141592653589793;

enum class coordinate_system {
    Cartesian,
    Polar
};

class Point {
    private : double x;
    double y;

    double r;
    double phi;

    coordinate_system coord_system;

    public : Point(double a1 = 0, double a2 = 0, coordinate_system coord_system = coordinate_system :: Cartesian) {
        if (coord_system == coordinate_system :: Cartesian) {
            x = a1;
            y = a2;
            r = sqrt(a1 * a1 + a2 * a2);
            phi = 1 / tan(a2 / a1);
        } else {
            r = a1;
            phi = a2;
            x = r * cos(phi);
            y = r * sin(phi);
        }
    }

    virtual ~ Point() {}

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
        this - > x = x;
    }

    void set_y(double y)
    {
        this - > y = y;
    }
    void set_r(double r)
    {
        this - > r = r;
    }

    void set_phi(double phi)
    {
        this - > phi = phi;
    }

    double round_to_10_decimal_places(double x)
    {
        if (x > 0) 
            return round(x * pow(10, 10)) / pow(10, 10);
        else 
            return round(-x * pow(10, 10)) / pow(10, 10);

        }
    
    bool operator == (const Point & rhs)
    {
        if (round_to_10_decimal_places(this - > x) == round_to_10_decimal_places(rhs.x) && round_to_10_decimal_places(this - > y) == round_to_10_decimal_places(rhs.y)) 
            return true;
        return false;
    }

    bool operator != (const Point & rhs)
    {
        return !(* this == rhs);
    }

    friend std :: ostream & operator << (std :: ostream & out, const Point & point)
    {
        out << '(' << point.x << ',' << point.y << ')';
        return out;
    }

    friend std :: istream & operator >> (std :: istream & in, Point & point)
    {
        char a,
        b,
        c; in >> a >> point.x >> b >> point.y >> c;

        return in;
    }
};

int main() {
    std :: vector < Point > original;
    std :: ifstream fin("data.txt");
    if (!fin.is_open()) {
        std :: cout << "Can't open file" << std :: endl;
        return 1;
    } else {
        while (!fin.eof()) {
            Point p;
            fin >> p;
            fin.ignore(2);
            original.push_back(p);
        }
        fin.close();
    }

    std :: vector < Point > simulacrum(original);
    for (auto & p : simulacrum) {
        //std::cout << p;
        p.set_x(p.get_x() + 10);
        p.set_phi(p.get_phi() + 180 * PI / 180);
        p.set_y(-p.get_y());
        p.set_x(-p.get_x() - 10);
        std :: cout << p << std :: endl;
    }

    if (std :: equal(original.begin(), original.end(), simulacrum.begin())) 
        std :: cout << "\nIt works!\n";
    else 
        std :: cout << "\nIt not works!\n";
    }
