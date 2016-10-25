#ifndef LIBRARY_H
#define LIBRARY_H

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QTextStream>
#include "iostream"
#include "reader.h"
#include "book.h"

using namespace std;

class Library
{ 
public:

    vector <Reader> ReaderList;
    vector <Book> ListBook;

    Library();

    void addReader(QString firstName, QString lastName,int age){
        //reader.push_back(Reader(firstName, lastName,age));
    }
    void addBook(Book book){
        ListBook.push_back(book);
    }
    void searchByGenre(QString genre);
    void searchByAuthor(QString author);

    void loadFromJsonFile();
    Book readBook(const QJsonObject &json){
       QJsonObject jsonObj = json["Author"].toObject();
       Author a.readAutorFromJson(jsonObj);
       return Book(json["Title"].toString(),json["Genre"].toString(), a);
    }
    void saveBookToJsonString(QJsonArray &json)const;
    void saveBookToJsonFile();









//    void Library:: saveReaderToJsonString(QJsonArray &json)const{
//        for(int i = 0; i< ReaderList.size(); i++){
//           QJsonObject jsonObj;

//            jsonObj["First Name"] = ReaderList[i].getFirstName();
//            jsonObj["Last Name"] = ReaderList[i].getLastName();
//            jsonObj["Age"] = ReaderList[i].getAge(); //json.setValue("Title",ListBook[i].getTitle());
//            for(int n = 0; n<ReaderList[i].СardReader.size(); i++){

//            }
//            json.push_back(jsonObj);
//        }
//    }


};

#endif // LIBRARIAN_H
