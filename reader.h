#ifndef READER_H
#define READER_H


#pragma once

#include "QString"

using namespace std;

class Reader
{
private:
    string FirstName;
    string LastName;
    int Age;
public:
    Reader(QString firstName, QString lastName);
    Reader(QString firstName, QString lastName, int age);
    void setFullName(QString firstName, QString lastName);
    void setAge(int age);

    QString & getFullName() const
    {
        return FirstName + LastName;
    }
    int getAge() const
    {
        return Age;
    };

    ~Reader();
};



#endif // READER_H