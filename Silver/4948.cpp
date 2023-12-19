#include <iostream>
using namespace std;


bool prime[250000]={1,1,0,0,};
void func(){
    for(int i=2;i<=250000;i++){
        if(!prime[i]){
            for(int j=2;i*j<=250000;j++)prime[i*j]=1;
        }
    }
}
int n;
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    func();
    while(1){
        cin>>n;
        if(n==0)break;
        int cnt=0;
        for(int i=n+1;i<=2*n;i++){
            if(!prime[i])cnt++;
        }
        cout<<cnt<<"\n";
    }
}
