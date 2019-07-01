#ifndef HOSPITALS_H_INCLUDED
#define HOSPITALS_H_INCLUDED

#include<vector>
#include"Hospital.h"
struct date
{
    int year, month, day;
};

std::string getCurrentDate();
int findComponentsOfDate(const char*, char, int&);
date to_date(const char*);
void isDischarged(const char*);

class HOSPITALS
{
public:
    HOSPITALS();
    HOSPITALS(std::vector<Hospital>& );

    void findHospitalByDoctor(int); //by med certificate number
    void findHospitalByNurse(const char*);  //by nursing certificate number
    void printHospitalsWherePatientHasBeen(const char*, int);

    void isDischargedORAttendingDoctorPatientFromGivenHospital(int, const char*, int, int);

    void addHospital(Hospital&);

    int countOfHospitals()const;

    void print()const;
private:
    std::vector<Hospital> hospitals;

    std::vector<std::string> findHospitalsWherePatientHasBeen(const char*, int);  //by name and age

};

#endif // HOSPITALS_H_INCLUDED
