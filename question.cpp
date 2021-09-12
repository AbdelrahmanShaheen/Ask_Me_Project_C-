#include "question.h"
#include <iostream>

void Question::SetId(const int &id) {
    this->id = id;
}

int Question::GetId() const {
    return id;
}

void Question::SetNewOrThread(const int &newOrThread) {
    this->newOrThread = newOrThread;
}

int Question::GetNewOrThread() const {
    return newOrThread;
}

void Question::SetFromUserId(const int &fromUserId) {
    this->fromUserId = fromUserId;
}

int Question::GetFromUserId() const {
    return this->fromUserId;
}

void Question::SetToUserId(const int &toUserId) {
    this->toUserId = toUserId;
}

int Question::GetToUserId() const {
    return this->toUserId;
}

void Question::SetAnonymousQuestion(const int &anonymousQuestion) {

    if (anonymousQuestion == 0 || anonymousQuestion == 1)
        this->anonymousQuestion = anonymousQuestion;
    else
        throw invalid_argument("invalid number: please put 0 for !AQ and 1 for AQ");
}

bool Question::IsAnonymousQuestion() const {
    if (anonymousQuestion == 0)
        return false;
    else
        return true;
}

void Question::SetQuestion(const string &question) {
    this->question = question;
}

string Question::GetQuestion() const {
    return this->question;
}

void Question::SetAnswer(const string &answer) {
    this->answer = answer;
}

string Question::GetAnswer() const {
    return answer;
}

Question::Question() {
}