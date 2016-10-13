#include "Author.h"
#include "iostream"
#include "fstream"

using json = nlohmann::json;


Author::Author(QString fullName)
{
    setFullName(fullName);
}

Author::Author(QString fullName, vector<Book> book)
{
    setFullName(fullName);
    setListBook(book);
}


//void Author::write(Author author)
//{
//	json j;
//	ifstream file("authorAndHisBook.json");
//	j["FullName"] = author.getFullName();
//
//	for (int i = 0; i < author.getListBook().size(); i++) {
//		j["Genre"] = author.getListBook()[i].getGenre();
//		j["Title"] = author.getListBook()[i].getTitle();
//	}
//}


Author::~Author()
{
}

