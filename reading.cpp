#include "reading.h"

Reading:: Reading(QString whenTook, QString whenReturn,int id){
    setDateTookBook(whenTook);
    setDateReturnBook(whenReturn);
    setBookId(id);
}

QJsonObject Reading:: saveReadingToJson()const{
    QJsonObject json;
    json["TookBook"] = this->getStingDateTookBook();
    json["ReturnBook"] = this->getStringDateReturnBook();
    json["ID"] = this->getBookID();
    return json;
}

void Reading:: readReading(QJsonObject &json){
    this->setBookId(json["ID"].toInt());
    this->setDateReturnBook(json["ReturnBook"].toString());
    this->setDateTookBook(json["TookBook"].toString());
}
