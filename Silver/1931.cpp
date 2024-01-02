#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int a,b,t;
vector<pair<int,int>> v;
int cnt=1;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    t=v[0].first;
    for(int i=1;i<n;i++){
        if(t<=v[i].second){
            cnt++;
            t=v[i].first;
        }
    }
    cout<<cnt;
}
