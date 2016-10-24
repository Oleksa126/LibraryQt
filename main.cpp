#include <QCoreApplication>
#include "iostream"
#include "book.h"
#include "library.h"
//#include "reader.h"
#include "QDate"

using namespace  std;

int main()
{
//    Book first("Harry potter", "fantasy", "Joan", "Rouling");
//    Book second("farytales","my", "Mark", "Twen");
    Library one;


//    one.addBook(first);
//    one.addBook(second);
//    one.saveBookToJsonFile();



    one.loadFromJsonFile();
    one.show();
    one.searchByGenre("History");
    one.searchByAuthor("Suzanne");



    return 0;
}
