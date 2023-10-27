#include "RealGirl.hpp"
#include "Proxy.hpp"
#include<limits.h>
#include<float.h>
int main()
{
    Girl *girl = new RealGirl("婷婷");
    Proxy *proxy = new Proxy(girl);
    proxy->marry(12341234);

    return 0;
}
