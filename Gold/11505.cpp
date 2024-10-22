#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k;
int a,b,c;

long long arr[1010101];
long long tree[4040404];

long long init(int st,int ed,int node){
    if(st==ed)return tree[node]=arr[st];
    
    int mid=(st+ed)/2;
    return tree[node]=((init(st,mid,node*2)%1000000007)*(init(mid+1,ed,node*2+1)%1000000007))%1000000007;
}

long long find(int st,int ed,int node,int left,int right){
    if(left<=st&&ed<=right)return tree[node];
    if(left>ed||right<st)return 1;
    
    int mid=(st+ed)/2;
    return ((find(st,mid,node*2,left,right)%1000000007)*(find(mid+1,ed,node*2+1,left,right)%1000000007))%1000000007;
}

void update(int st,int ed,int node,int idx, long long dif){
    if(idx<st||idx>ed)return;
    if(st==ed){
        tree[node]=dif;
        return;
    }
    int mid=(st+ed)/2;
    update(st,mid,node*2,idx,dif);
    update(mid+1,ed,node*2+1,idx,dif);
    tree[node]=(tree[node*2]*tree[node*2+1])%1000000007;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m>>k;
    
    for(int i=0;i<n;i++)cin>>arr[i];
    init(0,n-1,1);
    
    for(int i=0;i<m+k;i++){
        cin>>a>>b>>c;
        if(a==1){
            update(0,n-1,1,b-1,c);
            arr[b-1]=c;
        }
        else{
            cout<<find(0,n-1,1,b-1,c-1)<<"\n";
        }
    }
}
