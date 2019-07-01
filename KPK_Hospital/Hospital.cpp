#include <iomanip>
#include<iostream>

#include"HospitalValidation.h"
#include"Hospital.h"
#include "ConsoleColor.h"


Hospital::Hospital()
{
    name = " ";
}
Hospital::Hospital(const char* name, std::vector<Doctor> doctors, std::vector<Nurse> nurses, std::vector<Patient> patients)
{
    setName(name);
    this->doctors = doctors;
    this->nurses = nurses;
    this->patients = patients;
}
Hospital::~Hospital()
{
    delete [] this->name;
}
Hospital::Hospital(const Hospital& other)
{
    setName(other.name);
    this->doctors = other.doctors;
    this->nurses = other.nurses;
    this->patients = other.patients;
}
Hospital& Hospital::operator=(const Hospital& other)
{
    if(this != &other)
    {
        setName(other.name);
        this->doctors = other.doctors;
        this->nurses = other.nurses;
        this->patients = other.patients;
    }
    return *this;
}

void Hospital::setName(const char* name)
{
    if(this->name != NULL)
    {
        delete [] this->name;
    }
    if(!isHospitalNameValid(name) || strcmp(name, " ") == 0)
    {
        this->name = new char[strlen("Unknown") + 1];
        strcpy(this->name, "Unknown");

    }
    else
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
}

void Hospital::addPatient(Patient &patient)
{
    patients.push_back(patient);
}
void Hospital::addDoctor(Doctor &doctor)
{
    doctors.push_back(doctor);
}
void Hospital::addNurse(Nurse &nurse)
{
    nurses.push_back(nurse);
}

int Hospital::findCountOfDoctors()const
{
    return doctors.size();
}
int Hospital::findCountOfNurses()const
{
    return nurses.size();
}
int Hospital::findCountOfPatients()const
{
    return patients.size();
}
const char* Hospital::getName() const
{
    return this->name;
}
std::vector<Doctor> Hospital::getDoctors()const
{
    return doctors;
}
std::vector<Nurse> Hospital::getNurses()const
{
    return nurses;
}
std::vector<Patient> Hospital::getPatients()const
{
    return patients;
}
void Hospital::connectingDoctorsAndPatients()
{
    if(patients.size() != 0)
    {
        for(int i = 0; i < patients.size(); i++)
        {
            char* doctorName = new char[strlen(patients[i].getAttendingDoctor()) + 1];
            strcpy(doctorName, patients[i].getAttendingDoctor());

            for(int j = 0; j < doctors.size(); j++)
            {
                if(strcmp(doctorName, doctors[j].getName()) == 0)
                {
                    doctors[j].addPatient(patients[i]);
                }
            }
        }
    }
}
void Hospital::print()const
{
    std::cout<<red<<"HOSPITAL: "<<name<<white<<std::endl;

    std::cout<<blue<<"\nDoctors:\n"<<white;
    if(doctors.size() == 0)   std::cout<<"Has no doctors right now!\n";
    else
    {
        for(int i = 0; i < doctors.size(); i++)
        {
            if(i != 0) std::cout<<'\n';
            std::cout<<blue<<"___________________________________\n";
            std::cout<<std::setw(5)<< i + 1 <<". "<<white;
            doctors[i].print();
            std::cout<<blue<<"\n___________________________________\n"<<white;
        }
    }

    std::cout<<yellow<<"\nNurses:\n"<<white;
    if(nurses.size() == 0)   std::cout<<"Has no nurses right now!\n";
    else
    {
        for(int i = 0; i < nurses.size(); i++)
        {
            if(i != 0) std::cout<<'\n';
            std::cout<<yellow<<"___________________________________\n";
            std::cout<<std::setw(5)<< i + 1 <<". "<<white;
            nurses[i].print();
            std::cout<<yellow<<"\n___________________________________\n"<<white;
        }
    }

    std::cout<<green<<"\nPatients:\n"<<white;
    if(patients.size() == 0)   std::cout<<"Has no patients right now!\n";
    else
    {
        for(int i = 0; i < patients.size(); i++)
        {
            if(i != 0) std::cout<<'\n';
            std::cout<<green<<"___________________________________\n";
            std::cout<<std::setw(5)<< i + 1 <<". "<<white;
            patients[i].print();
            std::cout<<green<<"\n___________________________________\n"<<white;
        }
    }

}
