#ifndef  NOSUCHOBJECT_H
#define  NOSUCHOBJECT_H


#include <string>
#include <stdexcept>
using namespace std;

class NoSuchObject : public logic_error
{
public:
    NoSuchObject(const string& message) : logic_error(message) {};
};

#endif