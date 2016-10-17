#ifndef BOOK_H
#define BOOK_H

#pragma once

#include "QString"
#include "QVector"
#include "QJsonObject"
using namespace std;

class Book
{
private:
    QString Title;
    QString Genre;//жанр
public:
    Book();
    Book(const QString &title, const QString &genre);

    void setTitle(const QString &title) {
        Title = title;
    }
    void setGenre(const QString &genre) {
        Genre = genre;
    }

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    //void write(QString title, QString genre);

    //vector<Book> writeValueAsObject();

    QString getTitle() const {
        return Title;
    }
    QString getGenre() const{
        return Genre;
    }
    ~Book();
};



#endif // BOOK_H
