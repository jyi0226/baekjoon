#include <iostream>
#include <algorithm>
using namespace std;
int num[9];
int sum=0;
bool compare(int a,int b){
    return a<b;
}
int main()
{
    for(int i=0;i<9;i++){
        cin>>num[i];
        sum+=num[i];
        
    }sort(num,num+9,compare);
    for(int i=0;i<8;i++){
        sum-=num[i];
        for(int j=i+1;j<9;j++){
            sum-=num[j];
            if(sum==100){
                for(int k=0;k<9;k++){
                    if(k==i||k==j)continue;
                    cout<<num[k]<<"\n";
                }
                return 0;
            }
            sum+=num[j];
        }
        sum+=num[i];
    }
}
