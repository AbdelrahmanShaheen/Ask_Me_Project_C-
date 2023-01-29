#include "user_manager.h"
#include <fstream>
#include <iostream>
using namespace std;

void UserManager::ListSystemUsers() {
   for(int i =0 ;i<users.size() ;i++)
   {
       cout<<"ID: "<<users[i].GetId()<<"\t"<<"Name: "<<users[i].GetUserName()<<endl;
   }
}

void UserManager::LoadDataBase() {
    vector<string>data = ReadFileData("users.txt");
    for(int i = 0 ;i<data.size() ;i++)
    {
        vector<string>userInfo;
        userInfo = SplitString(data[i]);
        users.push_back(FillUserInfo(userInfo));
    }
}

vector<string>UserManager::ReadFileData(const string &file) {
     ifstream readFile(file);
     string line;
     vector<string>data;
     while (getline(readFile ,line))
     {
         if(!line.empty())
         data.push_back(line);
     }
     readFile.close();
     return data;
}

vector<string>UserManager::SplitString(string &str) {
    vector<string>splitedString;
    string s = "";
    for(int i = 0 ;i<str.size() ;i++)
    {
        if(str[i] == ',')
        {
            splitedString.push_back(s);
            s = "";
        }
        else
            s+=str[i];
    }
    if(!s.empty())
    splitedString.push_back(s);
    return splitedString;
}

User UserManager::FillUserInfo(vector<string> &userInfo) {
    User user;
    user.SetId(stoi(userInfo[0]));
    user.SetUserName(userInfo[1]);
    user.SetPassword(userInfo[2]);
    user.SetName(userInfo[3]);
    user.SetEmail(userInfo[4]);
    user.SetAnonymous(stoi(userInfo[5]));
    return user;
}

const int UserManager::DoSignUp() {
    string userName ,password ,name ,email;
    int aq;
    cout<<"Enter user name. (No spaces):";
    while (cin >> userName)
    {
        try {
            currentUser.SetUserName(userName);
            break;
        } catch (invalid_argument &error) {
            cout << "Error occurred: "<<error.what()<<endl;
        }
        cout<<"Enter user name. (No spaces):";
    }
    cout<<"Enter password:";
    while (cin >> password)
    {
        try {
            currentUser.SetPassword(password);
            break;
        } catch (invalid_argument &error) {
            cout << "Error occurred: "<<error.what()<<endl;
        }
        cout<<"Enter password:";
    }
    cout<<"Enter name:";
    while (cin>>name)
    {
        try {
            currentUser.SetName(name);
            break;
        } catch (invalid_argument &error) {
            cout << "Error occurred: "<<error.what()<<endl;
        }
        cout<<"Enter name:";
    }
    cout<<"Enter email:";
    while (cin>>email)
    {
        try {
            currentUser.SetEmail(email);
            break;
        } catch (invalid_argument &error) {
            cout << "Error occurred: "<<error.what()<<endl;
        }
        cout<<"Enter email:";
    }
    cout<<"Allow anonymous questions?: (1 or 0)";
    while (cin>>aq)
    {
        try {
            currentUser.SetAnonymous(aq);
            break;
        } catch (invalid_argument &error) {
            cout << "Error occurred: "<<error.what()<<endl;
        }
        cout<<"Allow anonymous questions?: (1 or 0)";
    }

    currentUser.SetId(users.size()+1);
    users.push_back(currentUser);
    return GetCurrentUserId();
}

int UserManager::DoLogin() {
    string pass{};
    string userName{};
    int position{};

        cout<<"Enter user name & password:";
        while (cin>>userName>>pass) {
            try {
                position = SearchForUser(userName ,pass);
                break;
            } catch (invalid_argument &e) {
                    cout<<e.what()<<endl;
            }
            cout<<"Enter user name & password:";
        }
    currentUser = users[position];
    return GetCurrentUserId();
}

int UserManager::SearchForUser(string &userName, string &password) {
    for(int indx = 0 ;indx < users.size() ;indx++)
    {
        if((users[indx].GetUserName() == userName) && (users[indx].GetPassword() == password))
            return indx;
    }
    throw invalid_argument("there is no user with such name or password");
}
int UserManager::GetCurrentUserId() {
    return currentUser.GetId();
}

const User *UserManager::GetUser(int &userId) {
    for(int i = 0 ;i<users.size() ;i++)
    {
        if(users[i].GetId() == userId)
        {
            return &users[i];
        }
    }
}

void UserManager::UpdateDataBase() {
    ofstream writeFile;
    writeFile.open("users.txt" ,ios::app);
    if(writeFile.fail())
    {
        cout<<"fail to open the file\n";
        return;
    }
        writeFile << currentUser.GetId() << "," << currentUser.GetUserName() << "," ;
        writeFile << currentUser.GetPassword() << "," << currentUser.GetName() << "," ;
        writeFile << currentUser.GetEmail() << "," << currentUser.GetAnonymous();
}