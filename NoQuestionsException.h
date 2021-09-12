#ifndef ASKME_PROJECT_NOQUESTIONSEXCEPTION_H
#define ASKME_PROJECT_NOQUESTIONSEXCEPTION_H
#include <stdexcept>
class NoQuestionsException : public std::runtime_error
{
public:
    NoQuestionsException() : std::runtime_error("There are no Questions to display")
    {
    }
};
#endif //ASKME_PROJECT_NOQUESTIONSEXCEPTION_H
