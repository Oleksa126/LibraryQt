#ifndef AUTHOR_H
#define AUTHOR_H

#pragma once

#include "QString"

using namespace std;

class Author
{
private:
    QString FirstName;
    QString LastName;
public:
    Author(){};
    Author(QString firstName, QString lastName){
        setFirstName(firstName);
        setLastName(lastName);
    }

    void setFirstName(QString firstName) {
       FirstName = firstName;
    }
    void setLastName(QString lastName) {
       LastName = lastName;
    }

    QString getFirstName() const {
        return FirstName;
    }

    QString getLastName() const {
        return LastName;
    }


    ~Author();
};
#endif // AUTHOR_H
