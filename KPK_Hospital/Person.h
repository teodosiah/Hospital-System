#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include<iostream>
class Person
{
public:
    Person();
    Person(const char*);
    virtual ~Person();
    Person(const Person&);
    Person& operator=(const Person&);

    const char* getName() const;
    void setName(const char*);

    virtual void findPersonType() const = 0;
    virtual void print() const = 0;

protected:
    char* name = " ";
};

#endif // PERSON_H_INCLUDED
