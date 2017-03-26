#pragma once
#include <iostream>
#include <cstring>

using namespace std;

enum serviceType
{
    None,
    Maintenance,
    Engine,
    Suspension,
};


struct ServiceJob
{
    double timeLength;
    serviceType eServiceType;
    ServiceJob();
    ServiceJob(double newTimeLength, serviceType);
    ServiceJob(const ServiceJob& other);
    ServiceJob& operator=(const ServiceJob& other);
    ~ServiceJob();
    double GetServiceJobPrice (const ServiceJob&);
};

