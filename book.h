#ifndef BOOK_H
#define BOOK_H

//#pragma once

#include "QString"
#include "QVector"
#include "QJsonObject"
//#include "author.h"

using namespace std;

class Book
{
private:
    QString Title;
    QString Genre;
    //Author author;
public:
    Book();
    Book(const QString &title, const QString &genre);

    void setTitle(const QString &title) {
        Title = title;
    }
    void setGenre(const QString &genre) {
        Genre = genre;
    }

    QString getTitle() const {
        return Title;
    }
    QString getGenre() const{
        return Genre;
    }



    ~Book();
};



#endif // BOOK_H
