#include <iostream>
#include <vector>

struct Triangle
{
    int a;
    int h;

    double calcArea()
    {
        return (this->a * this->h) / 2.0;
    }
};

void swap(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<double> areas(n);
    for (size_t i = 0; i < n; i++)
    {
        int a, h;
        std::cin >> a >> h;

        Triangle triangle;
        triangle.a = a;
        triangle.h = h;

        double area = triangle.calcArea();
        areas[i] = area;
    }

    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - 1 - i; j++)
        {
            if (areas[j] > areas[j + 1])
            {
                swap(areas[j], areas[j + 1]);
            }
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        std::cout << areas[i] << " ";
    }
}