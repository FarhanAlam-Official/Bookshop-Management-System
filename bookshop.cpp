#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include<cstring>
#include <algorithm>
using namespace std;

void displayHeader()
{
    system("cls");  // Clear the console screen
    system("color 06");  // Change the system font color
    cout << "\t\t\t\t*********************************************************************************************************\n";
    cout << "\t\t\t\t**********************                                                             **********************\n";
    cout << "\t\t\t\t**********************                                                             **********************\n";
    cout << "\t\t\t\t**********************                BOOKSHOP MANAGEMENT SYSTEM                   **********************\n";
    cout << "\t\t\t\t**********************                                                             **********************\n";
    cout << "\t\t\t\t**********************                                                             **********************\n";
    cout << "\t\t\t\t*********************************************************************************************************\n";
}

// Bookshop Class
class bookshope {
public:
    void control_panel();
    void add_book();
    void show_book();
    void check_book();
    void update_book();
    void del_book();
};

// Function to display the menus
void bookshope::control_panel()
{
    system("cls");
    displayHeader();
    cout << "\n\n\t\t\t\t\t\t\t\t\t  **** MAIN MENU **** ";
    cout << "\n\n\t\t\t\t\t=================================================================================================\n";
    cout << "\n\n\t\t\t\t\t\t\t 1. ADD BOOK";
    cout << "\n\n\t\t\t\t\t\t\t 2. DISPLAY BOOKS";
    cout << "\n\n\t\t\t\t\t\t\t 3. CHECK PARTICULAR BOOK";
    cout << "\n\n\t\t\t\t\t\t\t 4. UPDATE BOOK";
    cout << "\n\n\t\t\t\t\t\t\t 5. DELETE BOOK";
    cout << "\n\n\t\t\t\t\t\t\t 6. EXIT";
    cout << "\n\n\t\t\t\t\t=================================================================================================\n";

}

// Function to add book
void bookshope::add_book()
{
    system("cls");
    displayHeader();
    fstream file;
    int no_copy;
    string b_name, a_name, b_id, genre;
    float price;
    cout << "\n\n\t\t\t\t\t\t\t\t **** ADD BOOKS ****";
    cout << "\n\t\t\t\t=================================================================================================\n";
    cout << "\n\n\t\t\t\t Book ID : ";
    cin >> b_id;
    cout << "\n\t\t\t\t Book Name : ";
    cin >> b_name;
    cout << "\n\t\t\t\t Author Name : ";
    cin >> a_name;
    cout << "\n\t\t\t\t Genre : ";
    cin >> genre;
    cout << "\n\t\t\t\t Price Rs. : ";
    cin >> price;
    cout << "\n\t\t\t\t No. of Copies : ";
    cin >> no_copy;

    // Open file in append or output mode
    file.open("book.dat", ios::out | ios::app);
    file << " " << b_id << " " << b_name << " " << a_name << " " << genre << " " << price << " " << no_copy << "\n";
    file.close();
}

// Function to display book
void bookshope::show_book()
{
    system("cls");
    displayHeader();
    ifstream file("book.dat");
    if (!file) {
        cout << "\n\nFile Opening Error!";
        return;
    }

    cout << "\n\n\t\t\t\t\t\t\t\t\t **** All BOOKS ****";
        cout << "\n\t\t\t\t=================================================================================================\n";
    cout << "\n\n\n\n";
    cout << "\t\t\t=======================================================================================================================\n";
    // Set column headers with setw() for proper alignment
    cout <<"\t\t\t"<< setw(10) << left << "Book ID" << "|"
         << setw(30) << left << "Book" << "|"
         << setw(25) << left << "Author" << "|"
         << setw(15) << left << "Genre" << "|"
         << setw(15) << right << "Price" << " |"
         << setw(18) << right << "    No. of Copies"<< endl;
    cout << "\t\t\t=======================================================================================================================\n";

    string b_id, b_name, a_name, genre;
    float price;
    int no_copy;

    // Read and display each record
    while (file >> b_id >> b_name >> a_name >> genre >> price >> no_copy) {
        cout <<"\t\t\t"<< setw(10) << left << b_id << "|"
             << setw(30) << left << b_name << "|"
             << setw(25) << left << a_name << "|"
             << setw(15) << left << genre << "|"
             << setw(10) << right << fixed << setprecision(2) <<" Rs."<< price << "|"
             << setw(18) << right << no_copy << endl;
    }

    cout << "\t\t\t=======================================================================================================================\n";

    file.close();
    system("pause");
}


