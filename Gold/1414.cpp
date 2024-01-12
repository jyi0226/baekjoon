#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int a,b,res=0,cnt=0,sum=0;
char len;
int p[55];
vector<pair<int,pair<int,int>>> line;

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
    
    cin>>n;
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>len;
            if(len=='0')continue;
            else{
                int val=0;
                if(len-'a'<0)val=len-'A'+27;
                else val=len-'a'+1;
                sum+=val;
                line.push_back({val,{i,j}});
            }
        }
    }
    
    sort(line.begin(),line.end());
    for(int i=0;i<line.size();i++){
        a=line[i].second.first;
        b=line[i].second.second;
        //sum+=line[i].first;
        if(find_p(a)==find_p(b))continue;
        
        res+=line[i].first;
        union_p(a,b);
        cnt++;
        
        if(cnt==n-1)break;
    }
    for(int i=1;i<n;i++){
        if(find_p(i)!=find_p(i+1)){
            cout<<-1;
            return 0;
        }
    }
    cout<<sum-res;
}
