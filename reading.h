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
    Book book;
public:
//    Reading(QString whenTook, Book bookReader);
//    Reading(QString whenTook, QString whenReturn, Book bookReader);

    void setDateTookBook(QString date){
        TookBook.fromString(date);
    }
    void setDateReturnBook(QString date){
        ReturnBook.fromString(date);
    }

    QDate getDateTookBook(){
        return TookBook;
    }
    QDate getDateReturnBook(){
        return ReturnBook;
    }

};

#endif // READING_H
