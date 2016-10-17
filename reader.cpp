#include "Reader.h"

Reader::Reader()
{

}

Reader::Reader(QString firstName, QString lastName,int age, vector<Book> book)
{
    setFirstName(firsName);
    setLastName(lastName);
    setAge(age);
    ListBook = book;
}

Reader::~Reader()
{
}
