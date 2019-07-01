#include<cstring>
#include <iomanip>

#include"DoctorValidation.h"
#include"Doctor.h"

Doctor::Doctor()
    :Person()
{
    medicalCertificateNumber = 0;
    speciality = " ";

}

Doctor::Doctor(const char* name, int medicalCertificateNumber, const char* speciality, std::vector<std::string> patients)
    :Person(name)
{
    setMedicalCertificateNumber(medicalCertificateNumber);
    setSpeciality(speciality);
    this->patients = patients;
}
Doctor::~Doctor()
{
    delete [] this->speciality;
}
Doctor::Doctor(const Doctor& other)
    :Person(other.name)
{
    setMedicalCertificateNumber(other.medicalCertificateNumber);
    setSpeciality(other.speciality);
    this->patients = other.patients;
}
Doctor& Doctor::operator=(const Doctor& other)
{
    if(this != &other)
    {
        Person::operator=(other);

        setMedicalCertificateNumber(other.medicalCertificateNumber);
        setSpeciality(other.speciality);
        this->patients = other.patients;
    }
    return *this;
}
void Doctor::setMedicalCertificateNumber(int medicalCertificateNumber)
{
    if( !isValidMedCertificateNumber(medicalCertificateNumber))
    {
        this->medicalCertificateNumber = -1;
    }
    else this->medicalCertificateNumber = medicalCertificateNumber;
}
void Doctor::setSpeciality(const char* speciality)
{
    if(this->speciality != NULL)
    {
        delete [] this->speciality;
    }
    if(!isSpecialityValid(speciality) || strcmp(speciality, " ") == 0)
    {
        this->speciality = new char[strlen("Unknown") + 1];
        strcpy(this->speciality, "Unknown");
    }
    else
    {
        this->speciality = new char[strlen(speciality) + 1];
        strcpy(this->speciality, speciality);
    }

}

void Doctor::findPersonType() const
{
    std::cout<<"DOCTOR\n";
}
void Doctor::print() const
{
    std::cout<<"Dr. "<<getName()<<std::endl;

    if(medicalCertificateNumber != -1) std::cout<<"- Medical Certificate Number: "<<medicalCertificateNumber<<std::endl;
    else std::cout<<"- Medical Certificate Number: Unknown"<<std::endl;

    std::cout<<"- Speciality: "<<speciality<<std::endl;

    std::cout<<"\n- Patients:\n";
    if(patients.size() == 0)   std::cout<<"Has no patients right now!\n";
    else
    {
        for(int i = 0; i < patients.size(); i++)
        {
            std::cout<<std::setw(5)<< i + 1 <<". " <<patients[i]<<std::endl;
        }
    }
}
int Doctor::getMedCertificateNumber()const
{
    return medicalCertificateNumber;
}
void Doctor::addPatient(Patient &patient)
{
    if(strcmp(patient.getAttendingDoctor(),  this->name) == 0)
    {
        char *patientName = new char[strlen(patient.getName()) + 1];
        strcpy(patientName, patient.getName());

        patients.push_back(patientName);

        delete [] patientName;
    }
}
