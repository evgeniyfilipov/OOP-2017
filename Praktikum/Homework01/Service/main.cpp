#include "ServiceJob.h"
#include "ServiceEntry.h"

int main()
{
    ServiceJob t1 (1, Engine);
    cout<<t1.GetServiceJobPrice(t1)<<endl;
    ServiceJob t2 (2, Suspension);
    ServiceJob t3 [2] = {t1, t2};
    ServiceEntry t4("shefa", 9669, "CA999999", Subaru, Private, t3);

    t4.printInfo();

    return 0;
}
