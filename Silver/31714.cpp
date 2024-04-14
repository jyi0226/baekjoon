#include <bits/stdc++.h>
using namespace std;
vector<int> v[1010];
int n,m,d,h;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(nullptr);
    cin>>n>>m>>d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>h;
            v[i].push_back(h+d*i);
        }
    }
    for(int i=0;i<n;i++){
        sort(v[i].begin(),v[i].end());
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n-1;j++){
            if(v[j][i]>=v[j+1][i]){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
}
