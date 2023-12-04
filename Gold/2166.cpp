#include <iostream>
#include <cmath>
using namespace std;
int node[10101][2];
int n;
long double ans=0;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>node[i][0]>>node[i][1];
    }
    long double a=node[0][0];
    long double b=node[0][1];
    long double c,d,e,f;
    for(int i=1;i<n-1;i++){
        c=node[i][0];
        d=node[i][1];
        e=node[i+1][0];
        f=node[i+1][1];
        ans+=(a*d+c*f+e*b-b*c-d*e-a*f)/2;
    }
    cout<<fixed;
    cout.precision(1);
    cout<<abs(ans);
    
}
// 신발끈 공식을 이용해서 해결
