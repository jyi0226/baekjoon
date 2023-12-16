#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int num[101][101],a=0,b=0,val=0;
int main()
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)cin>>num[i][j];
    }
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(val<num[i][j]){
                val=num[i][j];
                a=i;
                b=j;
            }
        }
    }
    cout<<val<<"\n"<<a+1<<" "<<b+1;
}
