#ifndef DOCTORVALIDATION_H_INCLUDED
#define DOCTORVALIDATION_H_INCLUDED
bool isValidMedCertificateNumber(int medNumber)
{
    if(medNumber < 100000) return false;
    return true;
}
bool isSpecialityValid(const char* name)
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


#endif // DOCTORVALIDATION_H_INCLUDED
