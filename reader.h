#ifndef READER_H
#define READER_H

#pragma once

#include <QString>
#include <QDate>
#include "book.h"
#include "reading.h"
using namespace std;

class Reader
{
private:
    QString FirstName;
    QString LastName;
    int Age;
    vector<Reading> СardReader;
public:
    Reader(QString firstName, QString lastName,int age);

    Reader();

//    void booksLastYear(QString date){
//        vector<Reading> fromLastYear;
//        QDate one = QDate::fromString(date);
//        for(int i = 0; i<СardReader.size(); i++){
//            if(СardReader[i].getDateTookBook().daysTo(one)<365 && СardReader[i].getDateReturnBook().daysTo(one)<365){
//                fromLastYear.push_back(СardReader[i]);}
//        }
//    }

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

    void addBookAtСard(Reading reading){
        СardReader.push_back(reading);
    }

    ~Reader();
};



#endif // READER_H
