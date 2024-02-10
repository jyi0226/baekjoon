#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int n,m;
long long a,b;
struct pos{
    long long x,y;
};

vector<pos> v,v1,v2,ans;
stack<pos> s;

long long ccw(pos a,pos b,pos c){
    return a.x*b.y+b.x*c.y+c.x*a.y-(b.x*a.y+c.x*b.y+a.x*c.y);
}
bool compare(pos a,pos b){
    long long cc=ccw(v[0],a,b);
    
    if(cc) return cc>0;
    else if(a.x!=b.x)return a.x<b.x;
    else return a.y<b.y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        pos val;
        val.x=a;
        val.y=b;
        v1.push_back(val);
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        pos val;
        val.x=a;
        val.y=b;
        v2.push_back(val);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            pos val;
            val.x=v1[i].x+v2[j].x;
            val.y=v1[i].y+v2[j].y;
            v.push_back(val);
        }
    }
    for (int i=1; i<n*m; i++){
        if(v[i].x < v[0].x || (v[i].x == v[0].x && v[i].y < v[0].y)){
            
            long long temp = v[0].x;
            v[0].x = v[i].x;
            v[i].x = temp;
            
            temp = v[0].y;
            v[0].y = v[i].y;
            v[i].y = temp;
        }
    }
    sort(v.begin()+1,v.end(),compare);
    
    ans.push_back(v[0]);
    ans.push_back(v[1]);
    for(int i=2;i<v.size();i++){
        while(ans.size()>=2){
            pos top2=ans.back();
            ans.pop_back();
            pos top1=ans.back();
            if(ccw(top1,top2,v[i])>0){
                ans.push_back(top2);
                break;
            }
        }
        ans.push_back(v[i]);
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++)cout<<ans[i].x<<" "<<ans[i].y<<"\n";
    
}
