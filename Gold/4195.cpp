#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map<string,int> m;
string p1,p2;
int t,n,cnt,x,y;

int friend_num[201010];
int root[201010];

int find_root(int x){
    if(x==root[x])return x;
    return root[x]=find_root(root[x]);
}

void union_root(int x,int y){
    x=find_root(x);
    y=find_root(y);
    
    if(x<y){
        root[y]=x;
        friend_num[x]+=friend_num[y];   
    }
    else if(x>y){
        root[x]=y;
        friend_num[y]+=friend_num[x];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<string,int>::iterator it;
    cin>>t;
    for(int test=0;test<t;test++){
        m.clear();
        
        cin>>n;
        cnt=1;
        for(int i=1;i<=200001;i++){
            root[i]=i;
            friend_num[i]=1;
        }
        for(int i=1;i<=n;i++){
            cin>>p1>>p2;
            it=m.find(p1);
            if(it==m.end()){
                m[p1]=cnt;
                x=cnt++;
            }
            else x=it->second;
            it=m.find(p2);
            if(it==m.end()){
                m[p2]=cnt;
                y=cnt++;
            }
            else y=it->second;
            union_root(x,y);
            int val=find_root(x);
            cout<<friend_num[val]<<"\n";
        }
    }
}
