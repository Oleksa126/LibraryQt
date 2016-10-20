#include "library.h"

Library::Library()
{

}

void Library:: searchByGenre(QString genre){
    vector<Book> resultGenre;
    for(int i = 0; i<ListBook.size(); i++){
        if(ListBook[i].getGenre() == genre){
            resultGenre.push_back(ListBook[i]);
            std::cout<<"yes";
        }
        else{cout<<"no";}
    }
}

void Library:: write(QJsonArray &json){
    for(int i = 0; i< ListBook.size(); i++){
        QJsonObject jsonObj;
        jsonObj["Title"] = ListBook[i].getTitle(); //json.setValue("Title",ListBook[i].getTitle());
        jsonObj["Genre"] = ListBook[i].getGenre();
        json.push_back(jsonObj);
    }
}

QString Library:: serialize(){
    QJsonArray json;
    this->write(json);
    QJsonDocument doc;
    doc.setArray(json);
    QString result=QString::fromUtf8(doc.toJson(QJsonDocument::Indented));
    return result;
}

void Library:: writeToFile(QString str){
    QFile inFile("C:/Users/Oleksa/Documents/Library/save.json");
    QTextStream stream(&inFile);
    if(!inFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        cout<<"Error";
    }
    else{
        stream << str;
        stream.flush();
        inFile.close();
    }

}
