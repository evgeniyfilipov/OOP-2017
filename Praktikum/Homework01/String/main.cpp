#include "String.h"

int main()
{
    String test("abc", 3);

    test.setStr("bca");

    cout<<test.GetStr()<<endl;

    return 0;
}
