#include <iostream>
#include <queue>
using namespace std;

int n,m,num,idx,cnt=0;
deque<int> dq;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0;i<n;i++)dq.push_back(i+1);
    while(m--){
        cin>>num;
        
        for(int i=0;i<dq.size();i++){
            if(dq[i]==num){
                idx=i;
                break;
            }
        }
        
        if(idx<dq.size()-idx){
            while(1){
                if(dq.front()==num){
                    dq.pop_front();
                    break;
                }
                cnt++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            while(1){
                if(dq.front()==num){
                    dq.pop_front();
                    break;
                }
                cnt++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    cout<<cnt;
}
