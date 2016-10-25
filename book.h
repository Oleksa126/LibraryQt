#ifndef BOOK_H
#define BOOK_H

#include "QString"
#include "QVector"
#include "QJsonObject"

using namespace std;

struct Author{
    QString FirstName;
    QString LastName;
    Author(){}
    Author(QString &firstName, QString &lastName){FirstName = firstName; LastName = lastName;}

   QJsonObject saveAuthorToJson() const
    {
        QJsonObject jsonObj;
        jsonObj["First Name"] = FirstName;
        jsonObj["Last Name"] = LastName;
        return jsonObj;
    }
   Author readAutorFromJson(const QJsonObject &json){
      return Author (json["First Name"].toString(), json["Last Name"].toString());
   }
};


class Book
{   
public:
    QString Title;
    QString Genre;
    Author author;

    Book(const QString &title, const QString &genre, const QString &firstName, const QString &lastName)
    {
        Title = title;
        Genre = genre;
        author.FirstName = firstName;
        author.LastName = lastName;
    }

    Book(const QString &title, const QString &genre, Author aut)
    {
        Title = title;
        Genre = genre;
        author = aut;
    }

    ~Book();
};

#endif // BOOK_H