void bookshope::check_book()
{
    system("cls");
    displayHeader();

    fstream file;
    int count = 0;
    string b_id, b_name, a_name, genre, b_idd;
    int no_copy=0;
    float price;
    bool found = false;

    cout << "\n\n\t\t\t\t\t\t\t **** Check Book Availability ****";
    cout << "\n\t\t\t\t=================================================================================================\n";

    cout << "\n\n\t\t\t\t 1. Search by Book ID";
    cout << "\n\t\t\t\t 2. Search by Genre";
    cout << "\n\t\t\t\t 3. Search by Price Range";
    cout << "\n\t\t\t\t 4. Back to Control Panel";
    cout << "\n\n\t\t\t\t Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "\n\n\t\t\t\t Enter Book ID: ";
            cin >> b_idd;

            // Open the file in input mode
            file.open("book.dat", ios::in);
            if (!file) {
                cout << "\n\nFile Opening Error!";
                system("pause");
                return;
            }

            while (file >> b_id >> b_name >> a_name >> genre >> price >> no_copy) {
                if (b_idd == b_id) {
                    if (!found) {
                        cout << "\n\t\t\t\t=================================================================================================\n";
                        cout << "\n\t\t\t\t\t\t\t **** Available Books ****\n";
                        cout << "\n\t\t\t\t=================================================================================================\n";
                        found = true;
                    }
                    cout << "\n\n\t\t\t\t Book ID       : " << b_id;
                    cout << "\n\t\t\t\t Name          : " << b_name;
                    cout << "\n\t\t\t\t Author        : " << a_name;
                    cout << "\n\t\t\t\t Genre         : " << genre;
                    cout << "\n\t\t\t\t Price     Rs. : " << price;
                    cout << "\n\t\t\t\t No of Books   : " << no_copy;
                    count++;
                }
            }

            if (!found)
                cout << "\n\n\t\t\t\t No books found with the provided Book ID.";

            cout << "\n\t\t\t\t=================================================================================================\n";
            file.close();
            break;
        }

        case 2: {
    string enteredgenre;
    cout << "\n\n\t\t\t\t Enter Genre: ";
    cin >> enteredgenre;

    // Convert entered genre to uppercase
    transform(enteredgenre.begin(), enteredgenre.end(), enteredgenre.begin(), ::toupper);

    // Open the file in input mode
    file.open("book.dat", ios::in);
    if (!file) {
        cout << "\n\nFile Opening Error!";
        system("pause");
        return;
    }

    while (file >> b_id >> b_name >> a_name >> genre >> price >> no_copy) {
        // Convert genre read from file to uppercase
        transform(genre.begin(), genre.end(), genre.begin(), ::toupper);

        if (enteredgenre == genre) {
            if (!found) {
                cout << "\n\t\t\t\t=================================================================================================\n";
                cout << "\n\t\t\t\t\t\t\t **** Available Books ****\n";
                cout << "\n\t\t\t\t=================================================================================================\n";
                found = true;
            }
            cout << "\n\n\t\t\t\t Book ID       : " << b_id;
            cout << "\n\t\t\t\t Name          : " << b_name;
            cout << "\n\t\t\t\t Author        : " << a_name;
            cout << "\n\t\t\t\t Genre         : " << genre;
            cout << "\n\t\t\t\t Price     Rs. : " << price;
            cout << "\n\t\t\t\t No of Books   : " << no_copy;

            count++;
        }
    }

    if (!found)
        cout << "\n\n\t\t\t\t No books found with the provided Genre.";

    cout << "\n\t\t\t\t=================================================================================================\n";
    file.close();
    break;
}

