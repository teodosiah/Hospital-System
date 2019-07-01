#ifndef READ_INFORMATION_H_INCLUDED
#define READ_INFORMATION_H_INCLUDED
#include<fstream>
#include<iostream>
#include <stdlib.h>
#include<cstring>
std::string processingHospitalName(std::string &inputName)
{
    std::string name;
    int i = 0, j = 0;
    while(inputName[i] != ' ')
    {
        i++;
    }
    i++;
    while(i < inputName.size())
    {
        name += inputName[i];
        //name[j] = inputName[i];
        //j++;
        i++;
    }
    return name;
}
void stringToSymbol(std::string &inputString,std::string &outputString, int &fromIndex, char toSymbol)
{
    int j = 0;
    if(fromIndex >= inputString.length())
    {
        outputString = " ";
        return;
    }
    while(inputString[fromIndex] == ' ')
    {
        fromIndex++;
    }

    while(inputString[fromIndex] != toSymbol && inputString[fromIndex] != '\0')
    {
        outputString+=inputString[fromIndex];
        fromIndex++;
    }
    fromIndex++;
}

void readingInformationFromFile(const char* fileName, std::vector<Hospital>& hospitals)
{
    std::ifstream read;
    std::string line;
    int i = -1;
    read.open (fileName);

    while(getline(read,line))  // To get you all the lines.
    {
        // Saves the line in STRING.
        if(line[0] >= '1' && line[0] <= '9')
        {
            i++;
            Hospital *hospital = new Hospital;
            hospitals.push_back(*hospital);
            std::string name = processingHospitalName(line);

            hospitals[i].setName(name.c_str());

        }
        else if(line[0] == 'D')
        {
            Doctor *doctor = new Doctor;
            int j = 2;

            std::string str;
            stringToSymbol(line, str, j, ',');
            doctor->setName(str.c_str());
            str.clear();

            stringToSymbol(line, str, j, ',');
            doctor->setMedicalCertificateNumber(atoi(str.c_str()));
            str.clear();

            stringToSymbol(line,str, j, '\n');
            doctor->setSpeciality(str.c_str());
            hospitals[i].addDoctor(*doctor);

        }
        else if(line[0] == 'N')
        {

            Nurse *nurse = new Nurse;
            int j = 2;

            std::string str;
            stringToSymbol(line, str, j, ',');
            nurse->setName(str.c_str());
            str.clear();

            stringToSymbol(line,str, j, ',');
            nurse->setDepartment(str.c_str());
            str.clear();

            stringToSymbol(line, str, j, '\0');
            nurse->setNursingCertificateNumber(str.c_str());

            hospitals[i].addNurse(*nurse);
        }
        else if(line[0] == 'P')
        {

            Patient *patient = new Patient;
            int j = 2;

            std::string str;
            stringToSymbol(line, str, j, ',');
            patient->setName(str.c_str());
            str.clear();

            stringToSymbol(line,str, j, ',');
            patient->setAge(atoi(str.c_str()));
            str.clear();

            stringToSymbol(line, str, j, ',');
            patient->setAttendingDoctor(str.c_str());
            str.clear();

            stringToSymbol(line,str, j, ',');
            patient->setDateOfAdmission(str.c_str());
            str.clear();

            stringToSymbol(line,str, j, ',');
            patient->setDateOfDischarge(str.c_str());
            str.clear();

            stringToSymbol(line, str, j, ',');
            patient->setDiagnosis(str.c_str());
            str.clear();

            std::vector<std::string> treatment;
            while(j < line.length())
            {
                stringToSymbol(line,str, j, ';');
                treatment.push_back(str);
                str.clear();
            }
            patient->setTreatment(treatment);

            hospitals[i].addPatient(*patient);
        }
    }

    read.close();

    //adding patients to doctor's list of patients
    for(int i = 0; i < hospitals.size(); i++)
    {
        hospitals[i].connectingDoctorsAndPatients();
    }
}


#endif // READ_INFORMATION_H_INCLUDED
