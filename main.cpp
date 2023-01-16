#include <iostream>
#include <string.h>
#include <fstream>
#include "libfunctions.h"
using namespace std;

int main(){

int choice,choice2,choice3,choice4,choice5,choice6;
system("cls");

cout<<"\t\t\t\t\t\tWELCOME TO LMS\n\nEnter the correct option:\n\n1. Student\n2. Admin\nYour Choice: ";
cin>>choice;

system("cls");

switch (choice)
{
case 1:
    cout<<"\n\nEnter the correct option:\n1. Register\n2. Login\nYour Choice: ";
    cin>>choice2;
    system("cls");
    if (choice2  == 1)
    {
        studentRegister();
        system("cls");
        cout<<"\n\nNow please Login!\n\n";
        goto login;
    }else{
        login:
        int login = studentLogin();
        if(login == 1){
            loginChoices:
            system("cls");
            cout<<"\n\nEnter the correct option:\n1. Check Available Books\n2. Borrow Book\n3. Return Book\nYour Choice: ";
            cin>>choice3;
            system("cls");
            switch (choice3)
            {
            case 1:
                bookList();
                cout<<"\nDo you want to borrow a book?(Press \'1\' if yes): ";
                cin>>choice4;
                system("cls");
                if(choice4 == 1){
                    goto borrow;
                }else{
                    return 0;
                }
                break;
            case 2:
                borrow:
                borrowBook();
                break;
            case 3:
                returnBook();
                break;  
            default:
            cout<<"Invalid Command";
            goto loginChoices;
                break;
            }

        }
    }
    
    break;
    
case 2:
    cout<<"\n\t\t\t\t\t\tLOGIN\n";
    choice5 = adminLogin();
    system("cls");
    if(choice5 == 1){
        choice5:
        cout<<"\n\nEnter the correct option:\n\n1. Update a Book\n2. Delete a Book\n3. Check Available\n4. Borrowed Book List\n5. Add Book\nYour Choice: ";
        cin>>choice5;
        system("cls");
        switch (choice5)
        {
        case 1:
            updateBook();
            break;
        case 2:
            deleteBook();
            break;
        case 3:
            bookList();
            break;
        case 4:
            borrowedList();
            break;
        case 5:
            bookadd:
            addBook();
            cout<<"Press \'1\' if you want to add more books: ";
            cin>>choice6;
            system("cls");
            if(choice6==1){
                goto bookadd;
            }
            break;    
        default:
        cout<<"Invalid Command!";
        goto choice5;
            break;
        }
    }else{
        cout<<"Error: INVALID CREDENTIALS. Restart Program!";
        return 0;
    }

    break;

default:

cout<<"\nWrong Command!";
    
    break;
}   
}
























