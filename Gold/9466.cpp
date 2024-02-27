#include <iostream>
using namespace std;

int n,t,ans;
int nt[101010];
bool vis[101010];
bool done[101010];
void func(int cur){
    vis[cur]=1;
    int val=nt[cur];
    
    if(!vis[val])func(val);
    else{
        if(!done[val]){
            for(int i=val;i!=cur;i=nt[i]){
                ans++;
            }
            ans++;
        }
    }
    done[cur]=1;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>nt[i];
            vis[i]=0;
            done[i]=0;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i])func(i);
        }
        cout<<n-ans<<"\n";
    }
}
