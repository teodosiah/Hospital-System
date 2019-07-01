#ifndef HOSPITALVALIDATION_H_INCLUDED
#define HOSPITALVALIDATION_H_INCLUDED

#include<cstring>
bool isHospitalNameValid(const char* name)
{
    for(int i = 0; i < strlen(name); i++)
    {
        if(!((name[i] >= 'A' && name[i] <= 'Z') ||
             (name[i] >='a' && name[i] <= 'z') ||
              name[i] == ' '))
        {
            return false;
        }
    }
    return true;
}

#endif // HOSPITALVALIDATION_H_INCLUDED
