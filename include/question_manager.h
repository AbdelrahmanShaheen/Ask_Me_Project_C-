class Question;
#include <vector>
#include <map>
#include "NoQuestionsException.h"
using namespace std;
class User;
class QuestionManager{
private:
   //questions for all users.
   vector<Question*>questions;
   map<int ,vector<Question*>>parentId_threadsQuestions; // < parentId , <parentQuestion + threadsQuestions> > for all questions.
   //questions for current user.
   vector<Question*>fromCurrentUser;
   map<int ,vector<Question*>>toCurrentUser;   //<parentId ,<parent + threads>>
   //clear methods.
    void ClearQuestions();
    void ClearParentId_threadsQuestions();
    void ClearFromCurrentUser();
    void ClearToCurrentUser();
   //helper methods :
   vector<string>ReadFileData(string file);
   vector<string>SplitString(string question);
   Question *FillQuestionInfo(vector<string>&questionInfo);
   void DeleteParentQuestion(int parentId);
   void DeleteThreadQuestion(Question* ,int );
public:
    void AnswerQuestion();

    void DeleteQuestion();

    void AskQuestion(const User*,const int &);

    void FillQuestionsToCurrentUser(const int &);
    void FillQuestionsFromCurrentUser(const int &);
    void FillCurrentUserQuestions(const int &);

    void Cleardatabase();

    void PrintQuestionsFromCurrentUser();
    void PrintQuestionstoCurrentUser();

    void UpdateDataBase();
    void LoadDatabase();

    void Feed();
};