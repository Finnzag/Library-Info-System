#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
public:
    Book();

private:
    std::string Name;
    int ID;
    std::string Genere;
    bool isAvaiable;

};

#endif // BOOK_H
