#include <bits/stdc++.h>
using namespace std;
int n;
int num[55];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);
    
    cin>>n;
    for(int i=0;i<n;i++)cin>>num[i];
    if(n==1)cout<<"A";
    else if(n==2){
        if(num[0]==num[1])cout<<num[0];
        else cout<<"A";
    }
    else{
        int a,b;
        int val=num[1]-num[0];
        if(val==0){
            for(int i=0;i<n;i++){
                if(num[i]!=num[0]){
                    cout<<"B";
                    return 0;
                }
            }
            cout<<num[0];
            return 0;
        }
        int val2=num[2]-num[1];
        int val3=num[3]-num[2],cur;
        if(val2==0){
            for(int i=1;i<n;i++){
                if(num[i]!=num[1]){
                    cout<<"B";
                    return 0;
                }
            }
            cout<<num[1];
            return 0;
        }
        /*bool symbol=0;
        if(val>=0){
            if(val2>=0)symbol=0;
            else symbol=1;
        }
        else{
            if(val2>=0)symbol=1;
            else symbol=0;
        }
        a=abs(val2)/abs(val);
        if(symbol)a*=-1;

        b=num[1]-num[0]*a;*/
        if(abs(val2)<abs(val))a=0;
        else a=val2/val;
        b=num[1]-num[0]*a;
        if(a==0){
            cout<<"B";
            return 0;
        }
        else{
            for(int i=1;i<n;i++){
                if(num[i]!=(num[i-1]*a+b)){
                    cout<<"B";
                    return 0;
                }
            }
            cout<<num[n-1]*a+b;
        }
    }
}
