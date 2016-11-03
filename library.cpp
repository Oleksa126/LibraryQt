#include "library.h"

void Library:: searchByGenre(QString genre){
    vector<Book> resultGenre;
    for(int i = 0; i<ListBook.size(); i++){
        if(ListBook[i].getGenre() == genre/*Ganres[FANTESY]*/){
            resultGenre.push_back(ListBook[i]);
        }
    }

    cout << "\n\n\t\t\t Search books by " << genre.toStdString() << "\n\n";
    for(int i = 0; i<resultGenre.size(); i++){
        cout<<i<<"\t";
        resultGenre[i].showBook();
        cout<<endl;
    }
}

void Library:: searchByAuthor(QString author){
    vector<Book> resultAuthor;
    for(int i = 0; i<ListBook.size(); i++){
        if(ListBook[i].author.getFirstName() == author || ListBook[i].author.getLastName() == author){
            resultAuthor.push_back(ListBook[i]);
        }
    }

    cout << "\n\n\t\t\t Search books by " << author.toStdString() << "\n\n";
    for(int i = 0; i<resultAuthor.size(); i++){
        cout<<i<<"\t";
        resultAuthor[i].showBook();
        cout<<endl;
    }
}

void Library:: saveBookToJsonString(QJsonArray &json)const{
    for(int i = 0; i< ListBook.size(); i++){
        QJsonObject jsonObj;
        jsonObj = ListBook[i].saveBookToJson();
        json.push_back(jsonObj);
    }
}

void Library:: saveBookToJsonFile(){
    QJsonArray json;
    this->saveBookToJsonString(json);
    QJsonDocument doc;
    doc.setArray(json);
    QString result = QString::fromUtf8(doc.toJson(QJsonDocument::Indented));

    QFile inFile("C:/Users/Oleksa/Documents/QW/Books.json");
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

void Library:: loadBooksFromJsonFile(){
    QFile file("C:/Users/Oleksa/Documents/QW/Books.json");
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

void Library:: saveReaderToJsonString(QJsonArray &json)const{
    for(int i = 0; i< ListReader.size(); i++){
        QJsonObject jsonObj;
        jsonObj = ListReader[i].saveReaderToJson();
        json.push_back(jsonObj);
    }
}

void Library:: saveReaderToJsonFile(){
    QJsonArray json;
    this->saveReaderToJsonString(json);
    QJsonDocument doc;
    doc.setArray(json);
    QString result = QString::fromUtf8(doc.toJson(QJsonDocument::Indented));

    QFile inFile("C:/Users/Oleksa/Documents/QW/Readers.json");
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

void Library:: loadReadersFromJsonFile(){
    QFile file("C:/Users/Oleksa/Documents/QW/Readers.json");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        cout<<"Error";
    }
    QJsonDocument doc = QJsonDocument ::fromJson(file.readAll());
    file.close();

    QJsonArray jsonArray = doc.array();
    foreach (QJsonValue jsonReader, jsonArray) {
        ListReader.push_back(Library::readReader(jsonReader.toObject()));
     }
}

Reader Library:: readReader(const QJsonObject &json){
    Reader reader;//(json["FirstName"].toString(), json["LastName"].toString(), json["Age"].toInt());
    QJsonArray jsonArray = json["Book"].toArray();
    foreach (QJsonValue jsonReader, jsonArray) {
        Reading r;
        r.readReading(jsonReader.toObject());
        reader.addBookAtСard(r);
    }
    return reader;
;
}
