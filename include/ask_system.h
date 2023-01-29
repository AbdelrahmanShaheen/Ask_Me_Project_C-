#include "user_manager.h"
#include "question_manager.h"
class AskSystem{
private:
    static AskSystem*instance;
    vector<string> menu;
    UserManager userManager;
    QuestionManager questionManager;

    void ShowMenu();
    int Choose();
    bool MenuValidation(int &choice);
    AskSystem();
public:
    void run();
    static AskSystem* GetInstance();
    static void FreeInstance();
};