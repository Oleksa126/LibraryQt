#include "library.h"

Library::Library()
{

}

void Library:: searchByGenre(QString genre){
    vector<Book> resultGenre;
    for(int i = 0; i<ListBook.size(); i++){
        if(ListBook[i].Genre == genre){
            resultGenre.push_back(ListBook[i]);
        }
    }

    cout << "\n\n\t\t\t Search books by " << genre.toStdString() << "\n\n";
}

void Library:: searchByAuthor(QString author){
    vector<Book> resultAuthor;
//    for(int i = 0; i<ListBook.size(); i++){
//        if(ListBook[i].getFirsName() == author || ListBook[i].getLastName() == author){
//            resultAuthor.push_back(ListBook[i]);
//        }
//    }

    cout << "\n\n\t\t\t Search books by " << author.toStdString() << "\n\n";
}

void Library:: saveBookToJsonString(QJsonArray &json)const{
    for(int i = 0; i< ListBook.size(); i++){
        QJsonObject jsonObj;
        ListBook[i].author.saveAuthorToJson();
        jsonObj["Author"] = ListBook[i].author.saveAuthorToJson();
        jsonObj["Title"] = ListBook[i].Title;
        jsonObj["Genre"] = ListBook[i].Genre;
        json.push_back(jsonObj);
    }
}

void Library:: saveBookToJsonFile(){
    QJsonArray json;
    this->saveBookToJsonString(json);
    QJsonDocument doc;
    doc.setArray(json);
    QString result = QString::fromUtf8(doc.toJson(QJsonDocument::Indented));

    QFile inFile("C:/Users/Oleksa/Documents/Library/saveBook.json");
    QTextStream stream(&inFile);
    if(!inFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        cout << "Error";
    }
    else{
        stream << result;
        stream.flush();
        inFile.close();
    }
}

void Library:: loadFromJsonFile(){
    QFile file("C:/Users/Oleksa/Documents/Library/loadBook.json");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        cout<<"Error";
    }
    QJsonDocument doc = QJsonDocument ::fromJson(file.readAll());
    file.close();

    QJsonArray jsonArray = doc.array();
    foreach (QJsonValue jsonBook, jsonArray) {
        ListBook.push_back(Library::readBook(jsonBook.toObject()));
     }
}
