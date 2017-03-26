#pragma once
#include "ServiceJob.h"

enum carBrand
{
    Nothing,
    Subaru,
    Volkswagen,
    Renault,
    Nissan,
    BMW,
};

enum clientType
{
    NaN,
    Private,
    Firm,
    Preferences,
};

class ServiceEntry
{
private:
    char* name;
    int uniqueID;
    char* regPlate;
    carBrand eCarBrand;
    clientType eClientType;
    ServiceJob* listServiceJob;
public:
    ServiceEntry();
    ServiceEntry(char* newName, int newUniqueID, char* newRegPlate, carBrand, clientType, ServiceJob* newListServiceJob);
    ServiceEntry(const ServiceEntry& other);
    ServiceEntry& operator=(const ServiceEntry& other);
    ~ServiceEntry();

    // Getters //////////////////////
    char* getName() const;
    int getID() const;
    char* getRegPlate() const;
    carBrand getCarBrand() const;
    clientType getClientType() const;
    ServiceJob* getListSJ() const;
    /////////////////////////////////

    // Setters ////////////////////////////////////
    void setName (char* newName);
    void setID (int newUniqueID);
    void setRegPlate (char* newRegPlate);
    void setCarBrand (carBrand newCarBrand);
    void setClientType (clientType newClientType);
    void setServiceJob (ServiceJob* newServiceJob);
    ///////////////////////////////////////////////

    void printInfo();

    double GetTotalPrice();

};
