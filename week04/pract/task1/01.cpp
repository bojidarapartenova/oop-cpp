#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <optional>

class Student
{
private:
    int id;
    std::string name;
    std::string facultyNumber;

public:
    Student(int id_, const std::string &name_, const std::string &facultyNumber_) : id(id_), name(name_), facultyNumber(facultyNumber_) {}

    Student() = default;

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getFacultyNumber() const { return facultyNumber; }

    void setId(int id_) { id = id_; }
    void setName(std::string name_) { name = name_; }
    void setFacultyNumber(std::string facultyNumber_) { facultyNumber = facultyNumber_; }

    void print()
    {
        std::cout << "Id: " << id << " Name: " << name << " Faculty Number: " << facultyNumber;
    }
};

class StudentRepository
{
private:
    std::vector<Student> students;
    std::string filename;
    static int nextId;

public:
    StudentRepository(const std::string &filename_) : filename(filename_) { load(); }

    void addStudent(const std::string &name, const std::string &facultyNumber)
    {
        Student student(nextId, name, facultyNumber);
        students.push_back(student);
        nextId++;
    }

    std::optional<Student> findById(int id_)
    {
        for (size_t i = 0; i < students.size(); i++)
        {
            if (students[i].getId() == id_)
            {
                return students[i];
            }
        }
        return std::nullopt;
    }

    bool updateStudent(int id, const std::string &name, const std::string &facultyNumber)
    {
        for (size_t i = 0; i < students.size(); i++)
        {
            if (students[i].getId() == id)
            {
                students[i].setName(name);
                students[i].setFacultyNumber(facultyNumber);
                return true;
            }
        }
        return false;
    }

    bool deleteStudent(int id)
    {
        for (size_t i = 0; i < students.size(); i++)
        {
            if (students[i].getId() == id)
            {
                students[i] = students.back();
                students.pop_back();
                return true;
            }
        }
        return false;
    }

    void save()
    {
        std::ofstream file(filename);
        if (!file.is_open())
        {
            return;
        }

        for (size_t i = 0; i < students.size(); i++)
        {
            file << students[i].getId() << ' ' << students[i].getName() << ' ' << students[i].getFacultyNumber() << std::endl;
        }
        file.close();
    }

    void load()
    {
        std::ifstream file(filename);
        if (!file.is_open())
        {
            return;
        }

        int id;
        std::string name;
        std::string facultyNumber;
        int maxId = 0;

        while (file >> id >> name >> facultyNumber)
        {
            Student s(id, name, facultyNumber);
            students.push_back(s);
            if (id > maxId)
            {
                maxId = id;
            }
        }
        file.close();
        nextId = maxId + 1;
    }

    std::vector<Student> getAll()
    {
        return students;
    }
};

int StudentRepository::nextId = 1;

int main()
{
    StudentRepository repo("students.txt");

    repo.addStudent("Ivan", "FN123");
    repo.addStudent("Maria", "FN456");
    repo.addStudent("Georgi", "FN789");

    repo.save();

    std::optional<Student> s = repo.findById(2);
    if (s.has_value())
    {
        std::cout << "Found student: ";
        s->print();
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Student with ID 2 not found." << std::endl;
    }

    bool updated = repo.updateStudent(3, "George", "FN789X");
    if (updated)
        std::cout << "Student with ID 3 updated." << std::endl;

    std::cout << "\nAll students:" << std::endl;
    std::vector<Student> allStudents = repo.getAll();
    for (size_t i = 0; i < allStudents.size(); i++)
    {
        allStudents[i].print();
        std::cout << std::endl;
    }

    bool deleted = repo.deleteStudent(1);
    if (deleted)
        std::cout << "\nStudent with ID 1 deleted." << std::endl;

    std::cout << "\nStudents after deletion:" << std::endl;
    std::vector<Student> remainingStudents = repo.getAll();
    for (size_t i = 0; i < remainingStudents.size(); i++)
    {
        remainingStudents[i].print();
        std::cout << std::endl;
    }

    repo.save();

    return 0;
}
