/*
ADDRESSBOOK
Author: Yutong Wang
Date: 2024-03-13
Purpose: create addressbook in console
Misc.:*/

#include <windows.h>  //includes library for built-in windows functions

#include <algorithm>  //includes library for algorithm functions
#include <cctype>     //includes cctype library
#include <iostream>   //includes library for input and output
#include <string>     //includes library for string functions
#include <vector>     //includes vector library

using namespace std;  // uses names for variables and object from standard library

void wrong();               // declares function as  void, no return value
void contact_display(int);  // delcares function  with parameter int, takes an integer as argument

vector<string> name;     // declares  a vector of strings called "name" to store
vector<string> address;  // declares a vector of strings called "address" to store
vector<string> city;     // declares a vector of strings called "city" to store
vector<string> postal;   // declares a vector of strings called "postal" to store
vector<string> phone;    // declares a vector of strings  called "phone" to store

int main() {  // starts program

    bool errorflag, similar;                                                          // declares bool variables
    int action, choice, choice1;                                                      // declares int variables
    string temp_name, temp_address, temp_city, temp_postal, temp_phone, temp_phone1;  // delares string variables
    size_t found;                                                                     // declares  variable for finding substring in string

    do {  // start do-while loop

        do {  // start do-while loop

            cout << R"(    // Output raw string literal for ASCII art
                .-.					            .-.
                | |					            | |
		| |					            | |
		| |					            | |
		| |					            | |
		| |					            | |
                | |					            | |
                | |					            | |
                | |					            | |
     _.--"""""""--;_					 _.--"""""""--;_
    //             \\					//             \\
    ||   .-"""-.   ||					||   .-"""-.   ||
    ||  /  ...  \  ||					||  /  ...  \  ||
    || |  :::::  | ||					|| |  :::::  | ||
    ||  \  '''  /  ||					||  \  '''  /  ||
    ||   '-...-'   ||					||   '-...-'   ||
    |/.-----------.\|					|/.-----------.\|
    ||.-"""""""""-.||					||.-"""""""""-.||
    |||___________|||					|||___________|||
    ||[__][___][__]||					||[__][___][__]||
    ||=== ===== ===||					||=== ===== ===||
    |\  ===   ===  /|					|\  ===   ===  /|
    | `'""""""""""` |					| `'""""""""""` |
    |[TALK] === === |	what would you like to do?    	|[TALK] === === |
    |.---..---..---.|					|.---..---..---.|
    ||_1_||_2_||_3_||	(1)	add a contact		||_1_||_2_||_3_||
    |.---..---..---.|	(2)	display contacts	|.---..---..---.|
    ||_4_||_5_||_6_||	(3)	search for a contact	||_4_||_5_||_6_||
    |.---..---..---.|	(4)	edit a contact		|.---..---..---.|
    ||_7_||_8_||_9_||	(5)	remove a contact	||_7_||_8_||_9_||
    |.---..---..---.|	(6)	exit			|.---..---..---.|
    ||_*_||_0_||_#_||					||_*_||_0_||_#_||
    |____ _____ ____|					|____ _____ ____|
    |==== ===== ====|					|==== ===== ====|
    |====  ___  ====|					|====  ___  ====|
    |   .'`   `'.   |					|   .'`   `'.   |
    |  /  .:::.  \  |					|  /  .:::.  \  |
    \ '  {CASIO}  ' /					\ '  {CASIO}  ' /
     `--.........--'					 `--.........--'
)";  // outputs as a raw string

            cout << "\n\nenter your choice: ";  // Output prompt
            cin >> action;                      // Input user action

            if (action < 1 || action > 6) {  // run if statement to check input
                wrong();                     // Output error message
            }                                // close if statement

        } while (action < 1 || action > 6);  // Repeat until a valid input is received

        if (action == 6) {  // if statement breaks menu loop

            break;  // break

        }  // closes if statement

        else if (action == 1) {  // runs else if

            do {  // runs do-while loop

                system("cls");                                      // clears console
                cout << "\n\n********\tadd contact\t********\n\n";  // outputs message

                do {  // runs do-while loop

                    cin.ignore();  // ignores any excess strings to  prevent crashing from extra inputs

                    cout << "\nname: ";       // prompts user
                    getline(cin, temp_name);  // Input user name

                    for (int i = 0; i < (temp_name.length() - 1); i++) {  // runs for loop

                        if (isdigit(temp_name.at(i))) {  // error check if statement

                            errorflag = true;                            // assigns  the boolean variable "errorflag" to true
                            wrong();                                     // calls to wrong(); function
                            cout << "press enter to try again . . .\n";  // outputs message
                            break;                                       // break

                        }  // closes if statement

                        else {                  // runs else
                            errorflag = false;  // assigns  the boolean variable "errorflag" to false
                        }                       // closes else

                    }  // closes for loop

                } while (errorflag);  // Repeat until a valid input is received

                transform(temp_name.begin(), temp_name.end(), temp_name.begin(), ::toupper);  // uses  C++ algorithm library to convert all letters in string to uppercase

                do {  // runs do-while

                    cout << "\naddress: ";       // prompts user
                    getline(cin, temp_address);  // Input user address

                    for (int i = 0; i < (temp_address.length() - 1); i++) {  // runs for loop

                        if (isdigit(temp_address.at(i))) {  // error check if statement

                            errorflag = true;                            // assigns  the boolean variable "errorflag" to true
                            wrong();                                     // calls to wrong(); function
                            cout << "press enter to try again . . .\n";  // outputs message
                            break;                                       // break

                        }  // closes if statement

                        else {                  // runs else
                            errorflag = false;  // assigns  the boolean variable "errorflag" to false
                        }                       // closes else

                    }  // closes for loop

                } while (errorflag);  // Repeat until a valid input is received

                do {  // runs do-while loop

                    cout << "\ncity: ";       // prompts user
                    getline(cin, temp_city);  // Input user city

                    for (int i = 0; i < (temp_city.length() - 1); i++) {  // runs for loop

                        if (isdigit(temp_city.at(i))) {  // error check if statement

                            errorflag = true;                            // assigns  the boolean variable "errorflag" to true
                            wrong();                                     // calls to wrong(); function
                            cout << "press enter to try again . . .\n";  // outputs message
                            break;                                       // break

                        }  // closes if statement

                        else {                  // runs else
                            errorflag = false;  // assigns  the boolean variable "errorflag" to false
                        }                       // closes else

                    }  // closes for loop

                } while (errorflag);  // Repeat until a valid input is received

                do {  // runs do-while loop

                    cout << "\npostal code: ";  // prompts user
                    getline(cin, temp_postal);  // Input user postal code

                    if (temp_postal.length() != 6) {  // error check if statement

                        wrong();  // calls to wrong(); function

                    }  // closes if statement

                } while (temp_postal.length() != 6);  // Repeat until a valid input is received

                do {  // runs do-while loop

                    cout << "\nphone number: ";  // prompts user
                    getline(cin, temp_phone);    // Input user phone number

                    found = temp_phone.find_first_not_of("0123456789-");  // finds first non-numeric character in string

                    if (found != string::npos) {  // error check if statement

                        wrong();  // calls to wrong(); function

                    }  // closes if statement

                } while (found != string::npos);  // Repeat until a valid input is received

                name.push_back(temp_name);        // adds temp_name to end of vector
                address.push_back(temp_address);  // adds temp_address to end of vector
                city.push_back(temp_city);        // adds temp_city to end of vector
                postal.push_back(temp_postal);    // adds temp_postal to end of vector
                phone.push_back(temp_phone);      // adds temp_phone to end of vector

                cout << "\n\ncontact added successfully\n";  // outputs message

                cout << "\n\nadd another contact? (1 for yes, 0 for no): ";  // prompts user
                cin >> choice1;                                              // Input user choice

                if (choice1 != 1 && choice1 != 0) {  // error check if statement

                    wrong();  // calls to wrong(); function

                }  // closes if statement

            } while (choice1 == 1);  // Repeat until a valid input is received

        }  // closes if statement

        else if (action == 2) {  // runs else if

            do {  // runs do-while loop

                system("cls");                                          // clears console
                cout << "\n\n********\tdisplay contact\t********\n\n";  // outputs message

                for (int i = 0; i < name.size(); i++) {  // runs for loop

                    cout << "\ncontact " << i + 1 << ":\n";  // outputs message
                    cout << "\nname: " << name[i];           // outputs name from vector
                    cout << "\naddress: " << address[i];     // outputs address from vector
                    cout << "\ncity: " << city[i];           // outputs city from vector
                    cout << "\npostal code: " << postal[i];  // outputs postal from vector
                    cout << "\nphone number: " << phone[i];  // outputs phone from vector

                }  // closes for loop

                cout << "\n\nwould you like to return to menu? (1 for yes, 0 for no): ";  // prompts user
                cin >> choice;                                                            // Input user choice

                if (choice != 1 && choice != 0) {  // error check if statement

                    wrong();  // calls to wrong(); function

                }  // closes if statement

            } while (choice != 1);  // Repeat until a valid input is received

        }  // closes else if statement

        else if (action == 3) {  // runs else if

            system("cls");                                         // clears console
            cout << "\n\n********\tsearch contact\t********\n\n";  // outputs message

            cout << "\nenter name: ";  // prompts user
            cin.ignore();              // ignores any excess strings to  prevent crashing from extra inputs
            getline(cin, temp_name);   // Input user name

            transform(temp_name.begin(), temp_name.end(), temp_name.begin(), ::toupper);  // uses  C++ algorithm library to convert all letters in string to uppercase

            similar = false;  // assigns  the boolean variable "similar" to false

            for (int i = 0; i < name.size(); i++) {  // runs for loop

                if (temp_name == name[i]) {  // checks if temp_name is equal to a name in the vector

                    cout << "\ncontact found:\n";            // outputs message
                    cout << "\nname: " << name[i];           // outputs name from vector
                    cout << "\naddress: " << address[i];     // outputs address from vector
                    cout << "\ncity: " << city[i];           // outputs city from vector
                    cout << "\npostal code: " << postal[i];  // outputs postal from vector
                    cout << "\nphone number: " << phone[i];  // outputs phone from vector
                    similar = true;                          // assigns  the boolean variable "similar" to true

                }  // closes if statement

            }  // closes for loop

            if (!similar) {  // runs if statement if not found

                cout << "\n\ncontact not found";  // outputs message

            }  // closes if statement

            cout << "\n\nwould you like to return to menu? (1 for yes, 0 for no): ";  // prompts user
            cin >> choice;                                                            // Input user choice

            if (choice != 1 && choice != 0) {  // error check if statement

                wrong();  // calls to wrong(); function

            }  // closes if statement

        }  // closes else if statement

        else if (action == 4) {  // runs else if

            system("cls");                                       // clears console
            cout << "\n\n********\tedit contact\t********\n\n";  // outputs message

            cout << "\nenter name: ";  // prompts user
            cin.ignore();              // ignores any excess strings to  prevent crashing from extra inputs
            getline(cin, temp_name);   // Input user name

            transform(temp_name.begin(), temp_name.end(), temp_name.begin(), ::toupper);  // uses  C++ algorithm library to convert all letters in string to uppercase

            similar = false;  // assigns  the boolean variable "similar" to false

            for (int i = 0; i < name.size(); i++) {  // runs for loop

                if (temp_name == name[i]) {  // checks if temp_name is equal to a name in the vector

                    cout << "\ncontact found:\n";            // outputs message
                    cout << "\nname: " << name[i];           // outputs name from vector
                    cout << "\naddress: " << address[i];     // outputs address from vector
                    cout << "\ncity: " << city[i];           // outputs city from vector
                    cout << "\npostal code: " << postal[i];  // outputs postal from vector
                    cout << "\nphone number: " << phone[i];  // outputs phone from vector

                    cout << "\n\nis this the contact you want to edit? (1 for yes, 0 for no): ";  // prompts user
                    cin >> choice;                                                                // Input user choice

                    if (choice != 1 && choice != 0) {  // error check if statement

                        wrong();  // calls to wrong(); function

                    }  // closes if statement

                    else if (choice == 1) {  // runs else if statement

                        cout << "\n\n********\tedit contact\t********\n\n";  // outputs message

                        cout << "\nname: ";       // prompts user
                        cin.ignore();             // ignores any excess strings to  prevent crashing from extra inputs
                        getline(cin, temp_name);  // Input user name

                        transform(temp_name.begin(), temp_name.end(), temp_name.begin(), ::toupper);  // uses  C++ algorithm library to convert all letters in string to uppercase

                        do {  // runs do-while loop

                            cout << "\naddress: ";       // prompts user
                            getline(cin, temp_address);  // Input user address

                            for (int i = 0; i < (temp_address.length() - 1); i++) {  // runs for loop

                                if (isdigit(temp_address.at(i))) {  // error check if statement

                                    errorflag = true;                            // assigns  the boolean variable "errorflag" to true
                                    wrong();                                     // calls to wrong(); function
                                    cout << "press enter to try again . . .\n";  // outputs message
                                    break;                                       // break

                                }  // closes if statement

                                else {                  // runs else
                                    errorflag = false;  // assigns  the boolean variable "errorflag" to false
                                }                       // closes else

                            }  // closes for loop

                        } while (errorflag);  // Repeat until a valid input is received

                        do {  // runs do-while loop

                            cout << "\ncity: ";       // prompts user
                            getline(cin, temp_city);  // Input user city

                            for (int i = 0; i < (temp_city.length() - 1); i++) {  // runs for loop

                                if (isdigit(temp_city.at(i))) {  // error check if statement

                                    errorflag = true;                            // assigns  the boolean variable "errorflag" to true
                                    wrong();                                     // calls to wrong(); function
                                    cout << "press enter to try again . . .\n";  // outputs message
                                    break;                                       // break

                                }  // closes if statement

                                else {                  // runs else
                                    errorflag = false;  // assigns  the boolean variable "errorflag" to false
                                }                       // closes else

                            }  // closes for loop

                        } while (errorflag);  // Repeat until a valid input is received

                        do {  // runs do-while loop

                            cout << "\npostal code: ";  // prompts user
                            getline(cin, temp_postal);  // Input user postal code

                            if (temp_postal.length() != 6) {  // error check if statement

                                wrong();  // calls to wrong(); function

                            }  // closes if statement

                        } while (temp_postal.length() != 6);  // Repeat until a valid input is received

                        do {  // runs do-while loop

                            cout << "\nphone number: ";  // prompts user
                            getline(cin, temp_phone);    // Input user phone number

                            found = temp_phone.find_first_not_of("0123456789-");  // finds first non-numeric character in string

                            if (found != string::npos) {  // error check if statement

                                wrong();  // calls to wrong(); function

                            }  // closes if statement

                        } while (found != string::npos);  // Repeat until a valid input is received

                        name[i] = temp_name;        // replaces name in vector with temp_name
                        address[i] = temp_address;  // replaces address in vector with temp_address
                        city[i] = temp_city;        // replaces city in vector with temp_city
                        postal[i] = temp_postal;    // replaces postal in vector with temp_postal
                        phone[i] = temp_phone;      // replaces phone in vector with temp_phone

                        cout << "\n\ncontact edited successfully\n";  // outputs message

                    }  // closes else if statement

                    similar = true;  // assigns  the boolean variable "similar" to true

                }  // closes if statement

            }  // closes for loop

            if (!similar) {  // runs if statement if not found

                cout << "\n\ncontact not found";  // outputs message

            }  // closes if statement

            cout << "\n\nwould you like to return to menu? (1 for yes, 0 for no): ";  // prompts user
            cin >> choice;                                                            // Input user choice

            if (choice != 1 && choice != 0) {  // error check if statement

                wrong();  // calls to wrong(); function

            }  // closes if statement

        }  // closes else if statement

        else if (action == 5) {  // runs else if

            system("cls");                                         // clears console
            cout << "\n\n********\tremove contact\t********\n\n";  // outputs message

            cout << "\nenter name: ";  // prompts user
            cin.ignore();              // ignores any excess strings to  prevent crashing from extra inputs
            getline(cin, temp_name);   // Input user name

            transform(temp_name.begin(), temp_name.end(), temp_name.begin(), ::toupper);  // uses  C++ algorithm library to convert all letters in string to uppercase

            similar = false;  // assigns  the boolean variable "similar" to false

            for (int i = 0; i < name.size(); i++) {  // runs for loop

                if (temp_name == name[i]) {  // checks if temp_name is equal to a name in the vector

                    name.erase(name.begin() + i);        // erases name in vector
                    address.erase(address.begin() + i);  // erases address in vector
                    city.erase(city.begin() + i);        // erases city in vector
                    postal.erase(postal.begin() + i);    // erases postal in vector
                    phone.erase(phone.begin() + i);      // erases phone in vector

                    cout << "\n\ncontact removed successfully\n";  // outputs message
                    similar = true;                                // assigns  the boolean variable "similar" to true
                    break;                                         // break

                }  // closes if statement

            }  // closes for loop

            if (!similar) {  // runs if statement if not found

                cout << "\n\ncontact not found";  // outputs message

            }  // closes if statement

            cout << "\n\nwould you like to return to menu? (1 for yes, 0 for no): ";  // prompts user
            cin >> choice;                                                            // Input user choice

            if (choice != 1 && choice != 0) {  // error check if statement

                wrong();  // calls to wrong(); function

            }  // closes if statement

        }  // closes else if statement

    } while (action != 6);  // Repeat until action is 6

    return 0;  // returns 0
}  // closes main()

void wrong() {  // declares function as  void, no return value

    system("cls");                           // clears console
    cout << "\n\nINVALID INPUT";             // outputs message
    cout << "\nplease try again . . .\n\n";  // outputs message
}  // closes void wrong()
