#include "Book.h"
#include "iostream"
#include "fstream"

using namespace std;

Book::Book()
{
    const int MAX = 60;
    string title, genre;
    cout << "Enter tiitle book - " << endl;
    getline(cin, title);
    cout << "Enter ganre - " << endl;
    getline(cin, genre);
    Book(title, genre);
}

Book::Book(QString title, QString genre)
{
    setTitle(title);
    setGenre(genre);
}

void Book::read(const QJsonObject &json){
    Title = json["Title"].toString();
    Genre = json["Genre"].toString();
}

//void Book::write(QString title, QString genre)
//{
//    json j;
//    ofstream one("database.json", ios_base::app);
//    j["Title"] = title;
//    j["Genre"] = genre;
//    one << j;
//}

Book::~Book()
{
}
