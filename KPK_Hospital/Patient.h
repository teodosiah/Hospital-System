#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED
#include"Person.h"
#include<vector>
#include<string>


class Patient : public Person
{
public:
    Patient();
    Patient(const char*, int , const char*, const char*, const char*, const char* , std::vector<std::string>&);
    virtual ~Patient();
    Patient(const Patient&);
    Patient& operator=(const Patient&);


    void setAge(int);
    void setAttendingDoctor(const char*);
    void setDateOfAdmission(const char*);
    void setDateOfDischarge(const char*);
    void setDiagnosis(const char*);
    void setTreatment(std::vector<std::string>&);

    const char* getAttendingDoctor() const;
    const char* getDateOfDischarge() const;
    int getAge()const;

    virtual void findPersonType() const;
    virtual void print() const;


private:
    int age;
    char* attendingDoctor = " ";
    char* dateOfAdmission = " ";
    char* dateOfDischarge = " ";
    char* diagnosis = " ";
    std::vector <std::string> treatment;


};

#endif // PATIENT_H_INCLUDED
