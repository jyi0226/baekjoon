#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A[101010];
int min_tree[404040];
int max_tree[404040];
int n,m,a,b;

int init_min(int st, int ed, int node){
	if(st==ed) return min_tree[node] = A[st];
	int mid=(st+ed)/2;
	return min_tree[node] = min(init_min(st,mid,node*2),init_min(mid+1,ed,node*2+1));
}
int init_max(int st, int ed, int node){
	if(st==ed) return max_tree[node] = A[st];
	int mid=(st+ed)/2;
	return max_tree[node] = max(init_max(st,mid,node*2),init_max(mid+1,ed,node*2+1));
}
int find_max(int st,int ed,int node,int left,int right){
    if(left>ed||right<st)return 0;
    if(left<=st&&ed<=right)return max_tree[node];

    int mid=(st+ed)/2;
    return max(find_max(st,mid,node*2,left,right),find_max(mid+1,ed,node*2+1,left,right));
}
int find_min(int st,int ed,int node,int left,int right){
    if(left>ed||right<st)return 1000000001;
    if(left<=st&&ed<=right)return min_tree[node];

    int mid=(st+ed)/2;
    return min(find_min(st,mid,node*2,left,right),find_min(mid+1,ed,node*2+1,left,right));
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>A[i];
    init_max(0,n-1,1);
    init_min(0,n-1,1);

    for(int i=0;i<m;i++){
        cin>>a>>b;
        cout<<find_min(0,n-1,1,a-1,b-1)<<" "<<find_max(0,n-1,1,a-1,b-1)<<"\n";
    }
}
