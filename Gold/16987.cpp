#include <iostream>
#include <vector>
using namespace std;
int n,a,b;
vector<pair<int,int>> egg;

int res=0;
void func(int cur){
    if(cur==n){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(egg[i].first<=0)cnt++;
        }
        res=max(res,cnt);
        return;
    }
    if(egg[cur].first<=0)func(cur+1);
    else{
        bool val=0;
        for(int i=0;i<n;i++){
            if(i==cur||egg[i].first<=0)continue;

            egg[cur].first-=egg[i].second;
            egg[i].first-=egg[cur].second;
            val=1;
            func(cur+1);
            egg[cur].first+=egg[i].second;
            egg[i].first+=egg[cur].second;
        }
        if(!val)func(n);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        egg.push_back({a,b});
    }
    func(0);
    cout<<res;
}
