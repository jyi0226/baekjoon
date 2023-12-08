#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int p[101];
int find_p(int x){
    if(x==p[x])return p[x];
    return p[x]=find_p(p[x]);
}
void union_p(int x,int y){
    x=find_p(x);
    y=find_p(y);
    
    if(x>y)p[x]=y;
    else p[y]=x;
}
double star[101][2];
int n;
vector<pair<double,pair<int,int>>> v;
void make_line(int n){
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=n;i++){
        cin>>star[i][0]>>star[i][1];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            double x=star[i][0],xx=star[j][0],y=star[i][1],yy=star[j][1];
            double val=sqrt((xx-x)*(xx-x)+(yy-y)*(yy-y));
            
            v.push_back({val,{i,j}});
        }
    }
    sort(v.begin(),v.end());
}

double kruskal(double cnt){
    for(int i=0;i<v.size();i++){
        int a=v[i].second.first;
        int b=v[i].second.second;
        double val=v[i].first;
        if(find_p(a)==find_p(b))continue;
        cnt+=val;
        union_p(a,b);
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    make_line(n);
    cout<<fixed;
    cout.precision(2);
    cout<<kruskal(0);
}
