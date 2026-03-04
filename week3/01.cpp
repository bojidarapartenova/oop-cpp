#include <iostream>
#include <string>
#include <print>

class Book
{
private:
    std::string title;
    std::string author;
    int pages;

public:
    Book() : title(""), author(""), pages(0)
    {
        std::printf("Default constructor called \n");
    }

    Book(const std::string &title_, const std::string &author_, int pages_) : title(title_), author(author_), pages(pages_)
    {
        std::printf("Parameterized constructor called \n");
    }

    Book(const Book &book) : title(book.title), author(book.author), pages(book.pages)
    {
        std::printf("Copy constructor called \n");
    }

    ~Book()
    {
        std::cout << "Destructor called for " << title << std::endl;
    }

    void printInfo() const
    {
        std::cout << "Title: " << title << ", author: " << author << ", pages: " << pages;
    }
};

int main()
{
    Book book1;

    Book book2("bookTitle", "bookAuthor", 100);

    Book book3(book2);

    std::cout << "book 1: ";
    book1.printInfo();
    std::cout << std::endl;

    std::cout << "book 2: ";
    book2.printInfo();
    std::cout << std::endl;

    std::cout << "book 3: ";
    book3.printInfo();
    std::cout << std::endl;
}