case 3: {
    float min_price, max_price;
    cout << "\n\n\t\t\t\tEnter Minimum Price: ";
    cin >> min_price;
    cout << "\n\n\t\t\t\t Enter Maximum Price: ";
    cin >> max_price;

    // Open the file in input mode
    file.open("book.dat", ios::in);
    if (!file) {
        cout << "\n\nFile Opening Error!";
        system("pause");
        return;
    }

    while (file >> b_id >> b_name >> a_name >> genre >> price >> no_copy) {
        if (price >= min_price && price <= max_price) {
            if (!found) {
                cout << "\n\t\t\t\t=================================================================================================\n";
                cout << "\n\t\t\t\t\t\t\t **** Available Books ****\n";
                cout << "\n\t\t\t\t=================================================================================================\n";
                found = true;
            }
            cout << "\n\n\t\t\t\t Book ID       : " << b_id;
            cout << "\n\t\t\t\t Name          : " << b_name;
            cout << "\n\t\t\t\t Author        : " << a_name;
            cout << "\n\t\t\t\t Genre         : " << genre;
            cout << "\n\t\t\t\t Price     Rs. : " << price;
            cout << "\n\t\t\t\t No of Books  : " << no_copy;

            count++;
        }
    }

    if (!found)
        cout << "\n\n\t\t\t\t No books found within the provided price range.";

    cout << "\n\t\t\t\t=================================================================================================\n";
    file.close();
    break;
}


        case 4: {
            break;
        }

        default: {
            cout << "\n\n\t\t\t\t Invalid choice!! Please Select Proper Choice";
            break;
        }
    }
    cout<<"\n\n\t\t\t\t\t Press any key to return to main menu.....";
    getch();
}
// Function to update the book
void bookshope::update_book()
{
    system("cls");
    displayHeader();
    fstream file, file1;
    int no_copy, no_co, count = 0;
    string b_name, b_na, a_name, a_na, b_idd, b_id, genre;
    float price;

    cout << "\n\n\t\t\t\t\t\t\t\t **** Update Book Record ****";
        cout << "\n\n\t\t\t\t\t =============================================================================================\n";

    file1.open("temp.dat", ios::app | ios::out);
    file.open("book.dat", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else {

        cout << "\n\n\t\t\t\tBook ID : ";
        cin >> b_id;
        file >> b_idd >> b_name;
        file >> a_name >> genre >> price >> no_copy;

        // Till end of file is reached
        while (!file.eof()) {
            if (b_id == b_idd) {
                system("cls");
                displayHeader();
                cout << "\n\t\t\t\t\t\t\t **** Update Book Record ****";
                    cout << "\n\n\t\t\t\t =================================================================================================\n";

                cout<<"\n\n\t\t\t\t Current Book Details:";
                cout <<"\n\n\t\t\t =================================================================================================\n";

                cout << "\n\n\t\t\t\t Book Name : "<<b_name<<endl;
                cout << "\n\t\t\t\t Author Name : "<<a_name<<endl;
                cout << "\n\t\t\t\t Genre : "<<genre<<endl;
                cout << "\n\t\t\t\t Price Rs. : "<<price<<endl;
                cout << "\n\t\t\t\t No. of Books : "<<no_copy<<endl;

                cout <<"\n\n\t\t\t =================================================================================================\n";

                cout << "\n\n\t\t\t\t New Book Name : ";
                cin >> b_na;
                cout << "\n\t\t\t\t Author Name : ";
                cin >> a_na;
                cout << "\n\t\t\t\t Genre : ";
                cin >> genre;
                cout << "\n\t\t\t\t Price Rs. : ";
                cin >> price;
                cout << "\n\t\t\t\t No. of Books : ";
                cin >> no_co;
                file1 << " " << b_id << " " << b_na << " " << a_na << " " << genre << " " << price << " " << no_co << "\n\n";
                count++;
            }
            else
                file1 << " " << b_idd << " " << b_name << " " << a_name << " " << genre << " " << price << " " << no_copy << "\n\n";
            file >> b_idd >> b_name;
            file >> a_name >> genre >> price >> no_copy;
            cout<<"\n\n\t\t\t\t\t\t Records Updated Successfully....";
        }
        if (count == 0)
            cout << "\n\nBook ID Not Found...";
    }
    cout << endl;
    system("pause");

    // Close the files
    file.close();
    file1.close();
    remove("book.dat");
    rename("temp.dat", "book.dat");
}

// Function to delete book
void bookshope::del_book()
{
    system("cls");
    displayHeader();

    fstream file, file1;
    int no_copy, count = 0;
    string b_id, b_idd, b_name, a_name, genre;
    float price;

    cout << "\n\n\t\t\t\t\t\t\t\t **** Delete a Book ****";
    cout << "\n\n\t\t\t\t\t============================================================================================\n";

    // Open input file
    file.open("book.dat", ios::in);

    if (!file) {
        cout << "\n\nFile Opening Error...";
        system("pause");
        return;
    }

    // Open output file
    file1.open("temp.dat", ios::out);

    cout << "\n\n\t\t\t\t Book ID : ";
    cin >> b_id;

    // Read data from the input file
    while (file >> b_idd >> b_name >> a_name >> genre >> price >> no_copy) {
        if (b_id == b_idd) {
            // Book found, display details and ask for confirmation
            system("cls");
            displayHeader();
            count++;
            cout << "\n\n\t\t\t\t\t\t\t\t **** Delete a Book ****";
            cout << "\n\n \t\t\t\t\t=================================================================================================\n";
            cout << "\n\n\t\t\t\t Current Book Details:";
            cout << "\n\n\t\t\t =================================================================================================\n";
            cout << "\n\n\t\t\t\t Book Name : " << b_name << endl;
            cout << "\n\t\t\t\t Author Name : " << a_name << endl;
            cout << "\n\t\t\t\t Genre : " << genre << endl;
            cout << "\n\t\t\t\t Price Rs. : " << price << endl;
            cout << "\n\t\t\t\t No. of Books : " << no_copy << endl;
            cout << "\n\n\t\t\t =================================================================================================\n";

            char confirm;
            ask:
            cout << "\n\n\t\t\t\t Are you sure you want to delete this book? (y/n): ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                cout << "\n\n\t\t\t\t Book is Deleted Successfully...\n\n";
                continue; // Skip writing this book to the output file
            }
            else if(confirm == 'N' || confirm == 'n') {
                cout << "\n\n\t\t\t\t Record was not deleted.\n\n";
            }
            else{
                cout << "\n\n\t\t\t\t Invalid Choice...\n\n";
                goto ask;
            }
        }
        // Write data to the output file
        file1 << b_idd << " " << b_name << " " << a_name << " " << genre << " " << price << " " << no_copy << "\n";
    }

    // Close the files
    file.close();
    file1.close();

    // Remove the original file and rename the temporary file
    remove("book.dat");
    rename("temp.dat", "book.dat");

    if (count == 0) {
        cout << "\n\n\t\t\t\t Book ID Not Found...\n";
    }

    system("pause");
}

