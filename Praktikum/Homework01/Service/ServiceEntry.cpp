#include "ServiceEntry.h"
#include "ServiceJob.h"

ServiceEntry::ServiceEntry()
{
    name = '\0';
    uniqueID = 0;
    regPlate = '\0';
    eCarBrand = Nothing;
    eClientType = NaN;
    listServiceJob = NULL;
}

ServiceEntry::ServiceEntry(char* name, int newUniqueID, char* regPlate, carBrand newCarBrand, clientType newClientType, ServiceJob* newListServiceJob)
{
    this -> name = new char [strlen(name) + 1];
    strcpy(this -> name, name);
    uniqueID = newUniqueID;
    this -> regPlate = new char [strlen(regPlate) + 1];
    strcpy(this -> regPlate, regPlate);
    eCarBrand = newCarBrand;
    eClientType = newClientType;
    this -> listServiceJob = new ServiceJob [sizeof(newListServiceJob) / sizeof(ServiceJob)];
}

ServiceEntry::ServiceEntry (const ServiceEntry& other)
{
    this -> name = new char [strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this -> uniqueID = other.uniqueID;
    this -> regPlate = new char [strlen(other.regPlate) + 1];
    strcpy(this->regPlate, other.regPlate);
    this -> eCarBrand = other.eCarBrand;
    this -> eClientType = other.eClientType;
    this -> listServiceJob = new ServiceJob [sizeof(other.listServiceJob) / sizeof(ServiceJob)];
}

ServiceEntry& ServiceEntry::operator=(const ServiceEntry& other)
{
    if (this != &other)
    {
        delete[] this->name;
        delete[] this->regPlate;
        delete[] this->listServiceJob;

        this -> name = new char [strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this -> uniqueID = other.uniqueID;
        this -> regPlate = new char [strlen(other.regPlate) + 1];
        strcpy(this->regPlate, other.regPlate);
        this -> eCarBrand = other.eCarBrand;
        this -> eClientType = other.eClientType;
        this -> listServiceJob = new ServiceJob [sizeof(other.listServiceJob) / sizeof(ServiceJob)];
    }
    return *this;
}

ServiceEntry::~ServiceEntry()
{
    delete[] this->name;
    delete[] this->regPlate;
    delete[] this->listServiceJob;
}

char* ServiceEntry::getName() const
{
    return this->name;
}

int ServiceEntry::getID() const
{
    return this->uniqueID;
}

char* ServiceEntry::getRegPlate() const
{
    return this->regPlate;
}

carBrand ServiceEntry::getCarBrand() const
{
    return this->eCarBrand;
}

clientType ServiceEntry::getClientType() const
{
    return this->eClientType;
}

ServiceJob* ServiceEntry::getListSJ() const
{
    return this->listServiceJob;
}

void ServiceEntry::setName(char* newName)
{
    delete[] this->name;

    if(newName)
    {
        size_t len = strlen(newName);
        if(len != 0)
        {
            name = new char [len + 1];
            strcpy(name, newName);
        }
        else
        {
            name = new char [1];
            name = '\0';
        }
    }
}

void ServiceEntry::setID(int newUniqueID)
{
    this -> uniqueID = newUniqueID;
}

void ServiceEntry::setRegPlate(char* newRegPlate)
{
    delete[] this->regPlate;

    if(newRegPlate)
    {
        size_t len = strlen(newRegPlate);
        if(len != 0)
        {
            regPlate = new char [len + 1];
            strcpy(regPlate, newRegPlate);
        }
        else
        {
            regPlate = new char [1];
            regPlate = '\0';
        }
    }
}

void ServiceEntry::setCarBrand(carBrand newCarBrand)
{
    this->eCarBrand = newCarBrand;
}

void ServiceEntry::setClientType(clientType newClientType)
{
    this->eClientType = newClientType;
}

void ServiceEntry::setServiceJob(ServiceJob* newServiceJob)
{
    delete[] this->listServiceJob;

    this -> listServiceJob = new ServiceJob [sizeof(newServiceJob) / sizeof(ServiceJob)];
}

void ServiceEntry::printInfo()
{
    cout<<"Name:";
    cout<<getName()<<endl;
    cout<<"ID:";
    cout<<getID()<<endl;
    cout<<"Registration plate:";
    cout<<getRegPlate()<<endl;
    cout<<"Car brand:";
    switch(eCarBrand)
    {
    case 0:
        cout<<"None"<<endl;
        break;
    case 1:
        cout<<"Subaru"<<endl;
        break;
    case 2:
        cout<<"Volkswagen"<<endl;;
        break;
    case 3:
        cout<<"Renault"<<endl;
        break;
    case 4:
        cout<<"Nissan"<<endl;
        break;
    case 5:
        cout<<"BMW"<<endl;
        break;
    default:
        cout<<"Error"<<endl;
    }
    cout<<"Type client:";
    switch(eClientType)
    {
    case 0:
        cout<<"None"<<endl;
        break;
    case 1:
        cout<<"Private"<<endl;
        break;
    case 2:
        cout<<"Firm"<<endl;
        break;
    case 3:
        cout<<"Client with preferences"<<endl;
        break;
    default:
        cout<<"Error"<<endl;
    }
    cout<<"Repairs:"<<endl;
    cout<<endl;
    for (int i=0; i < 2 ; i++)
    {
        cout<<"Index:"<<i<<endl;
        cout<<"Repair type:";
        switch(listServiceJob[i].eServiceType)
        {
        case 0:
            cout<<"None"<<endl;
            break;
        case 1:
            cout<<"Maintenance"<<endl;
            break;
        case 2:
            cout<<"Engine"<<endl;
            break;
        case 3:
            cout<<"Suspension"<<endl;
            break;
        default:
            cout<<"Error"<<endl;
        }
        cout<<"Repair price:";
        cout<<listServiceJob[i].GetServiceJobPrice(listServiceJob[i]);
        cout<<endl;
    }

}

double ServiceEntry::GetTotalPrice() // Недовършена
{
    double sum = 0;
    if (eClientType == Private)
    {
        for (int i = 0; ; i++)
        {
            switch (listServiceJob[i].eServiceType)
            {
            case 2:
                sum += listServiceJob[i].GetServiceJobPrice(listServiceJob[i]) - 5 * listServiceJob[i].GetServiceJobPrice(listServiceJob[i])/100;
                break;
            }
        }
    }

    return sum;
}
