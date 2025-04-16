#include <iostream>

#define BOOK_LIMIT 50 // New way of defining constants learnt in class

using namespace std;

class Book
{
private:
    //private member variables that allow restrict access
    string title;
    string author;
    string isbn;
    double price;
public:
    //The constructor which allows empty books
    Book(string t = "", string a ="", string i ="", double p=0.0)
    {
        title = t;
        author = a;
        isbn = i;
        price = p;
    }

    //The getters
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    string getIsbn()
    {
        return isbn;
    }
    double getPrice()
    {
        return price;
    }

    // The setters
    void setTitle(string t)
    {
        title = t;
    }
    void setAuthor(string a)
    {
        author = a;
    }
    void setIsbn(string i)
    {
        isbn = i;
    }
    void setPrice(double p)
    {
        price = p;
    }

    //member function for displaying the items
    void display()
    {
        cout << endl << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Price: " << price << endl;
    }
};

class Library
{
private:
    Book books[BOOK_LIMIT];
    int counter = 0;

public:
    // Member function for adding the books
    void addBook()
    {
        if(counter >= BOOK_LIMIT)
        {
            cout << "Library is full!" << endl;
            return;
        }

        string title, author, isbn;
        double price;

        cin.ignore();
        cout << "Enter the title of the book: ";
        getline(cin,title);
        cout << "Enter the author of the book: ";
        getline(cin,author);
        cout << "Enter the isbn of the book: ";
        getline(cin,isbn);
        cout << "Enter the price of the book: ";
        cin >> price;

        books[counter] = Book(title, author, isbn, price);
        counter++;

        cout << "Book added successfully!" << endl;
    }

    // DIsplay all the books available in the Library
    void displayAll()
    {
        if (counter == 0)
        {
            cout << "No book available."<< endl;
            return;
        }

        cout << endl << "Books available" << endl;
        for(int i = 0; i < BOOK_LIMIT; i++)
        {
            books[i].display();
        }
    }

void deleteABook()
{
    if(counter == 0)
        {
            cout<<"Sorry. No book to delete."<<endl;
            return;
        }
    string isbnToBeDeleted;
    cout << "Enter the isbn: ";
    cin.ignore();//to ignore previous newline character
    getline(cin,isbnToBeDeleted);

    bool found = false;
    for(int i = 0; i < counter; i++)
    {
        if(books[i].getIsbn() == isbnToBeDeleted)
        {
            for(int j = i; j < counter - 1; j++)
            {
                books[j] = books[j + 1];
            }
            counter--;
            found = true;
            cout<<"Book successfully removed!!"<<endl;
            break;
        }
    }
        if(!found)
        {
            cout<<"Book with the ISBN "<<isbnToBeDeleted<<" not found!!"<<endl;
        }
    }


};


int main()
{
    //lib object created from the Library class
    Library lib;
    int choice;
    //simple do while loop that will always run and help display
    do
    {
        cout << "Welcome to the Library Book Store." <<endl <<endl;
        cout << "Please select an option" <<endl;
        cout << "1. Add Book" <<endl;
        cout << "2. Display all books" <<endl;
        cout << "3. Search for book" << endl;
        cout << "4. Delete book" <<endl;
        cout << "5. Edit book title" <<endl;
        cout << "6. Exit" <<endl;
        cout << "Response => ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                lib.addBook();
                break;
            }
            case 2:
            {
                lib.displayAll();
                break;
            }
            case 3:
            {
                lib.searchBook();
                break;
            }
            case 4:
            {
                lib.deleteABook();
                break;
            }
            case 5:
            {
                //
               break;
            }
            case 6:
            {
                cout << "Thank you for using the program." << endl;
                break;
            }
            default:
            {
                cout << "Invalid option.Please try again.";
                break;
            }
        }
    }
    while(choice != 6);
}
