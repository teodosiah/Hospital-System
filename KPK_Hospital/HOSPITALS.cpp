#include <iomanip>
#include<cstring>
#include <ctime>
#include<sstream>
#include <stdlib.h>
#include"HOSPITALS.h"
#include "ConsoleColor.h"
template <typename T>
std::string to_string(T value)
{
    //create an output string stream
    std::ostringstream os ;

    //throw the value into the string stream
    os << value ;

    //convert the string stream into a string and return
    return os.str() ;
}
std::string getCurrentDate()
{
    // Declaring argument for time()
    time_t now;
    // Declaring variable to store return value of
    // localtime()
    struct tm * local_tm;
    // Applying time()
    time (&now);
    // Using localtime()
    local_tm = localtime(&now);

    std::string year = to_string(1900 + local_tm->tm_year);
    std::string month = to_string(1 + local_tm->tm_mon);
    std::string day = to_string(local_tm->tm_mday);

    return year + " " + month + " " +day;
}
int findComponentsOfDate(const char* DATE, char to_symbol, int& index)
{
    char num[5];
    int i = 0;
    while(DATE[index] != to_symbol)
    {
        num[i] = DATE[index];
        index++;
        i++;

    }
    num[i] = '\0';
    return atoi(num);
}
date to_date(const char* DATE)
{
    date result_date;
    int index = 0;

    //find year
    result_date.year = findComponentsOfDate(DATE, ' ', index);
    index++; // skip the space

    //find month
    result_date.month = findComponentsOfDate(DATE, ' ', index);
    index++; // skip the space

    //find day
    result_date.day = findComponentsOfDate(DATE, '\0', index);

    return result_date;
}
void isDischarged(const char* dateOfDischarge)
{
    bool flag = true;
    if(strcmp(dateOfDischarge, "Unknown") == 0)
    {
        std::cout<<red<<"There is no information!\n"<<white;
        return;
    }
    else
    {
        std::string currDate = getCurrentDate();
        date currentDate = to_date(currDate.c_str());
        date dischargeDate = to_date(dateOfDischarge);
        if(currentDate.year < dischargeDate.year)
        {
            flag = false;
        }
        else if(currentDate.year == dischargeDate.year)
        {
            // if they're equals compare by months
            if(currentDate.month < dischargeDate.month)
            {
                flag = false;
            }
            else if(currentDate.month == dischargeDate.month)    //compare by days
            {
                if(currentDate.day < dischargeDate.day)
                {
                    flag = false;
                }
            }
        }
    }
    if(flag) std::cout<<red<<"The patient is discharged!\n"<<white;
    else std::cout<<red<<"The patient is NOT discharged!\n"<<white;
}
HOSPITALS::HOSPITALS()
{
}
HOSPITALS::HOSPITALS(std::vector<Hospital>& hospitals)
{
    this->hospitals = hospitals;
}

void HOSPITALS::findHospitalByDoctor(int medicalCertificateNumber)
{
    bool found = false;
    for(int i = 0; i < hospitals.size(); i++)
    {
        std::vector<Doctor> doctors = hospitals[i].getDoctors();
        for(int j = 0; j < doctors.size(); j++)
        {
            if(doctors[i].getMedCertificateNumber() == medicalCertificateNumber)
            {
                std::cout<<yellow<<hospitals[i].getName()<<white<<std::endl;
                found = true;
                break;
            }
        }
        if(found) break;
    }
    if(!found) std::cout<<"Has no such doctor!\n";
}
void HOSPITALS::findHospitalByNurse(const char* nursingCertificateNumber)
{
    bool found = false;
    for(int i = 0; i < hospitals.size(); i++)
    {
        std::vector<Nurse> nurses = hospitals[i].getNurses();
        for(int j = 0; j < nurses.size(); j++)
        {
            if(strcmp(nurses[i].getNursingCertificateNumber(),nursingCertificateNumber) == 0)
            {
                std::cout<<yellow<<hospitals[i].getName()<<white<<std::endl;
                found = true;
                break;
            }
        }
        if(found) break;
    }
    if(!found) std::cout<<"Has no such nurse!\n";
}
std::vector<std::string> HOSPITALS::findHospitalsWherePatientHasBeen(const char* name, int age)
{
    std::vector<std::string> hospitalsNames;

    for(int i = 0; i < hospitals.size(); i++)
    {
        std::vector<Patient> patients = hospitals[i].getPatients();
        for(int j = 0; j < patients.size(); j++)
        {
            if(strcmp(patients[j].getName(),name) == 0 && patients[j].getAge() == age)
            {
                hospitalsNames.push_back(hospitals[i].getName());
                break;
            }
        }
    }
    return hospitalsNames;
}
void HOSPITALS::printHospitalsWherePatientHasBeen(const char* name, int age)
{
    std::vector<std::string> hospitalsNames = findHospitalsWherePatientHasBeen(name, age);

    if(hospitalsNames.empty()) std::cout<<"Has no such patient!\n";
    else
    {
        for(int i = 0; i < hospitalsNames.size(); i++)
        {
            std::cout<<red<<i+1<<". "<<white<<hospitalsNames[i]<<std::endl;
        }
    }

}
void HOSPITALS::isDischargedORAttendingDoctorPatientFromGivenHospital(int hospitalIndex, const char* name, int age, int option)
{
    hospitalIndex--;
    std::vector<std::string> hospitalsNames = findHospitalsWherePatientHasBeen(name, age);
    if(hospitalsNames.empty()) std::cout<<"Has no such patient!\n";
    else if(hospitalIndex < 0 || hospitalIndex >= hospitalsNames.size())
    {
        std::cout<<"Wrong index! You will see for the first hospital from the list\n";
        isDischargedORAttendingDoctorPatientFromGivenHospital(1, name, age, option);
    }
    else
    {
        for(int i = 0; i < hospitals.size(); i++)
        {
            if(strcmp(hospitalsNames[hospitalIndex].c_str(), hospitals[i].getName()) == 0)
            {
                std::vector<Patient> patients = hospitals[i].getPatients();
                for(int j = 0; j < patients.size(); j++)
                {
                    if(strcmp(name, patients[j].getName()) == 0 && age == patients[j].getAge())
                    {
                        if(option == 0) isDischarged(patients[j].getDateOfDischarge());
                        else if(option == 1) std::cout<<yellow<<patients[j].getAttendingDoctor()<<white;;
                    }
                }
            }
        }
    }
}
void HOSPITALS::addHospital(Hospital& newHospital)
{
    hospitals.push_back(newHospital);
}
int HOSPITALS::countOfHospitals()const
{
    return hospitals.size();
}

void HOSPITALS::print()const
{
    std::cout<<"Total: "<<countOfHospitals()<<std::endl;
    std::cout<<"===============================================\n";
    if(hospitals.size() == 0) std::cout<<"Has no hospitals!\n";
    else
    {
        for(int i = 0; i < hospitals.size(); i++)
        {
            std::cout<<"...............................................\n";
            hospitals[i].print();
            std::cout<<"Doctors: "<<hospitals[i].findCountOfDoctors()<<"  Nurses: "<<hospitals[i].findCountOfNurses()<<"  Patients: "<<hospitals[i].findCountOfPatients()<<std::endl;
            std::cout<<"...............................................\n";
        }
    }
}
