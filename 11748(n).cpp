#include <iostream>
#include <cmath>
using namespace std;
double rad[505];
int n;
double result=0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)cin>>rad[i];

    if(n==1)cout<<rad[n-1]*2;

    else if(n==2)
    {
        if(rad[0]+sqrt((rad[0]+rad[1])*(rad[0]+rad[1])-(rad[1]-rad[0])*(rad[1]-rad[0]))<rad[1])
        {
            cout<<rad[n-1]*2;
        }
        else
        {
            cout<<rad[0]+sqrt((rad[0]+rad[1])*(rad[0]+rad[1])-(rad[1]-rad[0])*(rad[1]-rad[0]))+rad[1];
        }
    }



    for(int i=1;i<n-1;i++)
    {

    }
}