#include "ask_system.h"
#include <iostream>
using namespace std;

void AskSystem::run() {
    userManager.LoadDataBase();
    menu.push_back("\t1: Login");
    menu.push_back("\t2: Sign Up");
    ShowMenu();
    int currentUserId;
    if(Choose() == 1)
    {
       currentUserId = userManager.DoLogin();
    }
    else
    {
      currentUserId = userManager.DoSignUp();
        userManager.UpdateDataBase();
    }
    questionManager.LoadDatabase(); //load database for all questions.
    questionManager.FillCurrentUserQuestions(currentUserId); //load data base for current user questions.
    menu.clear();
    menu.push_back("\t1: Print Questions To Me");
    menu.push_back("\t2: Print Questions From Me");
    menu.push_back("\t3: Answer Question");
    menu.push_back("\t4: Delete Question");
    menu.push_back("\t5: Ask Question");
    menu.push_back("\t6: List System Users");
    menu.push_back("\t7: Feed");
    menu.push_back("\t8: Logout");
    while (true)
    {
        ShowMenu();
        int choice = Choose();
        if(choice == 1)
        {
            try {
                questionManager.PrintQuestionstoCurrentUser();
            } catch (NoQuestionsException &noQuestionsException) {
              cout << "Exception occurred: ";
              cout<<noQuestionsException.what()<<endl;
            }

        }
        else if(choice == 2)
        {
            try {
                questionManager.PrintQuestionsFromCurrentUser();
            }catch (NoQuestionsException &noQuestionsException) {
                cout << "Exception occurred: ";
                cout<<noQuestionsException.what()<<endl;
            }
        }
        else if(choice == 3)
        {
            questionManager.AnswerQuestion(); //you should handle an exception here to check if you answer your own question or not.
            questionManager.UpdateDataBase();
        }
        else if(choice == 4)
        {
            questionManager.DeleteQuestion();//you should handle an exception here to check if you try to delete your own questions.
            questionManager.UpdateDataBase();
        }
        else if(choice == 5)
        {
            cout<<"Enter user id or -1 to cancel :";
            int userId;
            cin>>userId; //you should handle an exception here to check if you try to ask an existing user or not .
            questionManager.AskQuestion(userManager.GetUser(userId) ,userManager.GetCurrentUserId());
            questionManager.UpdateDataBase();
        }
        else if(choice == 6)
        {
             userManager.ListSystemUsers();
        }
        else if(choice == 7)
        {
             questionManager.Feed();
        }
        else
        {
            break;
        }
        questionManager.LoadDatabase();
        questionManager.FillCurrentUserQuestions(currentUserId);
    }
}

void AskSystem::ShowMenu(){
    cout<<"Menu:\n";
    for(int i = 0 ;i<menu.size() ;i++)
    {
        cout<<menu[i]<<endl;
    }
    cout<<"Enter number in range 1 - "<<menu.size()<<":\n";
}

int AskSystem::Choose() {
    int choice;
    cin>>choice;
    bool check = false;
    while (!check)
    {
        try {
           check = MenuValidation(choice);
        } catch (out_of_range &e) {
            cout<<"out_of_range :"<<e.what()<<endl;
        }
    }
    return choice;
}

bool AskSystem::MenuValidation(int &choice) {
        if(choice > menu.size() || choice <= 0)
        {
            throw out_of_range("Enter a number in a given range");
        }
    return true;
}

AskSystem *AskSystem::GetInstance() {
    if(instance == nullptr)
    {
        instance = new AskSystem;
    }
    return instance;
}

AskSystem::AskSystem() {

}

void AskSystem::FreeInstance() {
  if(instance != nullptr)
  {
      delete instance;
      instance = nullptr;
  }
}