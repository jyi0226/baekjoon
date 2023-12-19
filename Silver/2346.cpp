#include <iostream>
#include <deque>
using namespace std;
deque<pair<int,int>> d;
int n,num,idx;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        d.push_back({num,i+1});
    }
    while(!d.empty()){
        num=d.front().first;
        idx=d.front().second;
        cout<<idx<<" ";
        d.pop_front();
        if(num>0){
            for(int i=1;i<num;i++){
                d.push_back({d.front().first,d.front().second});
                d.pop_front();
            }
        }
        else{
            for(int i=0;i<num*-1;i++){
                d.push_front({d.back().first,d.back().second});
                d.pop_back();
            }
        }
    }
}