// Function for book shop record
void bookShopRecord()
{
    int choice;
    char x;
    bookshope b;

    while (1) {

        b.control_panel();
        cout << "\n\n\t\t\t\t\t\t Enter your choice : ";
        cin >> choice;
        switch (choice) {

        case 1:
            do {

                b.add_book();
                cout << "\n\n\t\t\t\t Want to add another book? (y/n) : ";
                cin >> x;
            } while (x == 'y');
            break;

        case 2:
            b.show_book();
            break;

        case 3:
            b.check_book();
            break;
        case 4:
            b.update_book();
            break;

        case 5:
            b.del_book();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "\n\nINVALID CHOICE\n";
        }
    }
}

void welcome() {
    system("color 06");
    system("cls");
    displayHeader();
    cout << "\v\v\v\v\v";
    cout << "\t\t\t\t\t\t\t\t            WELCOME   \v\v";
    cout << "\t\t\t\t\t\t\t\t              TO      \v\v";
    cout << "\t\t\t\t\t\t\t      BOOKSHOP MANAGEMENT APPLICATION \v\v";
    cout << "\t\t\t\t\t\t\t\t          APPLICATION \n";
    cout << "\n\t\t\t\t\t\t\t=======================================================\n";

    cout << "\n\t\t\t\t\t\t\t\t        -Together We Learn";
    cout << "\n\n\n\n\t\t\t\t     Press any key to continue....";
    getch();
}

bool login() {
    const string username = "admin";
    const string password = "password";
    string enteredUsername, enteredPassword;
    int attempts = 3;

    while (attempts > 0) {
        system("cls");
        displayHeader();
        cout << "\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t\t **** LOGIN PAGE ****\n";
    cout << "\n\t\t\t\t=================================================================================================\n";
        cout << "\n\n\t\t\t\t Username: ";
        cin >> enteredUsername;
        cout << "\n\n\t\t\t\t Password: ";
        cin >> enteredPassword;

        if (enteredUsername == username && enteredPassword == password) {
            return true; // Successful login
        } else {
            cout << "\n\t\t\t\tInvalid username or password. Please try again.\n";
            attempts--;
            cout << "\n\t\t\t\tYou have " << attempts << " attempts remaining.\n";
            cout << "\t\t\t\t\t\t Press any key to continue...";
            getch();
        }
    }

    cout << "\n\t\t\t\tYou have exceeded the maximum number of login attempts.\n";
    cout << "\t\t\t\tExiting program...\n";
    return false; // Failed to login after three attempts
}

// Driver Code
int main() {
    welcome();

    int option = 0;
    if (login()) {
        // If login successful, display menu and perform operations
        cout << "\n\t\t\t\t\t\t\t Login successful !!!";
        cout<<"\n\n\t\t\t\tPress any key to continue...";
        getch();
        bookShopRecord();
    } else {
        // If login failed, exit the program
        exit(EXIT_FAILURE);
    }

    return 0;
}
