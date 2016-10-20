#ifndef LIBRARY_H
#define LIBRARY_H

#include "QString"
#include "reader.h"
#include "book.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include "QTextStream"
#include "iostream"
class Library
{ 
public:

    vector <Reader> reader;
    vector <Book> ListBook;

    void show(){
        for(int i = 0; i<reader.size(); i++){
        cout<<reader[i].getFirstName().toStdString()<<endl;
        }
    }
    Library();

    void addReader(QString firstName, QString lastName,int age){
        reader.push_back(Reader(firstName, lastName,age));
    }
    void addBook(Book book){
        ListBook.push_back(book);
    }
    void searchByGenre(QString genre);
    void searchByAuthor(QString author);

    void read();
    void write(QJsonArray &json);
    QString serialize();

    void writeToFile(QString);

};

#endif // LIBRARIAN_H
