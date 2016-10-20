#include <QCoreApplication>
#include "iostream"
#include "book.h"
#include "library.h"
#include "reader.h"


using namespace  std;

int main()
{
    Book first("Harry potter", "fantasy");
    Book second("farytales","my");

    Library one;
    one.addBook(first);
    one.addBook(second);

    QString a = one.serialize();
    //cout<<a.toStdString();

    one.writeToFile(a);
    return 0;
}
