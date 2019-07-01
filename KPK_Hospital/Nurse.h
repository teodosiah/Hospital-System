#ifndef NURSE_H_INCLUDED
#define NURSE_H_INCLUDED

#include"Person.h"

class Nurse : public Person
{
public:
    Nurse();
    Nurse(const char*, const char*, const char*);
    virtual ~Nurse();
    Nurse(const Nurse&);
    Nurse& operator=(const Nurse&);

    void setDepartment(const char*);
    void setNursingCertificateNumber(const char*);

    const char* getNursingCertificateNumber()const;
    virtual void findPersonType() const;
    virtual void print() const;

private:
    char* department = " ";
    char* nursingCertificateNumber = " ";
};

#endif // NURSE_H_INCLUDED
