#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED

#include<vector>
#include<string>
#include"Person.h"
#include"Patient.h"

class Doctor : public Person
{
public:
    Doctor();
    Doctor(const char* , int , const char* , std::vector<std::string>);
    virtual ~Doctor();
    Doctor(const Doctor&);
    Doctor& operator=(const Doctor&);

    void setMedicalCertificateNumber(int);
    void setSpeciality(const char*);

    virtual void findPersonType() const;
    virtual void print() const;

    int getMedCertificateNumber()const;

    void addPatient(Patient &patient);

private:
    int medicalCertificateNumber;
    char* speciality = " ";
    std::vector<std::string> patients;

};


#endif // DOCTOR_H_INCLUDED
