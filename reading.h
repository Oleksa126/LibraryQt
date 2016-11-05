#ifndef READING_H
#define READING_H

#include "QDate"
#include "QString"
#include "book.h"
#include "library.h"

class Reading
{
private:
    QDate TookBook;
    QDate ReturnBook;
    int BookID;
public:
    Reading(){}
    Reading(QString whenTook, QString whenReturn,int id){
        setDateTookBook(whenTook);
        setDateReturnBook(whenReturn);
        setBookId(id);
    }

    QJsonObject saveReadingToJson()const{
        QJsonObject json;
        json["TookBook"] = this->getStingDateTookBook();
        json["ReturnBook"] = this->getStringDateReturnBook();
        json["ID"] = this->getBookID();
        return json;
    }
    void readReading(QJsonObject &json){
        this->setBookId(json["ID"].toInt());
        this->setDateReturnBook(json["ReturnBook"].toString());
        this->setDateTookBook(json["TookBook"].toString());
    }
    void setBookId(int id){
        BookID = id;}
    void setDateTookBook(QString date){
        TookBook = QDate::fromString(date,"yyyyMd");
    }
    void setDateReturnBook(QString date){
        ReturnBook = QDate::fromString(date,"yyyyMd");
    }

    int getBookID()const{return BookID;}
    QDate getDateTookBook()const{
        return TookBook;
    }
    QDate getDateReturnBook()const{
        return ReturnBook;
    }

    QString getStingDateTookBook()const{
        return TookBook.toString("yyyyMMdd");
    }
    QString getStringDateReturnBook()const{
        return ReturnBook.toString("yyyyMMdd");
    }
};

#endif // READING_H
