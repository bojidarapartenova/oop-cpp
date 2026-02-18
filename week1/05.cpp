#include <iostream>
#include <string>
#include <vector>

enum Position
{
    SoftwareEngineer,
    SeniorSoftwareEngineer,
    EngineerManager,
    LeadSoftwareEngineer
};

struct Worker
{
    std::string name;
    Position position;
    double salary;
    int grade;
};

Worker createWorker()
{
    std::string name;
    std::cin >> name;

    int p;
    std::cin >> p;
    Position position = (Position)p;

    double salary;
    std::cin >> salary;

    int grade;
    std::cin >> grade;

    Worker worker;
    worker.name = name;
    worker.position = position;
    worker.salary = salary;
    worker.grade = grade;

    return worker;
}

void printInfo(Worker &worker)
{
    std::cout << "Name: " << worker.name << std::endl;
    std::cout << "Position: " << worker.position << std::endl;
    std::cout << "Salary: " << worker.salary << std::endl;
    std::cout << "Grade: " << worker.grade << std::endl;
}

struct Company
{
    std::vector<Worker> workers;

    double calcAverageSalary()
    {
        double sum = 0;
        for (size_t i = 0; i < workers.size(); i++)
        {
            sum += workers[i].salary;
        }

        return sum / workers.size();
    }
};

Company createCompany()
{
    int n;
    std::cin >> n;

    std::vector<Worker> workers(n);
    for (size_t i = 0; i < n; i++)
    {
        Worker worker = createWorker();
        workers[i] = worker;
    }

    Company company;
    company.workers = workers;

    return company;
}

void aboveAverageWorkers(Company &company)
{
    std::vector<std::string> result;

    double average = company.calcAverageSalary();
    for (size_t i = 0; i < company.workers.size(); i++)
    {
        if (company.workers[i].salary > average)
        {
            result.push_back(company.workers[i].name);
        }
    }

    std::sort(result.begin(), result.end());

    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }
}

int main()
{
    std::cout << "Enter number of workers: ";
    Company company = createCompany();

    std::cout << "Workers with salary above average (sorted by name):" << std::endl;
    aboveAverageWorkers(company);
}
