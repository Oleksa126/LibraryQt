#ifndef MENU_H
#define MENU_H
#include <QString>
#include <QDebug>
#include "library.h"
#include"iostream"
using namespace std;

class Menu{
public:
    Library library;

    Menu(){
        library.loadBooksFromJsonFile();
        library.loadReadersFromJsonFile();
    }

    int prompt_menu_item()
    {
        int variant;
        cout << "1. Add reader\n"
             << "2. Add book to reader\n"
             << "3. How many books read\n"
             << "4. Add book\n"
             << "5. Insertion sort book\n"
             << "6. Find books by genre\n"
             << "7. Find books by author\n"
             << "8. Exit\n" << endl;
        cout << ">>> ";
        cin >> variant;
        return variant;
    }

    void menu_(){
        int variant=0;
        do{
            int variant = prompt_menu_item();
            switch (variant){
            case 1:
                addReader();
                system("cls");
                break;
            case 2:
                addBookToReader();
                system("cls");
                break;
            case 3:
                howManyBook();
                system("cls");
                break;
            case 4:
                addBook();
                system("cls");
                break;
            case 5:
                insertionSort();
                system("cls");
                break;
            case 6:
                searchByGenre();
                system("cls");
                break;
            case 7:
                searchByAuthor();
                system("cls");
                break;
            case 8:
                cout << "EXIT" << endl;
                exit(EXIT_SUCCESS);
            default:
                cerr << "You tourch .." << endl;
                exit(EXIT_FAILURE);}
        }while(variant !=8);
    }

    void addReader(){
        string firstName, lastName;
        int age;

        cout << "first name - ";
        cin >> firstName;
        cout << "last name - ";
        cin >> lastName;
        cout << "age - ";
        cin >> age;

        library.addReader(Reader(firstName.c_str(),lastName.c_str(),age));
        library.saveReaderToJsonFile();
    }

    void addBook(){
        string title, genre, firstName, lastName;

        cout<<"Title - ";
        cin>>title;
        //        getline(cin,title);
        //        cin.get();
        cout<<"Genre - ";
        cin>>genre;
        //        getline(cin, genre);
        //        cin.get();

        cout<<"First Name - ";
        cin>>firstName;
        //        getline(cin,firstName);
        //        cin.get();

        cout<<"Last Name - ";
        cin>>lastName;
        //        getline(cin,lastName);
        //        cin.get();

        library.addBook(Book(title.c_str(), genre.c_str(), firstName.c_str(), lastName.c_str()));
        library.saveBookToJsonFile();
    }

    void searchByGenre(){
        vector<QString> genre = {"science", "fantastic", "proza", "periodic", "biography", "child's", "any"};
        int j;
        for(int i = 0; i<genre.size(); i++){
            cout<< i <<" "<<genre[i].toStdString()<<endl;
        }
        cout<< ">>> ";
        cin>>j;
        library.searchByGenre(genre[j]);
        system("pause");
    }

    void searchByAuthor(){
        vector<QString> author;
        for(int i = 0; i<library.ListBook.size(); i++){
            author.push_back(library.ListBook[i].author.getLastName());
        }

        int j;
        for(int i = 0; i<author.size(); i++){
            cout<< i <<" "<<author[i].toStdString()<<endl;
        }
        cout<< ">>> ";
        cin>>j;
        library.searchByAuthor(author[j]);
        system("pause");
    }

    void howManyBook(){
        for(int i = 0; i<library.ListReader.size(); i++){
            cout<<i<<". ";
            cout<<library.ListReader[i].getLastName().toStdString()<<endl;
        }
        int j;
        cout<< ">>> ";
        cin>>j;

        string date;
        cout<<"Date - ";
        cin>>date;

        library.ListReader[j].booksLastYear(date.c_str());

        system("pause");
    }

    void addBookToReader(){
        for(int i = 0; i<library.ListReader.size(); i++){
            cout<<i<<". ";
            cout<<library.ListReader[i].getLastName().toStdString()<<endl;
        }
        int j;
        cout<< ">>> ";
        cin>>j;

        string whenTook, whenReturnBook;
        int id;
        cout<<"When took book - ";
        cin>>whenTook;

        cout<<"When return book - ";
        cin>>whenReturnBook;

        cout<<"Id book ";
        cin>>id;
        library.ListReader[j].addBookAtСard(Reading(whenTook.c_str(), whenReturnBook.c_str(), id));
        library.saveReaderToJsonFile();
    }

    void insertionSort(){
        cout<<"\n before: \n\n";
        cout<<"# \t ID \t Title \t \t Genre \t\t Author \n\n";
        for(int i = 0; i<library.ListBook.size(); i++){
            library.ListBook[i].showBook();
        }

        vector<Book> sortBook;
        sortBook = library.ListBook;
        for(int i = 0; i<sortBook.size();i++){
            for(int j = i; j<sortBook.size();j++){
                if(sortBook[i].getID() < sortBook[j].getID()){
                    Book tmp;
                    tmp = sortBook[i];
                    sortBook[i] = sortBook[j];
                    sortBook[j] = tmp;
                }

            }
        }

        cout<<"\n after: \n\n";
        cout<<"# \t ID \t Title \t \t Genre \t\t Author \n\n";
        for(int  i = 0; i<sortBook.size(); i++){
            sortBook[i].showBook();
        }

        system("pause");
    }

    ~Menu(){}
};



#endif // MENU_H

