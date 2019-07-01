#include"Person.h"
#include<cstring>
Person::Person()
{
    name = " ";
}
Person::Person(const char* name)
{
    setName(name);
}
Person::~Person()
{
    delete [] name;
}
Person::Person(const Person& other)
{
    setName(other.name);
}
Person& Person::operator=(const Person& other)
{
    if(this != &other)
    {
        setName(other.name);
    }
    return *this;
}

void Person::setName(const char* name)
{
    if(this->name != NULL)
    {
        delete [] this->name;
    }
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

}
const char* Person::getName() const
{
    return this->name;
}


