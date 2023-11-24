#include <iostream>
#include <algorithm>
using namespace std;
int n,res=10101010;
int color[1010][3];
int d[1010][3];
int main()
{
    cin>>n;

   
    for(int i=0;i<n;i++){
        cin>>color[i][0]>>color[i][1]>>color[i][2];
    }
    d[0][0]=color[0][0];
    for(int s=0;s<3;s++){
        int d[1010][3];
        for(int i=0;i<3;i++){
            if(i==s)d[0][i]=color[0][i];
            else d[0][i]=res;
        }
        for(int i=1;i<n;i++){
            d[i][0]=min(d[i-1][1],d[i-1][2])+color[i][0];
            d[i][1]=min(d[i-1][0],d[i-1][2])+color[i][1];
            d[i][2]=min(d[i-1][1],d[i-1][0])+color[i][2];
        }
        for(int i=0;i<3;i++){
            if(i==s)continue;
            else res=min(res,d[n-1][i]);
        }
    }
    cout<<res;
}
