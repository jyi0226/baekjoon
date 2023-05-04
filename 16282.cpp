#include <iostream>
using namespace std;
unsigned long long n;

int main()
{
    cin>>n;
    unsigned long long cnt=7,chain=1;
    while(cnt<n)
   {
        chain++;
        cnt=chain;
        for(int i=0;i<=chain;i++)
        {
            cnt+=(cnt+1);
        }
    }
        cout<<chain;
}