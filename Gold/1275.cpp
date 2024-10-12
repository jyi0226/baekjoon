#include <iostream>
#include <vector>
using namespace std;

long long A[101010];
long long tree[404040];
long long n,m,a,b,c,d;

long long init(int start, int end, int node){
	if(start==end) return tree[node] = A[start];
	int mid=(start+end)/2;
	return tree[node] = init(start,mid,node*2) + init(mid+1,end,node*2+1);
}

long long sum(int start, int end, int node, int left, int right){
	if(left<=start&&end<=right) return tree[node];
	if(left>end||right<start) return 0;
	int mid = (start+end)/2;
	return sum(start,mid,node*2,left,right) + sum(mid+1,end,node*2+1,left,right);
}

void update(int start, int end, int node, int index, long long dif){
	if(index<start || index>end) return;
	tree[node]+=dif;
	if(start==end) return;
	int mid = (start+end)/2;
	update(start,mid,node*2,index,dif);
	update(mid+1,end,node*2+1,index,dif);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);

    cin>>n>>m;

    for(int i=0;i<n;i++)cin>>A[i];
    
    init(0,n-1,1);

    for(int i=0;i<m;i++){
        cin>>a>>b>>c>>d;
        if(a<b)cout<<sum(0,n-1,1,a-1,b-1)<<"\n";
        else cout<<sum(0,n-1,1,b-1,a-1)<<"\n";
        update(0,n-1,1,c-1,d-A[c-1]);
        A[c-1]=d;
    }
}
