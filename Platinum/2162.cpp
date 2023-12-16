#include <iostream>
#include <algorithm>
using namespace std;
long long a,b,c,d,e,f,g,h;
long long abc,abd,cda,cdb;
int n;
int root[3030];
int num[3030][4];
int size_root[3030];
int find_root(int x){
    if(x==root[x])return x;
    return root[x]=find_root(root[x]);
}
void union_root(int x,int y){
    x=find_root(x);
    y=find_root(y);
    
    root[y]=x;
    size_root[x]+=size_root[y];
    size_root[y]=0;
    //cout<<a<<" "<<b<<"\n";
}

int ccw(pair<long long,long long>p1,pair<long long,long long>p2,pair<long long,long long>p3) {
    long long num = p1.first*p2.second+p2.first*p3.second+p3.first*p1.second-p2.first*p1.second-p3.first*p2.second-p1.first*p3.second;
    if(num<0){
        return -1;
    }
    else if(num>0){
        return 1;
    }
    else return 0;
}
bool ccw_func(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    pair<long long,long long>a,b,c,d;
    a.first=x1;
    a.second=y1;
    b.first=x2;
    b.second=y2;
    c.first=x3;
    c.second=y3;
    d.first=x4;
    d.second=y4;
    abc=ccw(a,b,c);
    abd=ccw(a,b,d);
    cda=ccw(c,d,a);
    cdb=ccw(c,d,b);
    if(abc*abd==0&&cda*cdb==0){
        if(a>b)swap(a,b);
        if(c>d)swap(c,d);
        
        if(a<=d&&c<=b)return 1;
        else return 0;
    }
    else if(abc*abd<=0&&cda*cdb<=0)return 1;
    else return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i][0]>>num[i][1]>>num[i][2]>>num[i][3];
        root[i]=i;
        size_root[i]=1;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ccw_func(num[i][0],num[i][1],num[i][2],num[i][3],num[j][0],num[j][1],num[j][2],num[j][3])){
                if(find_root(i)!=find_root(j))union_root(i,j);
            }
        }
    }
    int res=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(size_root[i]!=0){
            res=max(res,size_root[i]);
            cnt++;
        }
    }
    cout<<cnt<<"\n"<<res;
    //cout<<"\n";
    //for(int i=0;i<n;i++)cout<<size_root[i]<<" "<<root[i]<<"\n";
    
}
