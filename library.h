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
//#include "book.h"

using namespace std;

class Library
{ 
public:

    vector <Reader> ReaderList;
    vector <Book> ListBook;

    void show(){
        for(int i = 0; i<ListBook.size(); i++){
        cout<<ListBook[i].getTitle().toStdString()<<"\t";
        cout<<ListBook[i].getGenre().toStdString()<<"\t";
        cout<<ListBook[i].getFirsName().toStdString()<<"\t";
        cout<<ListBook[i].getLastName().toStdString()<<endl;
        }
    }
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
       //return Book(json.value("Title").toString(),json.value("Genre").toString());
       return Book(json["Title"].toString(),json["Genre"].toString(), json["First Name"].toString(), json["Last Name"].toString());
    }
    void saveBookToJsonString(QJsonArray &json)const;
    void saveBookToJsonFile();

//    void Library:: saveReaderToJsonString(QJsonArray &json)const{
//        for(int i = 0; i< ReaderList.size(); i++){
//            QJsonObject jsonObj;

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
