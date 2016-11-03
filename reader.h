#ifndef READER_H
#define READER_H

#include <QString>
#include <QDate>
#include <QJsonArray>
#include <vector>
#include "book.h"
#include "reading.h"
#include "library.h"
using namespace std;

class Reader
{
private:
    QString FirstName;
    QString LastName;
    int Age;
    vector <Reading> СardReader;
public:
    Reader(){}
    Reader(QString firstName, QString lastName,int age){
        setFirstName(firstName);
        setLastName(lastName);
        setAge(age);
    }

    void isEmpty(){
        cout<<СardReader.empty();
    }
    void addBookAtСard(Reading reading){СardReader.push_back(reading);}
    QJsonObject saveReaderToJson() const{
        QJsonObject jsonObj;
        QJsonArray jsonArray;
            for(int i = 0; i<СardReader.size(); i++){
                jsonArray.append(this->СardReader[i].saveReadingToJson());
            }
        jsonObj["Book"] = jsonArray;
        jsonObj["FirstName"] = this->getFirstName();
        jsonObj["LastName"] = this->getLastName();
        jsonObj["Age"] = this->getAge();
        return jsonObj;
    }

    void booksLastYear(QString date){
        QDate one = QDate::fromString(date,"yyyyMd");
        booksLastYear(one);
    }
    void booksLastYear(QDate date){
        for(int i = 0; i<СardReader.size(); i++){
            if(date.daysTo(СardReader[i].getDateTookBook())<365 && date.daysTo(СardReader[i].getDateReturnBook())<365){
               cout<<СardReader[i].getBookID()<<"\t";
            }
        }
    }
    void booksLastYear(){
        booksLastYear(QDate::currentDate());
    }

    void setFirstName(QString firstName){
        FirstName = firstName;
    }
    void setLastName(QString lastName){
        LastName = lastName;
    }
    void setAge(int age){
        Age = age;
    }

    QString getFirstName()const{
       return FirstName;
    }
    QString getLastName()const{
        return LastName;
    }
    int getAge() const
    {
        return Age;
    }


    ~Reader(){}
};









#endif // READER_H
