#include <iostream>

using namespace std;
bool visited1[40];
bool visited2[40];
bool visited3[40];

int n,cnt=0;
void func(int cur){
    if(cur==n)cnt++;
    else{
        for(int i=0;i<n;i++){
            if(visited1[i]||visited2[i+cur]||visited3[cur-i+n-1])continue;
            visited1[i]=true;
            visited2[i+cur]=true;
            visited3[cur-i+n-1]=true;
            func(cur+1);
            visited1[i]=false;
            visited2[i+cur]=false;
            visited3[cur-i+n-1]=false;
        }
    }
}


int main()
{
    cin>>n;
    func(0);
    cout<<cnt;
}
