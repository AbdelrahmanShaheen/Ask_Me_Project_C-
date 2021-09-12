#include "question.h"
#include <vector>
#include <map>
class User{
private:
    int id;
    string name;
    string userName;
    string email;
    string password;
    int anonymousQuestion; // if anonymous 1 else 0
public:
    void SetId(const int &id);
    int GetId()const;

    void SetAnonymous(const int &anonymous);
    int GetAnonymous()const;

    void SetName(const string &name);
    string GetName()const;

    void SetUserName(const string &userName);
    string GetUserName()const;

    void SetEmail(const string &email);
    string GetEmail()const;

    void SetPassword(const string &password);
    string GetPassword()const;

};