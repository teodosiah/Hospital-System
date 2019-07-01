#ifndef NURSEVALIDETION_H_INCLUDED
#define NURSEVALIDETION_H_INCLUDED
#include<cstring>
bool isValidNursingCertificateNumber(const char* nurseNumber)
{
    if(strlen(nurseNumber) < 4 || strlen(nurseNumber) > 6) return false;
    for(int i = 0; i < strlen(nurseNumber); i++)
    {
        if(!((nurseNumber[i] >= 'A' && nurseNumber[i] <= 'Z') ||
             (nurseNumber[i] >='0' && nurseNumber[i] <= '9') ) )
        {
            return false;
        }
    }
    return true;
}
bool isDepartmentValid(const char* name)
{
    for(int i = 0; i < strlen(name); i++)
    {
        if(!((name[i] >= 'A' && name[i] <= 'Z') ||
             (name[i] >='a' && name[i] <= 'z') ||
             (name[i] >='1' && name[i] <= '9') ||
              name[i] == ' '))
        {
            return false;
        }
    }
    return true;
}

#endif // NURSEVALIDETION_H_INCLUDED
