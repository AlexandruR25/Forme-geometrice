// ------------------------------------------------------------------------------
// Fișier: main.cpp — Comentarii adăugate (fără modificări de logică)
// Tema 1 — Forme geometrice: clase Point, Shape, Quadrilateral, Circle;
// sortare după arie (apoi perimetru în caz de egalitate), afișare cu 6 zecimale.
// NOTĂ: Codul original al autorului a fost păstrat, s-au adăugat doar comentarii.
// ------------------------------------------------------------------------------

#include<bits/stdc++.h>

using namespace std;
// Declarație clasă

class Point {
private:
    double x, y;
public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    Point operator-(const Point &point) const {
        return Point(abs(x - point.x), abs(y - point.y));
    }

    void setX(double x) {
        this->x = x;
    }

    void setY(double y) {
        this->y = y;
    }
};
// Declarație clasă

class Shape {
protected:
    Point mFirst;
    Point mSecond;
    string mName;
public:
    Shape() {
        mFirst = Point();
        mSecond = Point();
    }

    Shape(Point x1, Point x2) {
        mFirst = x1;
        mSecond = x2;
    }

    string getName() const {
        return mName;
    }

    void setName(string name) {
        mName = name;
    }

    Point getFirst() const {
        return mFirst;
    }

    Point getSecond() const {
        return mSecond;
    }

    void setFirst(Point p) {
        mFirst = p;
    }

    void setSecond(Point p) {
        mSecond = p;
    }

    virtual double getPerimeter() const = 0;

    virtual double getArea() const = 0;
};
// Declarație clasă

class Quadrilateral : public Shape {
public:
    Quadrilateral() : Shape() {
        mName = "Unknown";
    }

    Quadrilateral(Point x1, Point x2, string name) : Shape(x1, x2) {
        mName = name;
    }

    double getLength() const {
        return abs(mFirst.getX() - mSecond.getX());
    }

    double getWidth() const {
        return abs(mFirst.getY() - mSecond.getY());
    }

    double getPerimeter() const {
        return 2 * (getLength() + getWidth());
    };

    double getArea() const {
        return getLength() * getWidth();
    }
};

bool comp(Shape *s1, Shape *s2) {
    if (s1->getArea() == s2->getArea())
        if (s1->getPerimeter() < s2->getPerimeter())
            return true;
        else
            return false;

    if (s1->getArea() < s2->getArea())
        return true;
    else
        return false;


}
// Declarație clasă

class Circle : public Shape {
private:
    double mRadius;
public:
    Circle() : Shape() {
        mName = "Unknown";
        mRadius = 0;
    }

    Circle(Point x1, double raza) {
        mFirst = Point(x1);
        mSecond = Point();
        mRadius = raza;
        mName = "cerc";
    }

    void setRadius(double raza) {
        mRadius = raza;
    }

    double getPerimeter() const {
        return 2 * M_PI * mRadius;
    };

    double getArea() const {
        return M_PI * mRadius * mRadius;
    };

    double getRadius() const {
        return mRadius;
    }
};
// Punct de intrare în aplicație

int main() {
    uint16_t n, ct = 0;
    double min, max;
    vector<Shape *> shape;
    shape.empty();
    cin >> n >> min >> max;
    if (n < 1 || n > 500 || min < -1000 || min > 1000 || max < -1000 || max > 1000)
        ct = 1;
    if (min > max)
        ct = 1;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        if (name == "cerc") {
            double x, y, raza;
            cin >> x >> y >> raza;
            // if (x <= min || x >= max || y <= min || y >= max) {
            //     ct = 1;
            // }
            if (raza < 0 || raza > 1000)
                ct = 1;
            Point p = Point(x, y);
            shape.push_back(new Circle(p, raza));
        }
        if (name == "patrat" || name == "dreptunghi") {
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 < -1000 || x1 > 1000 || x2 < -1000 || x2 > 1000)
                ct = 1;
            if (y1 < -1000 || y1 > 1000 || y2 < -1000 || y2 > 1000)
                ct = 1;

            Point p1 = Point(x1, y1);
            Point p2 = Point(x2, y2);
            shape.push_back(new Quadrilateral(p1, p2, name));
        }

    }
    sort(shape.begin(), shape.end(), comp);


    if (ct == 1)
        cout << "Valoare de intrare invalida";
    else
        for (Shape *x: shape) {
            cout << x->getName() << " " << fixed << setprecision(6) << x->getArea() << " " << fixed << setprecision(6)
                 << x->getPerimeter() << endl;
        }
}

