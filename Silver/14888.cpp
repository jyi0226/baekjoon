#include <iostream>
int n,num[11],cal[4];
int arr[10],resMax=-1000000001,resMin=1000000001;

void func(int cur){
    if(cur==n-1){
        /*for(int i=0;i<cur;i++){
            if(arr[i]==2){
                int cnt=num[i]*num[i+1];
                num[i]=cnt;
                num[i+1]=cnt;
            }
            else if(arr[i]==3){
                int cnt=num[i]/num[i+1];
                num[i]=cnt;
                num[i+1]=cnt;
            } 
        }
        int tot=num[0];
        for(int i=0;i<cur;i++){
            if(arr[i]==0)tot+=num[i+1];
            else if(arr[i]==1)tot-=num[i+1];
        }*/
        int tot=num[0];
        for(int i=0;i<cur;i++){
            if(arr[i]==0)tot+=num[i+1];
            else if(arr[i]==1)tot-=num[i+1];
            else if(arr[i]==2)tot*=num[i+1];
            else tot/=num[i+1];
        }
        
        
        if(resMax<tot)resMax=tot;
        if(resMin>tot)resMin=tot;
    }
    for(int i=0;i<4;i++){
        if(cal[i]!=0){
            cal[i]--;
            arr[cur]=i;
            func(cur+1);
            cal[i]++;
        }
    }
}


using namespace std;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>num[i];
    for(int i=0;i<4;i++)cin>>cal[i];
    
    func(0);
    
    cout<<resMax<<"\n"<<resMin;
}
