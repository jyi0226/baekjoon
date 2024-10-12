#include <iostream>
#include <vector>
using namespace std;

long long A[1010101];
long long tree[4040404];
long long n,m,k,a,b,c;

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

    cin>>n>>m>>k;

    for(int i=0;i<n;i++)cin>>A[i];
    
    init(0,n-1,1);

    for(int i=0;i<m+k;i++){
        cin>>a>>b>>c;
        if(a==1){
            update(0,n-1,1,b-1,c-A[b-1]);
            A[b-1]=c;
        }
        else{
            cout<<sum(0,n-1,1,b-1,c-1)<<"\n";
        }
    }
}
