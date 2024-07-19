#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

long long INF=1000000000,res=1;
vector<int> prime;
bool vis[40404];
int n,m;
map<int,int> a,b;
bool flag=0;

void func(int num,char w){
    if(w=='a'){
        for(auto o : prime){
            if(num%o==0){
                a[o]++;
                func(num/o,'a');
                return;
            }
        }
        if(num!=1)a[num]++;
    }
    else{
        for(auto o : prime){
            if(num%o==0){
                b[o]++;
                func(num/o,'b');
                return;
            }
        }
        if(num!=1)b[num]++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i=2;i<40000;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(int j=1;i*j<=40000;j++){
                vis[i]=1;
            }
        }
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        func(m,'a');
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        func(m,'b');
    }
    
    for(auto o : a){
        if(!b[o.first])continue;
        
        int cnt=min(o.second,b[o.first]);
        
        while(cnt--){
            res*=o.first;
            if(res>=INF){
                res%=INF;
                flag=1;
            }
        }
    }
    if(flag){
        printf("%09lld",res);
    }
    else cout<<res;
}
