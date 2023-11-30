#include <iostream>
#include <algorithm>
using namespace std;
int e,s,m;
int main()
{
    cin>>e>>s>>m;
    for(int i=1;i<10000;i++){
        if((i-e)%15==0&&(i-s)%28==0&&(i-m)%19==0){
            cout<<i;
            break;
        }
    }
}
