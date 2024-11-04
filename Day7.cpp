using namespace std;

class GemotricalShape
{
public:
    virtual float clacArea() = 0;
};

class GeometricShape
{
public:
    float area;
    virtual float clacArea()
    {
        return area;
    }
};

class Circle : public GeometricShape, public GemotricalShape
{
public:
    int radius;
    float clacArea()
    {
        return 3.14 * radius * radius;
    }
};

class Triangle : public GeometricShape, public GemotricalShape
{
public:
    int base;
    int hight;
    float clacArea()
    {
        return 0.5 * base * hight;
    }
};

class Rectangle : public GeometricShape, public GemotricalShape
{
public:
    int length;
    int width;
    float clacArea()
    {
        return width * length;
    }
};

class Square : public GeometricShape, public GemotricalShape
{
public:
    int L;
    float clacArea()
    {
        return L * L;
    }
};