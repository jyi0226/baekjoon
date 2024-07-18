#include <iostream>
using namespace std;
int n,x,y;
int res=0;
int arr[25];
bool vis[13];

void func(int cur){
    if(cur>n){
        res++;
        return;
    }
    if(vis[cur])func(cur+1);
    else{
        int var=2*n-cur;
        for(int i=1;i<var;i++){
            int idx=i+cur+1;
            if(arr[i]==0&&arr[idx]==0){
                arr[i]=cur;
                arr[idx]=cur;
                func(cur+1);
                arr[i]=0;
                arr[idx]=0;
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>x>>y;
    int val=y-x-1;
    vis[val]=1;
    arr[x]=val;
    arr[y]=val;
    
    func(1);
    
    cout<<res;
    
}
