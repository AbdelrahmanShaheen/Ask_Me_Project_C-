#include <string>
#include <vector>
using namespace std;
class Question{
private:
    int id{};
    int newOrThread{}; //-1 or parent id.
    int fromUserId{};
    int toUserId{};
    int anonymousQuestion{}; // if anonymous 1 else 0
    string question;
    string answer;
public:
    Question();
    void SetId(const int &id);
    int GetId()const;

    void SetNewOrThread(const int &newOrThread);
    int GetNewOrThread()const;

    void SetFromUserId(const int &fromUserId);
    int GetFromUserId()const;

    void SetToUserId(const int &toUserId);
    int GetToUserId()const;

    void SetAnonymousQuestion(const int &anonymousQuestion);
    bool IsAnonymousQuestion()const;

    void SetQuestion(const string &question);
    string GetQuestion()const;

    void SetAnswer(const string &answer);
    string GetAnswer()const;
};