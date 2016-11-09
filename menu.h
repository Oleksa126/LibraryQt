#ifndef MENU_H
#define MENU_H
#include <QString>
#include <QDebug>
#include "library.h"
#include "iostream"
using namespace std;

class Menu{
public:
    Library library;

    Menu(){
        library.loadBooksFromJsonFile();
        library.loadReadersFromJsonFile();
    }

    int prompt_menu_item();

    void meinMenu();

    void addReader();

    void addBook();

    void searchByGenre();

    void searchByAuthor();

    void howManyBook();

    void addBookToReader();

    template <class ElementType>
    void insertionSort(vector<ElementType> &arr);
    ~Menu(){}
};



#endif // MENU_H

