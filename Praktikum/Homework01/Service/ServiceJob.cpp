#include "ServiceJob.h"

ServiceJob::ServiceJob()
{
    timeLength = 0;
    eServiceType = None;
}

ServiceJob::ServiceJob(double newTimeLength, serviceType newServiceType)
{
    timeLength = newTimeLength;
    eServiceType = newServiceType;
}

ServiceJob::ServiceJob(const ServiceJob& other)
{
    this -> timeLength = other.timeLength;
    this -> eServiceType = other.eServiceType;
}

ServiceJob& ServiceJob::operator=(const ServiceJob& other)
{
    if (this != &other)
    {
        this -> timeLength = other.timeLength;
        this -> eServiceType = other.eServiceType;
    }
    return *this;
}

double ServiceJob::GetServiceJobPrice(const ServiceJob&)
{
    switch(eServiceType)
    {
    case 0:
        return 0;
        break;
    case 1:
        return 10 * timeLength;
        break;
    case 2:
        return 50 * timeLength;
        break;
    case 3:
        return 75 * timeLength;
        break;
    default:
        return 0;
    }
}

ServiceJob::~ServiceJob()
{}
