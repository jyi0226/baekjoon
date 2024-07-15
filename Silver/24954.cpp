#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int price[11];
int n,c,a,b;
vector<pair<int,int>> dis[11];
int Min=99999999;
int val;
bool vis[11];

void print(){
    for(int i=1;i<=n;i++)cout<<price[i]<<" ";
    cout<<"\n";
}

void func(int cur){
    if(cur>=n){
        
        //print();
        Min=min(Min,val);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        
        vis[i]=1;
        if(price[i]<=0)val++;
        else val+=price[i];
        for(int j=0;j<dis[i].size();j++){
            price[dis[i][j].first]-=dis[i][j].second;
        }
        func(cur+1);
        if(price[i]<=0)val--;
        else val-=price[i];
        vis[i]=0;
        for(int j=0;j<dis[i].size();j++){
            price[dis[i][j].first]+=dis[i][j].second;
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>price[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c;
        if(c==0)dis[i].push_back({0,0});
        for(int j=0;j<c;j++){
            cin>>a>>b;
            dis[i].push_back({a,b});
        }
    }
    for(int i=1;i<=n;i++){
        val=0;
        vis[i]=1;
        if(price[i]<=0)val++;
        else val+=price[i];
        for(int j=0;j<dis[i].size();j++){
            price[dis[i][j].first]-=dis[i][j].second;
        }
        func(1);
        vis[i]=0;
        if(price[i]<=0)val--;
        else val-=price[i];
        for(int j=0;j<dis[i].size();j++){
            price[dis[i][j].first]+=dis[i][j].second;
        }
    }
    cout<<Min;
    
}
