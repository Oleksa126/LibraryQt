#include "library.h"

Library::Library()
{

}

void Library:: searchByGenre(QString genre){
    vector<Book> resultGenre;
    for(int i = 0; i<ListBook.size(); i++){
        if(ListBook[i].getGenre() == genre){
            resultGenre.push_back(ListBook[i]);
        }
    }

    cout << "\n\n\t\t\t Search books by " << genre.toStdString() << "\n\n";
    for(int i = 0; i<resultGenre.size(); i++){
        cout<<resultGenre[i].getTitle().toStdString()<<"\t";
        cout<<resultGenre[i].getGenre().toStdString()<<"\t";
        cout<<resultGenre[i].getFirsName().toStdString()<<"\t";
        cout<<resultGenre[i].getLastName().toStdString()<<endl;
    }
}

void Library:: searchByAuthor(QString author){
    vector<Book> resultAuthor;
    for(int i = 0; i<ListBook.size(); i++){
        if(ListBook[i].getFirsName() == author || ListBook[i].getLastName() == author){
            resultAuthor.push_back(ListBook[i]);
        }
    }

    cout << "\n\n\t\t\t Search books by " << author.toStdString() << "\n\n";
    for(int i = 0; i<resultAuthor.size(); i++){
        cout<<resultAuthor[i].getTitle().toStdString()<<"\t";
        cout<<resultAuthor[i].getGenre().toStdString()<<"\t";
        cout<<resultAuthor[i].getFirsName().toStdString()<<"\t";
        cout<<resultAuthor[i].getLastName().toStdString()<<endl;
    }
}

void Library:: saveBookToJsonString(QJsonArray &json)const{
    for(int i = 0; i< ListBook.size(); i++){
        QJsonObject jsonObj;
        jsonObj["First Name"] = ListBook[i].getFirsName();
        jsonObj["Last Name"] = ListBook[i].getLastName();
        jsonObj["Title"] = ListBook[i].getTitle(); //json.setValue("Title",ListBook[i].getTitle());
        jsonObj["Genre"] = ListBook[i].getGenre();
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
