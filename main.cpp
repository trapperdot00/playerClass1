#include <iostream>
#include <string>

class Point
{
public:
    Point() = default;
    Point(const int& x, const int& y) : xPos(x), yPos(y) {}
    Point(std::istream& is)
    {
        is >> xPos >> yPos;
    }
    
    std::ostream& print(std::ostream&) const;
    std::istream& read(std::istream&);
    
    Point& moveUp(const unsigned&);
    Point& moveDown(const unsigned&);
    Point& moveLeft(const unsigned&);
    Point& moveRight(const unsigned&);
private:
    int xPos = 0;
    int yPos = 0;
};

std::ostream& Point::print(std::ostream& os) const
{
    os << xPos << " " << yPos;
    return os;
}

std::istream& Point::read(std::istream& is)
{
    is >> xPos >> yPos;
    return is;
}

Point& Point::moveUp(const unsigned& step)
{
    yPos += step;
    return *this;
}

Point& Point::moveDown(const unsigned& step)
{
    yPos -= step;
    return *this;
}

Point& Point::moveRight(const unsigned& step)
{
    xPos += step;
    return *this;
}

Point& Point::moveLeft(const unsigned& step)
{
    xPos -= step;
    return *this;
}

int main() {
    Point orb;
    orb.print(std::cout) << std::endl;
    orb.moveUp(10).print(std::cout) << std::endl;
    orb.moveDown(10).print(std::cout) << std::endl;
    orb.moveRight(10).print(std::cout) << std::endl;
    orb.moveLeft(10).print(std::cout) << std::endl;

    return 0;
}
