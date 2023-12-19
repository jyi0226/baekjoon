#include <iostream>
using namespace std;
long long n;
int main()
{
    cin>>n;
    if(n==1||n==2){
        cout<<1;
        return 0;
    }
    else if(n==3){
        cout<<1;
        return 0;
    }
    long long i=1;
    while(1){
        long long a=i*(i+2);
        i++;
        long long b=i*(i+2);
        if(n>a&&n<=b){
            cout<<i;
            return 0;
        }
        else if(n==a){
            cout<<i-1;
            return 0;
        }
    }
}
