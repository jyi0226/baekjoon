#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int n,t;
long long a,b;
struct pos{
    long long x,y;
};

vector<pos> v,ans;
stack<pos> s;

long long ccw(pos a,pos b,pos c){
    return a.x*b.y+b.x*c.y+c.x*a.y-(b.x*a.y+c.x*b.y+a.x*c.y);
}
bool compare(pos a,pos b){
    long long cc=ccw(v[0],a,b);
    
    if(cc) return cc>0;
    else if(a.y!=b.y)return a.y>b.y;
    else return a.x<b.x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            pos val;
            val.x=a;
            val.y=b;
            v.push_back(val);
        }
        for (int i=1; i<n; i++){
            if(v[i].y > v[0].y || (v[i].y == v[0].y && v[i].x < v[0].x)){
                
                long long temp = v[0].x;
                v[0].x = v[i].x;
                v[i].x = temp;
                
                temp = v[0].y;
                v[0].y = v[i].y;
                v[i].y = temp;
            }
        }
        sort(v.begin()+1,v.end(),compare);
        
        s.push(v[0]);
        s.push(v[1]);
        for(int i=2;i<v.size();i++){
            while(s.size()>=2){
                pos top2=s.top();
                s.pop();
                pos top1=s.top();
                if(ccw(top1,top2,v[i])>0){
                    s.push(top2);
                    break;
                }
            }
            s.push(v[i]);
        }
        cout<<s.size()<<"\n";
        while(s.size()>1){
            ans.push_back(s.top());
            //cout<<s.top().x<<" "<<s.top().y<<"\n";
            s.pop();
        }
        cout<<s.top().x<<" "<<s.top().y<<"\n";
        s.pop();
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].x<<" "<<ans[i].y<<"\n";
        }
        ans.clear();
        v.clear();
    }
        
}
