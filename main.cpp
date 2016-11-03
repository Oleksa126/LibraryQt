#include <QCoreApplication>
#include "iostream"
#include "book.h"
#include "library.h"
#include "reader.h"
#include "QDate"

using namespace  std;

int main()
{
    Library library;
    library.loadBooksFromJsonFile();


//    Reader oleksa("Oleksandr", "Bazavlyk", 19);
//    oleksa.addBookAtСard(Reading("20180110", "20180506",0));
//    oleksa.addBookAtСard(Reading("20160110", "20160506",1));
//    library.addReader(oleksa);

//    library.saveReaderToJsonFile();

    library.loadReadersFromJsonFile();

    cout<<"Reader - "<<library.ListReader.empty()<<endl;
    cout<<"Book - "<<library.ListBook.empty()<<endl;

//    cout<<library.ListReader[0].getFirstName().toStdString()<<"\t";
//    cout<<library.ListReader[0].getLastName().toStdString()<<"\t";

    return 0;
}








//    Book first("Harry potter", "fantasy", "Joan", "Rouling");
//    Book second("farytales","my", "Mark", "Twen");
//    Book one("farmndfsaytales","mfvnady", "Mark", "Twen");

//    library.addBook(first);
//    library.addBook(second);
//    library.addBook(one);

//    library.saveBookToJsonFile();


//    library.loadBooksFromJsonFile();
//    library.searchByGenre("fantasy");
//    library.searchByAuthor("Mark");
