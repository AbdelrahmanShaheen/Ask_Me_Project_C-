#include <fstream>
#include "question_manager.h"
#include <iostream>
#include "user.h"

void QuestionManager::AnswerQuestion() {
    cout << "Enter question id or -1 to cancel :";
    int questionId;
    cin >> questionId;

    if (questionId == -1)
        return;

    for (int i = 0; i < questions.size(); i++) {
        if (questions[i]->GetId() == questionId) {
            cout << "question id (" << questions[i]->GetId() << ") from user id (" << questions[i]->GetFromUserId()
                 << ")\t";
            cout << "\tQuestion: " << questions[i]->GetQuestion() << endl;
            if (!questions[i]->GetAnswer().empty())
                cout << "\t Answer: " << questions[i]->GetAnswer() << endl;
            cout << endl;
            if (!questions[i]->GetAnswer().empty())
                cout << "Warning: Already answered . Answer will be updated\n";
            string answer;
            cout << "Enter answer :";
            getline(cin, answer);
            getline(cin, answer);
            questions[i]->SetAnswer(answer);
            break;
        }
    }
}

void QuestionManager::DeleteQuestion() { //
    cout << "Enter question id or -1 to cancel:\n";
    int questionId;
    cin >> questionId;
    if (questionId == -1)
        return;
    //delete parent question and its threads.
    for (auto it : parentId_threadsQuestions) {
        if (it.first == questionId) {
            DeleteParentQuestion(it.first);
            return;
        }
    }
    //delete one question "a thread question".
    for (int pos = 0; pos < questions.size(); pos++) {
        if (questions[pos]->GetId() == questionId) {
            DeleteThreadQuestion(questions[pos], pos);
            break;
        }
    }
}

void QuestionManager::AskQuestion(const User *anyUser, const int &currentUserId) { // userInfo->isAnonymous
    cout << "Note:";
    if (anyUser->GetAnonymous())
        cout << "anonymous question are allowed for this user\n";
    else
        cout << "anonymous question are not allowed for this user\n";
    cout << "For thread question enter question id or -1 for new question :";
    int questionId;
    cin >> questionId;
    cout << "Enter question text :";
    string question;
    getline(cin, question);
    getline(cin, question);
    Question *question1 = new Question;
    question1->SetId(questions.size() + 1);
    question1->SetNewOrThread(questionId); //validate here
    question1->SetFromUserId(currentUserId);
    question1->SetToUserId(anyUser->GetId());
    question1->SetQuestion(question);
    questions.push_back(question1);
}

void QuestionManager::LoadDatabase() {
    Cleardatabase();
    vector<string> data = ReadFileData("questions.txt");

    for (int i = 0; i < data.size(); i++)//fill questions.
    {
        vector<string> questionInfo;
        questionInfo = (SplitString(data[i]));
        questions.push_back(FillQuestionInfo(questionInfo));
    }
    for (int i = 0; i < questions.size(); i++) //fill parents.
    {
        vector<Question *> q;
        if (questions[i]->GetNewOrThread() == -1) {
            q.push_back(questions[i]);
            parentId_threadsQuestions[questions[i]->GetId()] = q;
        }
    }
    for (int i = 0; i < questions.size(); i++) //fill threads.
    {
        if (questions[i]->GetNewOrThread() != -1) {
            parentId_threadsQuestions[questions[i]->GetNewOrThread()].push_back(questions[i]);
        }
    }
}

vector<string> QuestionManager::ReadFileData(string file) {
    string line;
    ifstream readFile;
    readFile.open(file);
    vector<string> questions_;
    while (getline(readFile, line)) {
        if (!line.empty())
            questions_.push_back(line);
    }
    readFile.close();
    return questions_;
}

vector<string> QuestionManager::SplitString(string question) {
    vector<string> splitedString;
    string s = "";
    for (int i = 0; i < question.size(); i++) {
        if (question[i] == ',') {
            splitedString.push_back(s);
            s = "";
        } else
            s += question[i];
    }
    splitedString.push_back(s);
    return splitedString;
}

Question *QuestionManager::FillQuestionInfo(vector<string> &questionInfo) {
    Question *question = new Question;

    question->SetId(stoi(questionInfo[0]));
    question->SetNewOrThread(stoi(questionInfo[1]));
    question->SetFromUserId(stoi(questionInfo[2]));
    question->SetToUserId(stoi(questionInfo[3]));
    question->SetAnonymousQuestion(stoi(questionInfo[4]));
    question->SetQuestion(questionInfo[5]);
    if (!questionInfo[6].empty())
        question->SetAnswer(questionInfo[6]);
    return question;
}

void QuestionManager::FillQuestionsToCurrentUser(const int &currentUserId) {
    for (auto it : parentId_threadsQuestions) {
        if (it.second[0]->GetToUserId() == currentUserId) {
            toCurrentUser[it.first] = it.second;
        }
    }
}

void QuestionManager::FillQuestionsFromCurrentUser(const int &currentUserId) {
    for (int i = 0; i < questions.size(); i++) {
        if (questions[i]->GetFromUserId() == currentUserId)
            fromCurrentUser.push_back(questions[i]);
    }
}

void QuestionManager::FillCurrentUserQuestions(const int &currentUserId) {
    if (!fromCurrentUser.empty() && !toCurrentUser.empty()) {
        fromCurrentUser.clear();
        toCurrentUser.clear();
    }
    FillQuestionsFromCurrentUser(currentUserId);
    FillQuestionsToCurrentUser(currentUserId);
}

