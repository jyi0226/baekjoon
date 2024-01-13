#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n,k,m,v,c,idx=0;
long long res=0;
vector<pair<int,int>> jew;
vector<int> bag;
priority_queue<int> pq;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>m>>v;
        jew.push_back({m,v});
    }
    for(int i=0;i<k;i++){
        cin>>c;
        bag.push_back(c);
    }
    sort(jew.begin(),jew.end());
    sort(bag.begin(),bag.end());
    for(int i=0;i<k;i++){
        while(idx<n&&bag[i]>=jew[idx].first){
            pq.push(jew[idx++].second);
        }
        if(!pq.empty()){
            res+=pq.top();
            pq.pop();
        }
    }
    cout<<res;
}
