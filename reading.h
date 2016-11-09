#ifndef READING_H
#define READING_H

#include "QDate"
#include "QString"
#include "book.h"
class Reading
{
private:
    QDate TookBook;
    QDate ReturnBook;
    int BookID;
public:
    Reading(){}
    Reading(QString whenTook, QString whenReturn,int id);

    QJsonObject saveReadingToJson()const;

    void readReading(QJsonObject &json);

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
