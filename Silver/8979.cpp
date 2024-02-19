#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,k;
int a,b,c,d;
struct pos{
    int x,y,z,idx;
};

vector<pos> v;

bool comp(pos a,pos b){
    if(a.x==b.x){
        if(a.y==b.y){
            return a.z>b.z;
        }
        return a.y>b.y;
    }
    return a.x>b.x;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        cin>>d>>a>>b>>c;
        pos val;
        val.x=a;val.y=b;val.z=c;val.idx=d;
        v.push_back(val);
    }
    
    sort(v.begin(),v.end(),comp);
    int res,val=0;
    for(int i=0;i<n;i++){
        if(v[i].idx==k){
            res=i;
            break;
        }
    }
    for(int i=res-1;i>=0;i--){
        if(v[i].x!=v[res].x||v[i].y!=v[res].y||v[i].z!=v[res].z)break;
        val++;
    }
    cout<<res-val+1;
}
