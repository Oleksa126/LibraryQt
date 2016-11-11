#include "book.h"

int Book ::counter = 0;

QJsonObject Book :: saveBookToJson()const{
   QJsonObject jsonObj;
       jsonObj = this->author.saveAuthorToJson();
       jsonObj["Title"] = this->getTitle();
       jsonObj["Genre"] = this->getGenre();
       jsonObj["ID"] = this->getID();
   return jsonObj;
}

ostream& operator <<(ostream &show, const Book &book){
    QString str = QString("%1 %2 %3 %4")
            .arg(book.getTitle(),15)
            .arg(book.getGenre(),15)
            .arg(book.author.getFirstName(),15)
            .arg(book.author.getLastName(),15);

    show<<str.toStdString()<<endl;

//    show<<book.getID()<<"\t"<<book.getTitle().toStdString()<<"\t"<<book.getGenre().toStdString()<<"\t"<<book.author.getFirstName().toStdString()<<"\t"<<book.author.getLastName().toStdString()<<endl;
    return show;
}

