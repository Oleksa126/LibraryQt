#ifndef LIBRARY_H
#define LIBRARY_H

#include "reader.h"
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QTextStream>
#include "iostream"
#include "reading.h"
#include "book.h"

using namespace std;

class Library
{
public:
    vector <Book> ListBook;
    vector <Reader> ListReader;

    void findBookById(int bookId)const{
        for(int i =0; i<ListBook.size(); i++){
            if(ListBook[i].getID() == bookId){
                ListBook[i].showBook();
            }
        }

    }
    void addBook(Book book){ListBook.push_back(book);}
    void addReader(Reader reader){ListReader.push_back(reader);}

    void searchByGenre(QString genre);
    void searchByAuthor(QString author);

    void loadBooksFromJsonFile();
    Book readBook(const QJsonObject &json){
       return Book(json["Title"].toString(),json["Genre"].toString(),json["First Name"].toString(),json["Last Name"].toString(), json["ID"].toInt());}
    void saveBookToJsonString(QJsonArray &json)const;
    void saveBookToJsonFile();

    void saveReaderToJsonString(QJsonArray &json)const;
    void saveReaderToJsonFile();
    void loadReadersFromJsonFile();
    Reader readReader(const QJsonObject &json);
};

















//    void saveReaderToJsonFile(){
//        QJsonArray json;
//        this->saveReaderToJsonString(json);
//        QJsonDocument doc;
//        doc.setArray(json);
//        QString result = QString::fromUtf8(doc.toJson(QJsonDocument::Indented));

//        QFile inFile("C:/Users/Oleksa/Documents/Library/saveReader.json");
//        QTextStream stream(&inFile);
//        if(!inFile.open(QIODevice::WriteOnly | QIODevice::Text)){
//            cout << "Error";
//        }
//        else{
//            stream << result;
//            stream.flush();
//            inFile.close();
//        }

//    }

//    void Library:: saveReaderToJsonString(QJsonArray &json)const{
//        for(int i = 0; i< ReaderList.size(); i++){
//           QJsonObject jsonObj;
//            jsonObj = ReaderList[i].saveReaderToJson();
//        }
//    }




#endif // LIBRARIAN_H
