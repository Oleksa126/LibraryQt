#ifndef AUTHOR_H
#define AUTHOR_H

#include "QJsonObject"
using namespace std;

class Author
{
private:
    QString FirstName;
    QString LastName;
public:
    Author(){}

    Author(QString firstName, QString lastName){
        setFirstName(firstName);
        setLastName(lastName);
    }

    QJsonObject saveAuthorToJson() const
     {
         QJsonObject jsonObj;
         jsonObj["First Name"] = FirstName;
         jsonObj["Last Name"] = LastName;
         return jsonObj;
     }

    bool operator<(const Author &author)
    {
        return this->getFirstName().operator <( author.getFirstName().toLatin1());
    }

    friend ostream& operator <<(ostream &show, const Author &author){
        QString str = QString("%1 %2")
                .arg(author.getFirstName(),15)
                .arg(author.getLastName(),15);
        show<<str.toStdString()<<endl;
        return show;
    }

    Author readAutorFromJson(const QJsonObject &json){
       return Author (json["First Name"].toString(), json["Last Name"].toString());
    }
    void setFirstName(QString firstName) {
       FirstName = firstName;
    }
    void setLastName(QString lastName) {
       LastName = lastName;
    }

    QString getFirstName() const {
        return FirstName;
    }

    QString getLastName() const {
        return LastName;
    }

    ~Author(){}
};
#endif // AUTHOR_H
