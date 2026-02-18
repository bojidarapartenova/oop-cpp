#include <iostream>

struct ComplexNum
{
    double realPart;
    double imaginaryPart;

    ComplexNum sum(ComplexNum &num)
    {
        double resRealPart = this->realPart + num.realPart;
        double resImaginaryPart = this->imaginaryPart + num.imaginaryPart;

        ComplexNum result;
        result.realPart = resRealPart;
        result.imaginaryPart = resImaginaryPart;

        return result;
    }

    ComplexNum multiply(ComplexNum &num)
    {
        double resRealPart = this->realPart * num.realPart - this->imaginaryPart * num.imaginaryPart;
        double resImaginaryPart = this->realPart * num.imaginaryPart + this->imaginaryPart * num.realPart;

        ComplexNum result;
        result.realPart = resRealPart;
        result.imaginaryPart = resImaginaryPart;

        return result;
    }

    ComplexNum divide(ComplexNum &num)
    {
        double denominator = num.realPart * num.realPart + num.imaginaryPart * num.imaginaryPart;

        if (denominator == 0)
        {
            std::cout << "You can't divide by 0.";
            return ComplexNum{0, 0};
        }

        double resRealPart =
            (this->realPart * num.realPart + this->imaginaryPart * num.imaginaryPart) / denominator;

        double resImaginaryPart =
            (this->imaginaryPart * num.realPart - this->realPart * num.imaginaryPart) / denominator;

        ComplexNum result;
        result.realPart = resRealPart;
        result.imaginaryPart = resImaginaryPart;

        return result;
    }

    void prdoubleComplexNum()
    {
        std::cout << this->realPart << " + " << this->imaginaryPart << "i";
    }
};

int main()
{
    ComplexNum num1;
    double r1, im1;
    std::cin >> r1 >> im1;
    num1.realPart = r1;
    num1.imaginaryPart = im1;

    ComplexNum num2;
    double r2, im2;
    std::cin >> r2 >> im2;
    num2.realPart = r2;
    num2.imaginaryPart = im2;

    ComplexNum sumRes = num1.sum(num2);
    ComplexNum multiplyRes = num1.multiply(num2);
    ComplexNum divideRes = num1.divide(num2);

    std::cout << "sum: ";
    sumRes.prdoubleComplexNum();
    std::cout << std::endl;

    std::cout << "product: ";
    multiplyRes.prdoubleComplexNum();
    std::cout << std::endl;

    std::cout << "quotient: ";
    divideRes.prdoubleComplexNum();
    std::cout << std::endl;
}