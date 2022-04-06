#include <iostream>
#include "ZFraction.hpp"

using namespace std;

int main()
{
   
    ZFraction a(-4,4);
    ZFraction b(4,4);
    
    ZFraction c = b-a;
    
    cout<<c<<endl<<endl;

return 0;
}
