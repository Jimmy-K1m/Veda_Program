#include <iostream>

class Circle_ {
private:
    int radius;
    static int numObject; // ���� ��� ����

public:
    // ������
    Circle_();
    Circle_(int r);

    // �Ҹ���
    ~Circle_();

    // ��� �Լ�
    double getArea();
    void setRadius(int r);
    static int getNumofCircles();
    static void setDefault();
};

// ���� ��� ���� �ʱ�ȭ
int Circle_::numObject = 0;

// ������
Circle_::Circle_() : radius(1) {
    numObject += 1;
}

Circle_::Circle_(int r) : radius(r) {
    numObject += 1;
}

// �Ҹ���
Circle_::~Circle_() {
    numObject -= 1;
}

// ��� �Լ� ����
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
