#include <iostream>
using namespace std;
int n,a=2;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        a=2*a-1;
    }
    cout<<a*a;
}
