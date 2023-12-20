#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int arr[505050];
int n,m,cnt=0;
bool val=0;
void merge_arr(int p,int q,int r){
    if(val)return;
    int tmp[505050];
    int i=p;
    int j=q+1;
    int t=1;
    while(i<=q&&j<=r){
        if(arr[i]<=arr[j])tmp[t++]=arr[i++];
        else tmp[t++]=arr[j++];
    }
    while(i<=q)tmp[t++]=arr[i++];
    while(j<=r)tmp[t++]=arr[j++];
    i=p;
    t=1;
    while(i<=r){
        arr[i++]=tmp[t++];
        cnt++;
        if(cnt==m){
            cout<<arr[i-1];
            val=1;
            break;
        }
    };
}

void merge_sort(int p,int r){
    if(val)return;
    if(p<r){
        int q=(p+r)/2;
        merge_sort(p,q);
        merge_sort(q+1,r);
        merge_arr(p,q,r);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    merge_sort(1,n);
    if(cnt<m)cout<<-1;
}
