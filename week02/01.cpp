#include <iostream>
#include <string>
#include <fstream>

class Thermometer
{
private:
    double temp_;

public:
    void setTemperature(double temp)
    {
        if (temp < -273.15)
        {
            std::cout << "Invalid temperature!" << std::endl;
            temp_ = -273.15;
        }
        else
        {
            temp_ = temp;
        }
    }

    double getFarenheit() const
    {
        return temp_ * 9.0 / 5.0 + 32.0;
    }

    void logTemperature(const std::string &filename) const
    {
        std::ofstream file(filename);
        if (!file)
        {
            std::cout << "Cannot open file!";
            return;
        }

        file << "Celsius: " << temp_ << "\n";
        file << "Farenheit: " << getFarenheit() << "\n";
        file.close();
    }
};

int main()
{
    std::cout << "Enter temperature in Celsius: ";
    double temp;
    std::cin >> temp;

    Thermometer thermometer;
    thermometer.setTemperature(temp);

    std::cout << "Temperature in Farenheit: " << thermometer.getFarenheit() << std::endl;

    std::cout << "Enter a file name: ";
    std::string file;
    std::cin >> file;
    thermometer.logTemperature(file);
}