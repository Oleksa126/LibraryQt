#include <QCoreApplication>
#include "iostream"
#include "book.h"
#include "library.h"
//#include "reader.h"
#include "QDate"

using namespace  std;

int main()
{
    Book first("Harry potter", "fantasy", "Joan", "Rouling");
    Book second("farytales","my", "Mark", "Twen");
    Library library;



    library.addBook(first);
    library.addBook(second);
    library.saveBookToJsonFile();



//    library.loadFromJsonFile();
//    library.searchByGenre("History");
//    library.searchByAuthor("Suzanne");



    return 0;
}