void QuestionManager::Cleardatabase() {
    ClearQuestions();
    ClearParentId_threadsQuestions();
    ClearFromCurrentUser();
    ClearToCurrentUser();
}

void QuestionManager::ClearQuestions() {
    //clear questions from heap.
    if (questions.empty())return;
    for (int i = 0; i < questions.size(); i++) {
        delete questions[i];
        questions[i] = nullptr;
    }
    questions.clear();
}

void QuestionManager::ClearParentId_threadsQuestions() {
    //clear all questions and their threads.
    if (parentId_threadsQuestions.empty())return;
    for (auto it : parentId_threadsQuestions) {
        for (int i = 0; i < it.second.size(); i++) {
            delete it.second[i];
            it.second[i] = nullptr;
        }
    }
    parentId_threadsQuestions.clear();
}

void QuestionManager::ClearFromCurrentUser() {
//clear fromCurrentUser questions.
    if (fromCurrentUser.empty())return;
    for (int i = 0; i < fromCurrentUser.size(); i++) {
        delete fromCurrentUser[i];
        fromCurrentUser[i] = nullptr;
    }
    fromCurrentUser.clear();
}

void QuestionManager::ClearToCurrentUser() {
//clear toCurrentUser questions.
    if (toCurrentUser.empty())return;
    for (auto it : toCurrentUser) {
        for (int i = 0; i < it.second.size(); i++) {
            delete it.second[i];
            it.second[i] = nullptr;
        }
    }
    toCurrentUser.clear();
}

void QuestionManager::PrintQuestionsFromCurrentUser() {
    if (fromCurrentUser.empty()) {
        throw NoQuestionsException();
    }
    for (int i = 0; i < fromCurrentUser.size(); i++) {
        cout << "Question Id (" << fromCurrentUser[i]->GetId() << ") to user id(" << fromCurrentUser[i]->GetToUserId()
             << ")\t";
        cout << "Question: " << fromCurrentUser[i]->GetQuestion() << "\n";
        if (fromCurrentUser[i]->GetAnswer().empty())
            cout << "\tNot Answered Yet\n";
        else
            cout << "\tAnswer: " << fromCurrentUser[i]->GetAnswer() << endl;
    }
}

void QuestionManager::PrintQuestionstoCurrentUser() {

    if (toCurrentUser.empty()) {
        throw NoQuestionsException();
    }
    for (auto it :  toCurrentUser) {

        //parent question:
        cout << "Question Id (" << it.first << ")";
        if (!it.second[0]->IsAnonymousQuestion())
            cout << " from user id (" << it.second[0]->GetFromUserId() << ")\t";
        cout << "Question: " << it.second[0]->GetQuestion() << endl;
        if (!it.second[0]->GetAnswer().empty())
            cout << "\tAnswer: " << it.second[0]->GetAnswer() << endl;
        cout << endl;
        //threads:
        for (int i = 1; i < it.second.size(); i++) {
            cout << "\tThread: ";
            cout << "Question Id (" << it.second[i]->GetId() << ")";
            if (!it.second[i]->IsAnonymousQuestion())
                cout << " from user id (" << it.second[i]->GetFromUserId() << ")\t";
            cout << "Question: " << it.second[i]->GetQuestion() << endl;
            if (!it.second[i]->GetAnswer().empty()) {
                cout << "\tThread: ";
                cout << "\tAnswer: " << it.second[i]->GetAnswer() << endl;
            }
            cout << endl;
        }
    }
}

void QuestionManager::UpdateDataBase() {
    ofstream writeFile;
    writeFile.open("questions.txt", ios::trunc);
    if (writeFile.fail()) //validate here.
    {
        cout << "fail to open the file\n";
        return;
    }
    for (int i = 0; i < questions.size(); i++) {
        writeFile << questions[i]->GetId() << "," << questions[i]->GetNewOrThread() << ",";
        writeFile << questions[i]->GetFromUserId() << "," << questions[i]->GetToUserId() << ",";
        writeFile << questions[i]->IsAnonymousQuestion() << "," << questions[i]->GetQuestion() << ",";
        if (!questions[i]->GetAnswer().empty())
            writeFile << questions[i]->GetAnswer();
        writeFile << endl;
    }
    writeFile.close();
}

void QuestionManager::DeleteThreadQuestion(Question *question1, int pos) {
    delete question1;
    question1 = nullptr;
    questions.erase(questions.begin() + pos);
}

void QuestionManager::DeleteParentQuestion(int parentId) {
    for (int pos = 0; pos < questions.size(); pos++) {
        if (parentId == questions[pos]->GetNewOrThread() || parentId == questions[pos]->GetId()) {
            DeleteThreadQuestion(questions[pos], pos);
            pos--;
        }
    }
}

void QuestionManager::Feed() {
    for (auto it : parentId_threadsQuestions) {
        for (auto it2 : it.second) {
            if (!it2->GetAnswer().empty()) {
                if (it2->GetId() != it.first) //it is a thread question.
                    cout << "Thread Parent Question Id (" << it.first << ") ";
                cout << "Question Id (" << it2->GetId() << ")";
                if (!it2->IsAnonymousQuestion())
                    cout << " From user Id (" << it2->GetFromUserId() << ")";
                cout << " To user Id(" << it2->GetToUserId() << ")";
                cout << "\t Question: " << it2->GetQuestion() << endl;
                cout << "\tAnswer: " << it2->GetAnswer() << endl;

            }
        }
    }
}