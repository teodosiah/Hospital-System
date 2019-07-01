#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include<vector>
#include<string>

#include"Read Information.h"
#include"Hospital.h"
#include"HOSPITALS.h"
#include "ConsoleColor.h"

void optionValidation(int option)
{
    while(option < 1 || option > 6)
    {
        std::cout<<red<<"\nWrong option number!!!"<<white<<"Enter number between 1 and 6: ";
        std::cin>>option;
    }
}
void subOptionValidation(int subOption)
{
    while(subOption < 1 || subOption > 4)
    {
        std::cout<<red<<"\nWrong option number!!!"<<white<<"Enter number between 1 and 4: ";
        std::cin>>subOption;
    }
}
template <typename T>
void cinInformation(T& value)
{
    std::cin>>value;
    return;
}

void executeMainMenu()
{
    std::cout<<red<<"MENU: \n"<<white;
    for(int i = 0; i < 6; i++)
    {
        std::cout<<red<<i + 1<<". "<<white<<"If you want to ";
        switch(i)
        {
        case 0:
            std::cout<<"CLOSE the program\n";
            break;
        case 1:
            std::cout<<"see COUNT of all hospitals\n";
            break;
        case 2:
            std::cout<<"see LIST of all hospitals\n";
            break;
        case 3:
            std::cout<<"find hospital BY DOCTOR\n";
            break;
        case 4:
            std::cout<<"find hospital BY NURSE\n";
            break;
        case 5:
            std::cout<<"find all hospitals where PATIENT HAS BEEN\n";
            break;

        }
    }
    std::cout<<"\nPlease"<<green<<" enter the number of your choice"<<white<<"(integer between 1 and 6)\nand you will see the information or more options: ";
}
void executeSubMenuForPatient()
{
    std::cout<<green<<"\nYou can choose between the following options: \n"<<white;
    for(int i = 0; i < 4; i++)
    {
        std::cout<<green<<i + 1<<". "<<white<<"If you want to ";

        switch(i)
        {
        case 0:
            std::cout<<"CLOSE the program\n";
            break;
        case 1:
            std::cout<<"GO BACK to main menu\n";
            break;
        case 2:
            std::cout<<"see if this patient IS DISCHARGED from hospital by your choice from the list\n";
            break;
        case 3:
            std::cout<<"see the ATTENDING DOCTOR of this patient in hospital by your choice from the list\n";
            break;
        }
    }
    std::cout<<"\nPlease"<<green<<" enter the number of your choice"<<white<<"(integer between 1 and 4)\nand you will see the information or more options: ";
}

void patientMenuRun(const char* name, int &age, HOSPITALS &hospitalData);
void optionFindByNurse(HOSPITALS &hospitalData)
{
    std::cout<<"\nPlease enter valid"<<red<<" nursing certificate number "<<white<<"of the nurse: ";
    std::string nursingNumber;
    cinInformation(nursingNumber);
    hospitalData.findHospitalByNurse(nursingNumber.c_str());
}
void optionFindByPatient(HOSPITALS &hospitalData)
{
    std::cout<<"\nPlease enter "<<red<<"name and age "<<white<<"of the patient: \nName: ";
    char name [50];
    std::cin.ignore();
    std::cin.getline(name, 49, '\n');
    std::cout<<"\nAge: ";
    int age;
    cinInformation(age);
    hospitalData.printHospitalsWherePatientHasBeen(name, age);

    std::cout<<"\nDo you want to see more options? y/n: ";
    char answer;
    cinInformation(answer);
    if(answer == 'y')
    {
        executeSubMenuForPatient();
        patientMenuRun(name, age, hospitalData);
    }

}
void mainMenuRun(HOSPITALS &hospitalData)
{
    int option;
    std::cin>>option;
    optionValidation(option);

    while(option != 1)
    {
        switch(option)
        {
        case 2:
            std::cout<<"Count of hospitals: "<<yellow<<hospitalData.countOfHospitals()<<white;
            break;
        case 3:
            hospitalData.print();
            break;
        case 4:
            std::cout<<"\nPlease enter valid"<<red<<" medical certificate number "<<white<<"of the doctor: ";
            int medicalCertificateNumber;
            cinInformation(medicalCertificateNumber);
            hospitalData.findHospitalByDoctor(medicalCertificateNumber);
            break;
        case 5:
            optionFindByNurse(hospitalData);
            break;
        case 6:
            optionFindByPatient(hospitalData);
            break;

        }

        std::cout<<red<<"\nPlease enter option from main manu (number between 1 and 6): "<<white;
        break;

    }
    if(option == 1) exit(0);
    mainMenuRun(hospitalData);
}
void patientMenuRun(const char* name, int &age, HOSPITALS &hospitalData)
{
    int subOption;
    std::cin>>subOption;

    while(subOption != 1 && subOption!= 2)
    {
        std::cout<<"\nPlease enter the number before the hospital you want to check out: ";
        int number;
        std::cin>>number;
        switch(subOption)
        {
        case 3:
            hospitalData.isDischargedORAttendingDoctorPatientFromGivenHospital(number, name, age, 0);
            break;
        case 4:
            hospitalData.isDischargedORAttendingDoctorPatientFromGivenHospital(number, name, age, 1);
            break;
        }

        std::cout<<green<<"\nPlease enter option from manu (number between 1 and 4): "<<white;
        break;

    }
    if(subOption == 1) exit(0);
    if(subOption == 2)
    {
        executeMainMenu();
        mainMenuRun(hospitalData);
        exit(0);
    }

    patientMenuRun(name, age, hospitalData);


}
void run(const char* fileName)
{
    std::vector<Hospital> hospitals;
    readingInformationFromFile(fileName, hospitals);
    HOSPITALS hospitalData(hospitals);

    executeMainMenu();
    mainMenuRun(hospitalData);

}



#endif // INPUT_H_INCLUDED
