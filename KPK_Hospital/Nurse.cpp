#include"NurseValidetion.h"
#include"Nurse.h"

Nurse::Nurse()
    :Person()
{
    department = " ";
    nursingCertificateNumber = " ";
}
Nurse::Nurse(const char* name, const char* depertment, const char* nursingCertificateNumber)
    :Person(name)
{
    setDepartment(depertment);
    setNursingCertificateNumber(nursingCertificateNumber);

}
Nurse::~Nurse()
{
    delete [] this->department;
    delete [] this->nursingCertificateNumber;
}
Nurse::Nurse(const Nurse& other)
    :Person(other.name)
{
    setDepartment(other.department);
    setNursingCertificateNumber(other.nursingCertificateNumber);
}
Nurse& Nurse::operator=(const Nurse& other)
{
    if(this != &other)
    {
        Person::operator=(other);

        setDepartment(other.department);
        setNursingCertificateNumber(other.nursingCertificateNumber);
    }
    return *this;
}

void Nurse::setDepartment(const char* department)
{
    if(this->department != NULL)
    {
        delete [] this->department;
    }
    if(!isDepartmentValid(department) || strcmp(department, " ") == 0)
    {
        this->department = new char[strlen("Unknown") + 1];
        strcpy(this->department, "Unknown");
    }
    this->department = new char[strlen(department) + 1];
    strcpy(this->department, department);
}
void Nurse::setNursingCertificateNumber(const char* nursingCertificateNumber)
{
    if(this->nursingCertificateNumber != NULL)
    {
        delete [] this->nursingCertificateNumber;
    }
    if(!isValidNursingCertificateNumber(nursingCertificateNumber) || strcmp(nursingCertificateNumber, " ") == 0)
    {
        this->nursingCertificateNumber = new char[strlen("Unknown") + 1];
        strcpy(this->nursingCertificateNumber, "Unknown");
    }
    this->nursingCertificateNumber = new char[strlen(nursingCertificateNumber) + 1];
    strcpy(this->nursingCertificateNumber, nursingCertificateNumber);
}

const char* Nurse::getNursingCertificateNumber()const
{
    return nursingCertificateNumber;
}
void Nurse::findPersonType() const
{
    std::cout<<"NURSE\n";
}
void Nurse::print() const
{
    std::cout<<getName()<<std::endl;

    std::cout<<"- Department: "<<department<<std::endl;

    std::cout<<"- Nursing Certificate Number: "<<nursingCertificateNumber<<std::endl;
}
