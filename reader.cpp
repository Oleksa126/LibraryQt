#include "Reader.h"



Reader::Reader(QString firstName, QString lastName)
{
    setFullName(firstName, lastName);
}

Reader::Reader(QString firstName, QString lastName, int age)
{
    setFullName(firstName, lastName);
    setAge(age);
}

void Reader::setFullName(QString firstName, QString lastName)
{
    FirstName = firstName;
    LastName = lastName;
}

void Reader::setAge(int age)
{
    Age = age;
}




Reader::~Reader()
{
}
