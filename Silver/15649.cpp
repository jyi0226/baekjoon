#include <iostream>

using namespace std;
int n,m;
int arr[10];
bool visited[10];

void backTrack(int cur){
    if(cur==m){
        for(int i=0;i<m;i++)cout<<arr[i]<<" ";
        cout<<"\n";
    }
    else{
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                arr[cur]=i;
                visited[i]=true;
                backTrack(cur+1);
                visited[i]=false;
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    backTrack(0);
}
