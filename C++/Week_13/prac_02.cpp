#include <iostream>
#include <string>

using namespace std;

class Point
{
    int x, y;

public:
    Point(){
        x =0;
        y =0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int getX() { return x; }
    int getY() { return y; }

protected:
    void move_up(int x, int y)
    {
        this->x += x;
        this->y += y;
    }
    void move_down(int x, int y)
    {
        this->x -= x;
        this->y -= y;
    }
};
class ColorPoint:public Point{
    string c;
public :
    ColorPoint();
    ColorPoint(int a, int b, string c = "Blue");
    void setPoint(int x,int y, char z);
    void show();
};
ColorPoint ::ColorPoint():Point(0,0){
    c = "Black";
}
ColorPoint :: ColorPoint(int a, int b, string c):Point(a,b){
    this->c = c;
}
void ColorPoint::setPoint(int a , int b, char z){
    if(z == '+')
        move_up(a,b);
    else if(z == '-')
        move_down(a,b);
}
void ColorPoint::show(){
    cout << c << "색으로 (" << getX() << "," << getY() << ") 에 위치한 점입니다." << endl;
}

int main()
{
    cout << "zeroPoint 객체 출력 "<<endl;
    ColorPoint zeroPoint; // BLACK에 (0, 0) 위치의 점
    zeroPoint.show();

    ColorPoint blue(5, 5);
    cout << endl
         << "blue 객체 출력" << endl;
    cout << "현재 위치에서 x:+10, y:+20 위치로 이동합니다" << endl;
    blue.setPoint(10, 20, '+');
    blue.show();

    ColorPoint red(50, 40, "RED");
    red.show();
    cout << "현재 위치에서 x:-10, y:-20 위치로 이동합니다" << endl;
    red.setPoint(10, 20, '-');
    red.show();
}
