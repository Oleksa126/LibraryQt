#include "Book.h"
#include "iostream"
#include "fstream"
#include "QJsonDocument"
#include "QFile"
using namespace std;

Book::Book()
{
    const int MAX = 60;
    string title, genre;
    cout << "Enter tiitle book - " << endl;
    getline(cin, title);
    cout << "Enter ganre - " << endl;
    getline(cin, genre);
    //Book(title, genre);
}

Book::Book(const QString &title, const QString &genre)
{
    setTitle(title);
    setGenre(genre);

    QFile saveFile = QStringLiteral ("save.json");
    QJsonObject bookObject;
        write(bookObject);
        QJsonDocument saveDoc(bookObject);
        saveFile.write(saveDoc.toJson());

}

void Book::read(const QJsonObject &json){
    Title = json["Title"].toString();
    Genre = json["Genre"].toString();
}

void Book::write(QJsonObject &json) const
{
    json["Title"] = Title;
    json["Genre"] = Genre;
}

Book::~Book()
{
}
