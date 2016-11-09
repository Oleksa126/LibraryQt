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
    for(int i = 0; i<СardReader.size(); i++){
        if(date.daysTo(СardReader[i].getDateTookBook())>=0 && date.daysTo(СardReader[i].getDateTookBook())<=365 && date.daysTo(СardReader[i].getDateReturnBook())<=365){
           cout<<СardReader[i].getBookID()<<"\t";
        }
    }
}