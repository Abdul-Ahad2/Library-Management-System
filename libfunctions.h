#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
using namespace std;

struct bookInfo
{
    string bookName;
    string authorName;
    int year, month, date;
}info;

struct students
{
    string id;
    string pass;
}user;

struct admin
{
    string id;
    string pass;
};


void addBook(){
    
    cout<<"Enter the name of book to be added: ";
    cin.ignore();
    getline(cin, info.bookName);
    cout<<"\nEnter the author name of book to be added: ";
    getline(cin, info.authorName);
    cout<<"\nEnter the date of the book when it was published\nDate: ";
    cin>>info.date;
    cout<<"\nMonth(For example \'02\' for February): ";
    cin>>info.month;
    cout<<"\nYear(For example \'2002\'): ";
    cin>>info.year; 
    
    fstream file;
    
    file.open("bookList.txt", ios::app | ios::binary);

    file<<info.bookName<<" by "<<info.authorName<<", Published: "<<info.date<<"/"<<info.month<<"/"<<info.year<<endl;

    file.close(); 
}

void bookList(){

    int id = 1;

    fstream file;
    file.open("bookList.txt", ios::in | ios::binary);
    string text;
    while (getline(file, text)){  
        cout<<"Book Id: "<<id<<"; "<<text<<endl; 
        id++;
    };

}

void deleteBook(){
    int id;
    bookList();
    cout<<"\n\n";
    cout<<"Enter the Id of the Book you want to delete: ";
    cin>>id;

    string fileName = "bookList.txt";
    string tempFileName = "temp.txt";

    fstream file,file2;
    file.open("bookList.txt", ios::in);
    file2.open("temp.txt", ios::app);


    int currentLine = 0;
    string text;
    while (getline(file, text)) {
        currentLine++;
        if (currentLine != id) {
            file2<<text<< endl;
        }
    }

    file.close();
    file2.close();

    remove(fileName.c_str());
    rename(tempFileName.c_str(), fileName.c_str());
    cout<<"Successfully Deleted!";
}

int updateBook(){

   int id;
    bookList();
    cout<<"\n\n";
    cout<<"Enter the Id of the Book you want to update: ";
    cin>>id;
    cout<<"\n\n";
    string fileName = "bookList.txt";
    string tempFileName = "temp.txt";

    fstream file,file2;
    file.open("bookList.txt", ios::in);
    file2.open("temp.txt", ios::app);


    int currentLine = 0;
    string text;
    while (getline(file, text)) {
        currentLine++;
        if (currentLine != id) {
            file2<<text<< endl;
        }else{
            cout<<"Enter the name of book to be added: ";
            cin.ignore();
            getline(cin, info.bookName);
            cout<<"\nEnter the author name of book to be added: ";
            getline(cin, info.authorName);
            cout<<"\nEnter the date of the book when it was published\nDate: ";
            cin>>info.date;
            cout<<"\nMonth(For example \'02\' for February): ";
            cin>>info.month;
            cout<<"\nYear(For example \'2002\'): ";
            cin>>info.year;

            file2<<info.bookName<<" by "<<info.authorName<<", dated: "<<info.date<<"/"<<info.month<<"/"<<info.year<<endl;
        }
    }

    file.close();
    file2.close();

    remove(fileName.c_str());
    rename(tempFileName.c_str(), fileName.c_str());
    cout<<"Successfully Updated!";

 }

void studentRegister(){

    fstream filePassAndId;

    filePassAndId.open("studentPass.txt", ios::app);

    cout<<"\nEnter a new one word user ID: ";
    cin.ignore();
    getline(cin, user.id);
    cout<<"\nEnter new user password: ";
    getline(cin, user.pass);

    filePassAndId<<user.id<<" "<<user.pass<<endl;

    cout<<"Registration Successful!";
};

int studentLogin(){
    int login = 0;
    cout<<"\t\t\t\t\tLOGIN";
    cout<<"\nEnter your ID : ";
    cin>>user.id;
    cout<<"Enter your Password: ";
    cin>>user.pass;
    string details = user.id + " " + user.pass;
    fstream fileRead;
    fileRead.open("studentPass.txt", ios::in);
    string text;
    while (getline(fileRead, text))
    {
        if(details == text){
            cout<<"Logged In!";
            login = 1;
            break;
        }
    }

    if (login == 0)
    {
        cout<<"You are not registered!";
    }
    
    return login; 
}


int adminLogin(){
    
    admin loginDetails;
    loginDetails.id = "admin";
    loginDetails.pass = "admin";

    string pass,id;
    bool login = 0;
    cout<<"\nEnter ID: ";
    cin.ignore();
    getline(cin, id);
    cout<<"\nEnter Password: ";
    getline(cin, pass);

    if(id == loginDetails.id && pass == loginDetails.pass){
        cout<<"Login Successful!"<<endl;
        login = 1;
    }else{
        cout<<"Invalid username or password!"<<endl;
    }
    return login;

}
   

int borrowBook(){
    int id;
    cout<<"\n\n";
    bookList();
    cout<<"\n\n";
    cout<<"Enter the Id of the Book you want to borrow: ";
    cin>>id;

    string fileName = "bookList.txt";
    string tempFileName = "temp.txt";

    fstream file,file2,file3;
    file.open("bookList.txt", ios::in);
    file2.open("temp.txt", ios::app);
    file3.open("borrowedBookList.txt", ios::app);

    int currentLine = 0;
    string text;
    while (getline(file, text)) {
        currentLine++;
        if (currentLine != id) {
            file2<<text<< endl;
        }else{
            file3<<text<<endl;
            cout<<"Successfully Borrowed!";
        }
    }

    file.close();
    file2.close();

    remove(fileName.c_str());
    rename(tempFileName.c_str(), fileName.c_str());
    
}

void borrowedList(){

    int id = 1;

    fstream file;
    file.open("borrowedBookList.txt", ios::in | ios::binary);
    string text;
    while (getline(file, text)){  
        cout<<"Book Id: "<<id<<"; "<<text<<endl; 
        id++;
    };

}

int returnBook(){
    int id;
    borrowedList();
    cout<<"\n\n";
    cout<<"Enter the Id of the Book you want to return: ";
    cin>>id;

    string fileName = "borrowedBookList.txt";
    string tempFileName = "temp.txt";

    fstream file,file2,file3;
    file.open("borrowedBookList.txt", ios::in);
    file2.open("temp.txt", ios::app);
    file3.open("bookList.txt", ios::app);

    int currentLine = 0;
    string text;
    while (getline(file, text)) {
        currentLine++;
        if (currentLine != id) {
            file2<<text<< endl;
        }else{
            file3<<text<<endl;
            cout<<"Successfully Returned!";
        }
    }

    file.close();
    file2.close();

    remove(fileName.c_str());
    rename(tempFileName.c_str(), fileName.c_str());
}



 
