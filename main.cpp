#include <QCoreApplication>
#include "iostream"
#include "book.h"
#include "library.h"
#include "reader.h"
#include "QDate"
#include "menu.h"

using namespace  std;


int main()
{
    Menu menu;
    menu.menu_();

//    Library library;

//    Reader roman("Roman", "Kurtach", 18);
//    roman.addBookAtСard(Reading("20180110", "20180506",0));
//    roman.addBookAtСard(Reading("20150110", "20160506",3));
//    roman.addBookAtСard(Reading("20161210", "20161218",1));
//    roman.booksLastYear("20160101");

//    Reader oleksa("oleksandr", "baza", 19);
//    oleksa.addBookAtСard(Reading("20150110", "20160506",3));
//    oleksa.addBookAtСard(Reading("20161210", "20161218",1));

//    library.addReader(roman);
//    library.addReader(oleksa);

//    library.saveReaderToJsonFile();

//    library.loadReadersFromJsonFile();

//    cout<<library.ListReader[1].getLastName().toStdString()<<endl;
//    cout<<library.ListReader[0].getLastName().toStdString()<<endl;
//    library.ListReader[0].addBookAtСard(Reading("20161210", "20161218",10));
//    library.saveReaderToJsonFile();

//    library.ListReader[1].booksLastYear("20160101");


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
