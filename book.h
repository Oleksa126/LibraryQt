#ifndef BOOK_H
#define BOOK_H

#include "QString"
#include "QJsonObject"
#include "author.h"
#include "iostream"

#include<string.h>
using namespace std;

class Book
{
private:
    static int counter;
    int ID;
    QString Title;
    QString Genre;
public:
    Author author;

    Book(){}
    Book(const QString &title, const QString &genre, const QString &firstName, const QString &lastName)
    {
        setTitle(title);
        setGenre(genre);
        author.setFirstName(firstName);
        author.setLastName(lastName);
        setID(counter++);
    }

    Book(const QString &title, const QString &genre, const QString &firstName, const QString &lastName, int id)
    {
        setTitle(title);
        setGenre(genre);
        author.setFirstName(firstName);
        author.setLastName(lastName);
        setID(id);
        counter++;
    }

    QJsonObject saveBookToJson()const;

    void showBook()const{
        cout<<getID()<< "\t" <<getTitle().toStdString()<<"\t"<<getGenre().toStdString()<<"\t"<<author.getFirstName().toStdString()<<"\t"<<author.getLastName().toStdString()<<endl;
    }

    bool operator<(const Book & bk_)
    {
        return this->author.getFirstName().operator <( bk_.author.getFirstName().toLatin1());
    }

    friend ostream& operator <<(ostream &show, const Book &book);

    void setTitle(QString title){Title = title;}
    void setGenre(QString genre){Genre = genre;}
    void setID(int id){ID = id;}

    QString getTitle()const{return Title;}
    QString getGenre()const{return Genre;}
    int getID()const{return ID;}

    ~Book(){}
};


#endif // BOOK_H
