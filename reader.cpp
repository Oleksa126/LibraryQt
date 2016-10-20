#include "reader.h"

Reader::Reader()
{

}

Reader::Reader(QString firstName, QString lastName,int age)
{
    setFirstName(firstName);
    setLastName(lastName);
    setAge(age);
}

Reader::~Reader()
{
}
