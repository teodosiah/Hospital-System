#ifndef HOSPITAL_H_INCLUDED
#define HOSPITAL_H_INCLUDED

#include<vector>

#include"Patient.h"
#include"Doctor.h"
#include"Nurse.h"

class Hospital
{
public:
    Hospital();
    Hospital(const char*, std::vector<Doctor>, std::vector<Nurse>, std::vector<Patient>);
    ~Hospital();
    Hospital(const Hospital&);
    Hospital& operator=(const Hospital&);

    void setName(const char*);

    void addPatient(Patient&);
    void addDoctor(Doctor&);
    void addNurse(Nurse&);

    int findCountOfDoctors()const;
    int findCountOfNurses()const;
    int findCountOfPatients()const;

    int getHospitalID() const;
    const char* getName() const;
    std::vector<Doctor> getDoctors()const;
    std::vector<Nurse> getNurses()const;
    std::vector<Patient> getPatients()const;

    void connectingDoctorsAndPatients();

    void print()const;

private:
    char* name;
    std::vector<Doctor> doctors;
    std::vector<Nurse> nurses;
    std::vector<Patient> patients;



};


#endif // HOSPITAL_H_INCLUDED
