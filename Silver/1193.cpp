#include <iostream>
using namespace std;
int n,a=2,cnt=0;
int main()
{
    cin>>n;
    while(1){
        if(a%2==0){
            for(int i=1;i<a;i++){
                cnt++;
                if(cnt==n){
                    cout<<a-i<<"/"<<i;
                    return 0;
                }    
            }
            
        }
        else{
            for(int i=1;i<a;i++){
                cnt++;
                if(cnt==n){
                    cout<<i<<"/"<<a-i;
                    return 0;
                }
            }
        }
        
        a++;
    }
}
