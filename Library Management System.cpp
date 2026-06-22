#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    void addBook() {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        issued = false;
    }

    void displayBook() {
        cout << "\nBook ID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: " << (issued ? "Issued" : "Available") << endl;
    }
};

int main() {
    Book books[100];
    int count = 0;
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search by Title\n";
        cout << "4. Search by Author\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {

        case 1:
            books[count].addBook();
            count++;
            cout << "Book Added Successfully!\n";
            break;

        case 2:
            for (int i = 0; i < count; i++) {
                books[i].displayBook();
                cout << endl;
            }
            break;

        case 3: {
            string title;
            cout << "Enter Title to Search: ";
            getline(cin, title);

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (books[i].title == title) {
                    books[i].displayBook();
                    found = true;
                }
            }

            if (!found)
                cout << "Book Not Found!\n";
            break;
        }

        case 4: {
            string author;
            cout << "Enter Author Name to Search: ";
            getline(cin, author);

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (books[i].author == author) {
                    books[i].displayBook();
                    found = true;
                }
            }

            if (!found)
                cout << "Book Not Found!\n";
            break;
        }

        case 5: {
            int id;
            cout << "Enter Book ID to Issue: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (books[i].id == id) {
                    if (!books[i].issued) {
                        books[i].issued = true;
                        cout << "Book Issued Successfully!\n";
                    } else {
                        cout << "Book Already Issued!\n";
                    }
                    found = true;
                }
            }

            if (!found)
                cout << "Book Not Found!\n";
            break;
        }

        case 6: {
            int id;
            cout << "Enter Book ID to Return: ";
            cin >> id;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (books[i].id == id) {
                    if (books[i].issued) {
                        books[i].issued = false;
                        cout << "Book Returned Successfully!\n";
                    } else {
                        cout << "Book Was Not Issued!\n";
                    }
                    found = true;
                }
            }

            if (!found)
                cout << "Book Not Found!\n";
            break;
        }

        case 7:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}
