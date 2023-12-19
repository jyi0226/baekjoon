#include <iostream>
using namespace std;


bool prime[1010101]={1,1,0,0,};
int prime_num[1010101];
int prime_cnt=0;
int n,num;
void func(){
    for(int i=2;i<=1000000;i++){
        if(!prime[i]){
            prime_num[prime_cnt++]=i;
            for(int j=2;i*j<=1000000;j++)prime[i*j]=1;
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    func();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        int cnt=0;
        int val=0;
        while(1){
            int a=prime_num[cnt];
            int b=num-a;
            if(a>b)break;
            if(!prime[b]){
                val++;
            }
            cnt++;
        }
        cout<<val<<"\n";
    }
}
