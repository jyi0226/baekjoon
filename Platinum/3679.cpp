#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

int n,c;
long long a,b;
struct pos{
    long long x,y,z;
};

vector<pos> v;

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
    cin>>c;
    while(c--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            pos val;
            val.x=a;
            val.y=b;
            val.z=i;
            v.push_back(val);
        }
        for (int i=1; i<n; i++){
            if(v[i].x < v[0].x || (v[i].x == v[0].x && v[i].y < v[0].y)){
                
                long long temp = v[0].x;
                v[0].x = v[i].x;
                v[i].x = temp;
                
                temp = v[0].y;
                v[0].y = v[i].y;
                v[i].y = temp;
                
                temp = v[0].z;
                v[0].z=v[i].z;
                v[i].z=temp;
            }
        }
        //cout<<v[0].x<<" "<<v[0].y<<" "<<v[0].z<<"\n";
        sort(v.begin()+1,v.end(),compare);
        int i=n-1;
        while(!ccw(v[0],v[i-1],v[i]))i--;
        reverse(v.begin()+i,v.end());
        
        for(int i=0;i<n;i++)cout<<v[i].z<<" ";
        cout<<"\n";
        v.clear();
    }
    
}
