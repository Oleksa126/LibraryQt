#ifndef AUTHOR_H
#define AUTHOR_H

#pragma once

#include "QString"
#include "vector"
#include "Book.h"

using namespace std;

class Author
{
private:
    QString FullName;
    vector <Book> ListBook;
public:
    Author(QString fullName);
    Author(QString fullName, vector <Book> book);
    void setFullName(QString fullName) {
        FullName = fullName;
    }
    void setListBook(vector <Book> book){
        ListBook.swap(book);
    }

    //void write(Author author);


    QString getFullName() const {
        return FullName;
    }
    vector<Book> getListBook() const {
        return ListBook;
    }
    ~Author();
};
#endif // AUTHOR_H