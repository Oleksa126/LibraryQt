#include "menu.h"

int Menu:: prompt_menu_item()
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

void Menu:: meinMenu(){
    vector<Book> book = library.ListBook;
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
            insertionSortMenu();
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

void Menu:: addReader(){
    string firstName, lastName;
    int age;

    cin.ignore();

    cout << "first name - ";
    getline(cin,firstName);
    cout << "last name - ";
    getline(cin,lastName);
    cout << "age - ";
    cin >> age;

    library.addReader(Reader(firstName.c_str(),lastName.c_str(),age));
    library.saveReaderToJsonFile();
}

void Menu:: addBook(){
    string title, genre, firstName, lastName;

    cin.ignore();
    cout<<"Title - ";
    getline(cin,title);

    cout<<"Genre - ";
    getline(cin, genre);

    cout<<"First Name - ";
    getline(cin,firstName);

    cout<<"Last Name - ";
    getline(cin,lastName);

    library.addBook(Book(title.c_str(), genre.c_str(), firstName.c_str(), lastName.c_str()));
    library.saveBookToJsonFile();
}

void Menu:: searchByGenre(){
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

void Menu:: searchByAuthor(){
    vector<QString> author;
    for(int i = 0; i<library.ListBook.size(); i++){
        author.push_back(library.ListBook[i].author.getLastName());
    }

    sort(author.begin(), author.end());
   author.erase(unique(author.begin(), author.end()),author.end());

    int j;
    for(int i = 0; i<author.size(); i++){
        cout<< i <<" "<<author[i].toStdString()<<endl;
    }

    cout<< ">>> ";
    cin>>j;
    if(j>author.size()){
        cout<<"please try againe\n";
        system("pause");
        return;
    }
    library.searchByAuthor(author[j]);
    system("pause");
}

void Menu:: howManyBook(){
    for(int i = 0; i<library.ListReader.size(); i++){
        cout<<i<<". ";
        cout<<library.ListReader[i].getLastName().toStdString()<<endl;
    }
    int j;
    cout<< ">>> ";
    cin>>j;

    string date;
    cout<<"Year - ";
    cin>>date;
    date += "0101";
    library.ListReader[j].booksLastYear(date.c_str());
    system("pause");
}

void Menu:: addBookToReader(){
    for(int i = 0; i<library.ListReader.size(); i++){
        cout<<i<<". ";
        cout<<library.ListReader[i].getLastName().toStdString()<<endl;
    }
    int j;
    cout<< ">>> ";
    cin>>j;

    if(j>library.ListReader.size()){
        cout<<"please try againe\n";
        return;
    }
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

void Menu:: insertionSortMenu(){
    vector<Author> author;
    for(int i = 0; i<library.ListBook.size(); i++){
        author.push_back(library.ListBook[i].author);
    }

    int a = 0;
    cout<<"SORT: \n"
        <<"1. Book by Author FirstName \n"
        <<"2. Readers by First Name \n"
        <<"3. Author by FirstName \n";
    cout << ">>> ";
    cin>>a;
    switch(a){
    case 1:
        insertionSort(library.ListBook); //books by author
        break;
    case 2:
        insertionSort(library.ListReader);
        system("cls");
        break;
    case 3:

        insertionSort(author);
    default:
        cerr << "You tourch .." << endl;
        system("cls");
        break;
    }
}
template <class ElementType>
void Menu:: insertionSort(vector<ElementType> &arr){
    cout<<"\n before: \n\n";
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i];
    }
    for(int i = 0; i<arr.size();i++){
        for(int j = i; j<arr.size();j++){
            if(arr[i] < arr[j]){
                ElementType tmp;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    cout<<"\n after: \n\n";

    for(int  i = 0; i<arr.size(); i++){
        cout<<arr[i];
    }
    system("pause");
}
