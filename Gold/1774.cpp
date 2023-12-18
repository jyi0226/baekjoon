#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,a,b;
int p[1010];
vector<pair<double,pair<int,int>>> line;
vector<pair<double,double>> dot;
bool vis[1010][1010];
int find_p(int x){
    if(x==p[x])return x;
    return p[x]=find_p(p[x]);
}

void union_p(int x,int y){
    x=find_p(x);
    y=find_p(y);
    
    if(x<y)p[y]=x;
    else p[x]=y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        p[i+1]=i+1;
        cin>>a>>b;
        dot.push_back({a,b});
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            double x1=dot[i].first;
            double y1=dot[i].second;
            double x2=dot[j].first;
            double y2=dot[j].second;
            line.push_back({sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)),{i+1,j+1}});
        }
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        union_p(a,b);
    }
    sort(line.begin(),line.end());
    cout<<fixed;
    cout.precision(2);
    double res=0;
    int cnt=0;
    for(int i=0;i<line.size();i++){
        a=line[i].second.first;
        b=line[i].second.second;
        double cost=line[i].first;
        if(find_p(a)==find_p(b))continue;
        
        union_p(a,b);
        res+=cost;
        
        if(cnt==n-1)break;
    }
    cout<<res;
    /*for(int i=0;i<line.size();i++){
        cout<<line[i].first<<" "<<line[i].second.first<<" "<<line[i].second.second<<"\n";
    }*/
    
}
