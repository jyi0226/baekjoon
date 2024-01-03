#include <iostream>

using namespace std;
long long arr[5][5],res[5][5],temp[5][5];
int n;
long long b;
void func(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            long long sum=0;
            for(int k=0;k<n;k++)sum+=res[i][k]*arr[k][j];
            temp[i][j]=sum%1000;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res[i][j]=temp[i][j];
        }
    }
}
void power(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            long long sum=0;
            for(int k=0;k<n;k++)sum+=arr[i][k]*arr[k][j];
            temp[i][j]=sum%1000;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=temp[i][j];
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>b;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
        res[i][i]=1;
    }
    while(b>0){
        if(b%2==1)func();
        power();
        b/=2;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cout<<res[i][j]<<" ";
        cout<<"\n";
    }
}
