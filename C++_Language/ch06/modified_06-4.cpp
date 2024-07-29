#include <iostream>

class Circle_ {
private:
    int radius;
    static int numObject; // 정적 멤버 변수

public:
    // 생성자
    Circle_();
    Circle_(int r);

    // 소멸자
    ~Circle_();

    // 멤버 함수
    double getArea();
    void setRadius(int r);
    static int getNumofCircles();
    static void setDefault();
};

// 정적 멤버 변수 초기화
int Circle_::numObject = 0;

// 생성자
Circle_::Circle_() : radius(1) {
    numObject += 1;
}

Circle_::Circle_(int r) : radius(r) {
    numObject += 1;
}

// 소멸자
Circle_::~Circle_() {
    numObject -= 1;
}

// 멤버 함수 정의
double Circle_::getArea() {
    return 3.14 * radius * radius;
}

void Circle_::setRadius(int r) {
    radius = r;
}

int Circle_::getNumofCircles() {
    return numObject;
}

void Circle_::setDefault() {
    numObject = 0;
}

int _________________________main() {
    Circle_ c1;
    Circle_ c2(5);

    std::cout << "Number of Circles: " << Circle_::getNumofCircles() << std::endl;
    std::cout << "Area of c2: " << c2.getArea() << std::endl;

    c2.setRadius(10);
    std::cout << "New Area of c2: " << c2.getArea() << std::endl;

    Circle_::setDefault();
    std::cout << "Number of Circles after reset: " << Circle_::getNumofCircles() << std::endl;

    return 0;
}
