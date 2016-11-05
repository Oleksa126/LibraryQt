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
             << "2. Add book\n"
             << "3. find books by genre\n"
             << "4. find books by author \n"
             << "5. how many books read .....\n"
             << "6. Help\n"
             << "7. Exit\n" << endl;
        cout << ">>> ";
        cin >> variant;
        return variant;
     }

    void menu_(){
        int variant = prompt_menu_item();
        //do{
        switch (variant){
             case 1:
                cout << "\t\t\t\t Add reader \n" ;
                addReader();
                break;
             case 2:
                addBook();
                break;
             case 3:
                searchByGenre();
                break;
             case 4:
                searchByAuthor();
                break;
             case 5:
                howManyBook();
                break;
             case 6:
                cout << "Help" << endl;
                break;
             case 7:
                cout << "EXIT" << endl;
                exit(EXIT_SUCCESS);
                break;
             default:
                cerr << "You tourch .." << endl;
                exit(EXIT_FAILURE);}
        //}while(variant !=7);

    }

    void addReader(){
        QTextStream qtin(stdin);
        QString line = qtin.readLine();

        QString firstName, lastName;
        int age;

        cout << "first name - ";
        qtin >> firstName;
        cout << "last name - ";
        qtin >> lastName;
        cout << "age - ";
        qtin >> age;

        library.addReader(Reader(firstName,lastName,age));
    }

    void addBook(){
        string title, genre, firstName, lastName;

        cout<<"Title - ";
        getline(cin,title);
        cin.get();

        cout<<"Genre - ";
        getline(cin, genre);
        cin.get();

        cout<<"First Name - ";
        getline(cin,firstName);
        cin.get();

        cout<<"Last Name - ";
        getline(cin,lastName);
        cin.get();

        library.addBook(Book(title.c_str(), genre.c_str(), firstName.c_str(), lastName.c_str()));
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
    }

    void howManyBook(){
//        vector<QString> readers;
        for(int i = 0; i<library.ListReader.size(); i++){
//            readers.push_back(library.ListReader[i].getLastName());
            cout<<i<<". ";
            cout<<library.ListReader[i].getLastName().toStdString()<<endl;
        }
        int j;
        cout<< ">>> ";
        cin>>j;

        string date;
        cout<<"date - ";
        cin>>date;
        library.ListReader[j].booksLastYear(date.c_str());
    }
    ~Menu(){
        library.saveBookToJsonFile();
        library.saveReaderToJsonFile();
    }
};



#endif // MENU_H

