#include<iostream>
#include <iomanip>
#include<string>
#include<cstring>
#include <stdlib.h>

#include"PatientValidation.h"
#include"Patient.h"

Patient::Patient()
    :Person()
{
    age = 0;
    attendingDoctor = " ";
    dateOfAdmission = " ";
    dateOfDischarge = " ";
    diagnosis = " ";
}
Patient::Patient(const char* name, int age, const char* attendingDoctor, const char* dateOfAdmission, const char* dateOfDischarge, const char* diagnosis, std::vector<std::string>& treatment)
    :Person(name)
{
    setAge(age);
    setAttendingDoctor(attendingDoctor);
    setDateOfAdmission(dateOfAdmission);
    setDateOfDischarge(dateOfDischarge);
    setDiagnosis(diagnosis);
    this->treatment = treatment;

}
Patient::~Patient()
{
    delete [] attendingDoctor;
    delete [] dateOfAdmission;
    delete [] dateOfDischarge;
    delete [] diagnosis;
}
Patient::Patient(const Patient& other)
    :Person(other.name)
{
    setAge(other.age);
    setAttendingDoctor(other.attendingDoctor);
    setDateOfAdmission(other.dateOfAdmission);
    setDateOfDischarge(other.dateOfDischarge);
    setDiagnosis(other.diagnosis);
    this->treatment = other.treatment;

}
Patient& Patient::operator=(const Patient& other)
{
    if(this != &other)
    {
        Person::operator=(other);

        setAge(age);
        setAttendingDoctor(other.attendingDoctor);
        setDateOfAdmission(other.dateOfAdmission);
        setDateOfDischarge(other.dateOfDischarge);
        setDiagnosis(other.diagnosis);
        this->treatment = other.treatment;
    }
    return *this;
}

void Patient::setAge(int age)
{
    if(!isAgeValid(age))
    {
        this->age = -1;
    }
    else
    {
        this->age = age;
    }
}
void Patient::setAttendingDoctor(const char* attendingDoctor)
{
    if(this->attendingDoctor != NULL)
    {
        delete [] this->attendingDoctor;
    }
    if(!isStringValid(attendingDoctor) || strcmp(attendingDoctor, " ") == 0)
    {
        this->attendingDoctor = new char[strlen("Unknown") + 1];
        strcpy(this->attendingDoctor,"Unknown");
    }
    else
    {
        this->attendingDoctor = new char[strlen(attendingDoctor) + 1];
        strcpy(this->attendingDoctor, attendingDoctor);
    }
}
void Patient::setDateOfAdmission(const char* dateOfAdmission)
{
    if(this->dateOfAdmission != NULL)
    {
        delete [] this->dateOfAdmission;
    }
    if(!isValidDate(dateOfAdmission) || strcmp(dateOfAdmission, " ") == 0)
    {
        this->dateOfAdmission = new char[strlen("Unknown") + 1];
        strcpy(this->dateOfAdmission, "Unknown");
    }
    else
    {
        this->dateOfAdmission = new char[strlen(dateOfAdmission) + 1];
        strcpy(this->dateOfAdmission, dateOfAdmission);
    }

}
void Patient::setDateOfDischarge(const char* dateOfDischarge)
{
    if(this->dateOfDischarge != NULL)
    {
        delete [] this->dateOfDischarge;
    }
    if(!isValidDate(dateOfDischarge) || strcmp(dateOfDischarge, " ") == 0)
    {
        this->dateOfDischarge = new char[strlen("Unknown") + 1];
        strcpy(this->dateOfDischarge, "Unknown");
    }
    else
    {
        this->dateOfDischarge = new char[strlen(dateOfDischarge) + 1];
        strcpy(this->dateOfDischarge, dateOfDischarge);
    }
}

void Patient::setDiagnosis(const char* diagnosis)
{
    if(this->diagnosis != NULL)
    {
        delete [] this->diagnosis;
    }
    if(!isStringValid(diagnosis) || strcmp(diagnosis, " ") == 0)
    {
        this->diagnosis = new char[strlen("Unknown") + 1];
        strcpy(this->diagnosis, "Unknown");
    }
    else
    {
        this->diagnosis = new char[strlen(diagnosis) + 1];
        strcpy(this->diagnosis, diagnosis);
    }
}
void Patient::setTreatment(std::vector<std::string>& treatment)
{
    this->treatment = treatment;
}
const char* Patient::getAttendingDoctor() const
{
    return this->attendingDoctor;
}
const char* Patient::getDateOfDischarge() const
{
    return this->dateOfDischarge;
}
int Patient::getAge()const
{
    return this->age;
}
void Patient::findPersonType() const
{
    std::cout<<"PATIENT\n";
}

void Patient::print() const
{
    std::cout<<getName()<<std::endl;

    if(age != -1) std::cout<<"- Age: "<<age<<std::endl;
    else std::cout<<"- Age: Unknown"<<std::endl;

    std::cout<<"\n- Attending Doctor: "<<attendingDoctor<<std::endl;
    std::cout<<"- DIAGNOSIS: "<<diagnosis<<std::endl;
    std::cout<<"- Date of admission: "<<dateOfAdmission<<std::endl;
    std::cout<<"- Date of discharge: "<<dateOfDischarge<<std::endl;
    std::cout<<"\n- Treatment:";
    if(treatment.empty()) std::cout<<" Unknown"<<std::endl;
    else
    {
        std::cout<<'\n';
        for(int i = 0; i < treatment.size(); i++)
        {
            std::cout<<std::setw(5)<< i + 1 <<". " <<treatment[i]<<std::endl;
        }
    }

}



