#ifndef BOOK_H
#define BOOK_H

#include "QString"
#include "QJsonObject"
#include "author.h"
#include "iostream"
using namespace std;

static int counter;
class Book
{
private:
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

    QJsonObject saveBookToJson()const{
       QJsonObject jsonObj;
           jsonObj = this->author.saveAuthorToJson();
           jsonObj["Title"] = this->getTitle();
           jsonObj["Genre"] = this->getGenre();
           jsonObj["ID"] = this->getID();
       return jsonObj;
    }
    void showBook()const{
        cout<<getID()<< "\t" <<getTitle().toStdString()<<"\t"<<getGenre().toStdString()<<"\t"<<author.getFirstName().toStdString()<<"\t"<<author.getLastName().toStdString()<<endl;
    }

    void setTitle(QString title){Title = title;}
    void setGenre(QString genre){Genre = genre;}
    void setID(int id){ID = id;}

    QString getTitle()const{return Title;}
    QString getGenre()const{return Genre;}
    int getID()const{return ID;}

    ~Book(){}
};

#endif // BOOK_H
