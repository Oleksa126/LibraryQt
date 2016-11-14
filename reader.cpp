#include "reader.h"

Reader:: Reader(QString firstName, QString lastName,int age){
    setFirstName(firstName);
    setLastName(lastName);
    setAge(age);
}

QJsonObject Reader:: saveReaderToJson() const{
    QJsonObject jsonObj;
    QJsonArray jsonArray;
    for(int i = 0; i<СardReader.size(); i++){
        jsonArray.append(this->СardReader[i].saveReadingToJson());
    }
    jsonObj["Book"] = jsonArray;
    jsonObj["FirstName"] = this->getFirstName();
    jsonObj["LastName"] = this->getLastName();
    jsonObj["Age"] = this->getAge();
    return jsonObj;
}

void Reader:: booksLastYear(QString date){
    QDate one = QDate::fromString(date,"yyyyMd");
    booksLastYear(one);
}

void Reader:: booksLastYear(){
    booksLastYear(QDate::currentDate());
}

void Reader:: booksLastYear(QDate date){
    vector<Reading>reader;
    for(int i = 0; i<СardReader.size(); i++){
        if(date.daysTo(СardReader[i].getDateTookBook())>=0 && date.daysTo(СardReader[i].getDateTookBook())<=365 && date.daysTo(СardReader[i].getDateReturnBook())<=365){
            reader.push_back(СardReader[i]);
        }
    }

    if(reader.empty()){cout<<this->getLastName().toStdString() <<" do not read book in "<<date.toString("yyyy").toStdString()<<endl;}
    else{cout<<this->getLastName().toStdString()<<" read - "<<reader.size()<<" books in "<<date.toString("yyyy").toStdString()<<endl;}
}

ostream& operator <<(ostream &show, const Reader &reader){
    QString str = QString("%1 %2 %3").arg(reader.getFirstName(),15).arg(reader.getLastName(),15).arg(reader.getAge(),15);
    show<<str.toStdString()<<endl;
    //show<<reader.getFirstName().toStdString()<<"\t"<<reader.getLastName().toStdString()<<"\t"<<reader.getAge()<<endl;
    return show;
}
