#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,d,w;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    if(n==0){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>w>>d;
        pq.push({d,w});
    }
    /*while(!pq.empty()){
        cout<<pq.top().first<<" "<<pq.top().second<<"\n";
        pq.pop();
    }*/
    int res=0;
    q.push({pq.top().second,pq.top().first});
    pq.pop();
    while(!pq.empty()){
        int size=q.size();
        int Min=q.top().first;
        int ed=pq.top().first;
        int cost=pq.top().second;
        if(size<ed)q.push({cost,ed});
        else if(size==ed){
            if(Min<cost){
                q.pop();
                q.push({cost,ed});
            }
        }
        pq.pop();
    }
    while(!q.empty()){
        res+=q.top().first;
        //cout<<q.top().first<<" "<<q.top().second<<"\n";
        q.pop();
    }
    cout<<res;
}
