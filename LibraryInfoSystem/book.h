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
    std::string Genre;
    bool isAvaiable;

public:

    void setName();
    void setGenre();
    void setIsAvailable();

    std::string getName();
    std::string getID();
    std::string getGenre();
    std::string getIsAvailable();


};

#endif // BOOK_H
