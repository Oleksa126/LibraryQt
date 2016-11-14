#ifndef READER_H
#define READER_H

#include <QString>
#include <QDate>
#include <QJsonArray>
#include <vector>
#include "book.h"
#include "reading.h"
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
    Reader(QString firstName, QString lastName,int age);

    void addBookAtСard(Reading reading){СardReader.push_back(reading);}

    QJsonObject saveReaderToJson() const;

    bool operator<(const Reader &reader)
    {
        return this->getFirstName().toLower().operator <(reader.getFirstName().toLatin1().toLower());
    }

    friend ostream& operator <<(ostream &show, const Reader &reader);

    void booksLastYear(QString date);
    void booksLastYear(QDate date);
    void booksLastYear();

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
