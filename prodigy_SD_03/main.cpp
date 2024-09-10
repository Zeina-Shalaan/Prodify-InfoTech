#include <iostream>
#include <string>
using namespace std;

const int MAX_CONTACTS = 100;

struct Contact
{
    string name;
    string phoneNum;
    string email;
};

void addContact ( Contact contats[],int& contactCount)
{
    if(contactCount >= MAX_CONTACTS)
    {
        cout << "Contact list is full..";
        return ;
    }

    cout << "Enter name : ";
    getline (cin,contats[contactCount].name);

    cout << "Enter phone address : ";
    cin >> contats[contactCount].phoneNum;

    cout <<"Enter email address : ";
    cin >> contats[contactCount].email;
    contactCount++;
    cout <<"Enter Contact added successfully"<<endl;
}
void ViewContact(const Contact contats[],int& contactCount)
{
    if (contactCount == 0)
    {
        cout << "no contact available \n";
        return ;
    }


    for (int i =0; i < contactCount;i++)
    {
        cout << "\n  Contact # " << i+1 << " : \n";
        cout << "name " << contats[i].name << endl;
        cout << "phone number " << contats[i].phoneNum<<endl;
        cout << " email address "<< contats[i].email<<endl;
    }
}

void Edit ( Contact contats[],int contactCount)
{
    if (contactCount == 0)
    {
        cout << "No contact to show "<<endl;
        return;
    }

    int index;
    ViewContact(contats,contactCount);
    cout << "Enter the number of contact you want to edit "<<endl;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > contactCount)
    {
        cout << "invalid index"<<endl;
        return ;
    }

    index-- ;
    cout << "Editing contact #" << (index + 1) << ":\n";
    cout << "Enter new name: ";
    getline(cin, contats[index].name);
    cout << "Enter new phone number: ";
    getline(cin, contats[index].phoneNum);
    cout << "Enter new email: ";
    getline(cin, contats[index].email);

    cout << "Contact updated successfully.\n";

}

void deleteContact (Contact contats[],int contactCount)
{
    if (contactCount == 0) {
        cout << "No contacts available to delete.\n";
        return;
    }

    int index;
    ViewContact(contats,contactCount);
    cout << "enter contact number you want to delete"<<endl;
    cin >>index;

    cin.ignore();

    if (index < 1 || index > contactCount)
    {
        cout << "invalid number entered "<<endl;
        return ;
    }
    for (int i = index; i < contactCount; ++i)
    {
        contats[i - 1] = contats[i];
    }

    contactCount--;
    cout << "Contact deleted successfully.\n";

}



int main()
{
    Contact contacts[MAX_CONTACTS]; // Array of contacts
    int contactCount = 0;           // Number of contacts
    int choice;

     do {
        // Display menu options
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Edit Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore the newline character after the choice

        switch (choice) {
            case 1:
                addContact(contacts, contactCount);
                break;
            case 2:
                ViewContact(contacts, contactCount);
                break;
            case 3:
                Edit(contacts, contactCount);
                break;
            case 4:
                deleteContact(contacts, contactCount);
                break;
            case 5:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
