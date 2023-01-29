#include "user.h"
class UserManager{
private:
    vector<User>users;
    User currentUser;

    vector<string>ReadFileData(const string &file);
    vector<string>SplitString(string &str);
    User FillUserInfo(vector<string>&userInfo);
    int SearchForUser(string &name ,string &password);
public:
    void ListSystemUsers();
    void LoadDataBase();
    void UpdateDataBase();
    const int DoSignUp();
    int DoLogin();
    const User* GetUser(int &userId);
    int GetCurrentUserId();
};