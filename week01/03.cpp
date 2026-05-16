#include <iostream>
#include <string>
#include <vector>

enum Major
{
    SE,
    IS,
    CS,
    AM,
    M,
    I
};

struct Student
{
    double grade;
    std::string facultyNum;
    std::string name;
    Major major;
};

struct Group
{
    // int n;
    std::vector<Student> students;
    double average;
};

Group createGroup()
{
    int n;
    std::cin >> n;

    std::vector<Student> students(n);
    for (size_t i = 0; i < n; i++)
    {
        double grade;
        std::cin >> grade;

        std::string facultyNum;
        std::cin >> facultyNum;

        std::string name;
        std::cin >> name;

        int m;
        std::cin >> m;
        Major major = (Major)m;

        Student student;
        student.grade = grade;
        student.facultyNum = facultyNum;
        student.name = name;
        student.major = major;
        students[i] = student;
    }

    Group group;
    group.students = students;

    double sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum += students[i].grade;
    }
    group.average = sum / n;

    return group;
}

int scholarshipCount(Group &group, double minGrade)
{
    int count = 0;
    for (size_t i = 0; i < group.students.size(); i++)
    {
        if (group.students[i].grade >= minGrade)
        {
            count++;
        }
    }

    return count;
}

void scholarshipStudents(Group &group, double minGrade)
{
    std::vector<Student> result;

    for (size_t i = 0; i < group.students.size(); i++)
    {
        if (group.students[i].grade >= minGrade)
        {
            result.push_back(group.students[i]);
        }
    }

    std::sort(result.begin(), result.end(), [](const Student &a, const Student &b)
              { return a.facultyNum < b.facultyNum; });

    for (const auto &s : result)
    {
        std::cout << s.facultyNum << " " << s.name << " " << s.grade << std::endl;
    }
}

bool isInTheGroup(Group &group, std::string facultyNum)
{
    for (size_t i = 0; i < group.students.size(); i++)
    {
        if (group.students[i].facultyNum == facultyNum)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::cout << "Enter group info:\n";
    Group group = createGroup();

    std::cout << "Average grade: " << group.average << std::endl;

    double minGrade;
    std::cout << "Enter minimum grade for scholarship: ";
    std::cin >> minGrade;

    int count = scholarshipCount(group, minGrade);
    std::cout << "Number of scholarship students: " << count << std::endl;

    scholarshipStudents(group, minGrade);

    std::string searchFN;
    std::cout << "Enter faculty number to search: ";
    std::cin >> searchFN;
    if (isInTheGroup(group, searchFN))
    {
        std::cout << "Student " << searchFN << " is in the group.";
    }
    else
    {
        std::cout << "Student " << searchFN << " is NOT in the group.";
    }
}