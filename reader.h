#ifndef READER_H
#define READER_H

#pragma once

#include "QString"
#include "book.h"

using namespace std;

class Reader
{

private:
    QString FirstName;
    QString LastName;
    int Age;
    vector<Book> СardReader;
public:
    Reader(QString firstName, QString lastName,int age);

    Reader();

    void setFirstName(QString firstName){
        FirstName = firstName;
    }
    void setLastName(QString lastName){
        LastName = lastName;
    }
    void setAge(int age){
        Age = age;
    }

    QString getFirstName(){
       return FirstName;
    }

    QString getLastName(){
        return LastName;
    }

    int getAge() const
    {
        return Age;
    }

    void addBookAtСard(Book book){
        СardReader.push_back(book);
    }

    ~Reader();
};



#endif // READER_H
