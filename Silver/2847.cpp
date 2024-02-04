#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int t,n,num;
vector<int> v;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    cin>>n;
    while(n--){
        cin>>num;
        v.push_back(num);
    }
    int idx=v.size()-1;
    long long res=0;
    for(int i=idx;i>0;i--){
        if(v[i]>v[i-1])continue;
        else{
            res+=v[i-1]-v[i]+1;
            v[i-1]=v[i]-1;
        }
    }
    cout<<res<<"\n";
}
