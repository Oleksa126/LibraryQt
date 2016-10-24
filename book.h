#ifndef BOOK_H
#define BOOK_H

#include "QString"
#include "QVector"
#include "QJsonObject"
using namespace std;

/*
struct Author{
    QString FirstName;
    QString LastName;
    Author(QString firstName, QString lastName):FirstName(firstName), LastName(lastName){}

    Book(const QString &title, const QString &genre, const QString &firstName, const QString &lastName)
        : author (new Author(firstName, lastName)){
        setTitle(title);
        setGenre(genre);
    }
};
*/

class Book
{
private:
    QString Title;
    QString Genre;
    QString FirstName;
    QString LastName;
public:
    Book(const QString &title, const QString &genre, const QString &firstName, const QString &lastName){
        setTitle(title);
        setGenre(genre);
        setFirstName(firstName);
        setLastName(lastName);
    }

    void setTitle(const QString &title) {
        Title = title;
    }
    void setGenre(const QString &genre) {
        Genre = genre;
    }
    void setFirstName(const QString &firstName){
        FirstName = firstName;
    }
    void setLastName(const QString &lastName){
        LastName = lastName;
    }

    QString getTitle() const {
        return Title;
    }
    QString getGenre() const{
        return Genre;
    }
    QString getLastName() const {
        return LastName;
    }
    QString getFirsName() const {
        return FirstName;
    }

    ~Book();
};

#endif // BOOK_H
