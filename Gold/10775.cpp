#include <iostream>

int r[101010];
int find_r(int x){
    if(x==r[x])return x;
    return r[x]=find_r(r[x]);
}
void union_r(int x,int y){
    x=find_r(x);
    y=find_r(y);
    
    r[x]=y;
}
int g,p,plane;
using namespace std;

int main()
{
    cin>>g>>p;
    int res=0;
    for(int i=1;i<=g;i++)r[i]=i;
    for(int i=0;i<p;i++){
        cin>>plane;
        plane=find_r(plane);
        
        if(plane==0)break;
        
        union_r(plane,plane-1);
        res++;
    }
    cout<<res;
}
