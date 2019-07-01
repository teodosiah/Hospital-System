#ifndef VALIDATION_H_INCLUDED
#define VALIDATION_H_INCLUDED

#include<cstring>
// for names, diagnosis

bool isStringValid(const char* name)
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

bool isAgeValid(int age)
{
    if(age < 0 || age > 110) return false;
    return true;
}

bool isValidDate(const char* date)
{
    //valid date : yyyy m[m] d[d]
    int i = 1;
    //1st to 4th symbol are year -> numbers
    //but the 1st one cannot be 0
    if(date[0] < '1' || date[0] > '9') return false;
    while(i < 4)
    {
        if(date[i] < '0' || date[i] > '9') return false;
        i++;
    }
    if(date[4] != ' ') return false;
    if(date[5] < '0' || date[5] > '9') return false;
    if(date[6] >= '0' && date[6] <= '9')      //yyyy mm d[d]
    {
        if(date[7] != ' ') return false;
        if(date[8] < '0' || date[8] > '9') return false;
        if(date[9] != '\0' && (date[9] <'0' || date[9] >'9')) return false;
    }
    else if(date[6] == ' ')
    {
        if(date[7] < '0' || date[7] > '9') return false;
        if(date[8] != '\0' && (date[8] <'0' || date[8] >'9')) return false;
    }
    else return false;

    return true;
}


#endif // VALIDATION_H_INCLUDED
