#include <iostream>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,less<int>> max_heap;
priority_queue<int,vector<int>,greater<int>> min_heap;

int n,num;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    while(n--){
        cin>>num;
        if(!max_heap.empty()&&!min_heap.empty()){
            if(max_heap.size()==min_heap.size())max_heap.push(num);
            else min_heap.push(num);
        }
        else{
            if(max_heap.empty())max_heap.push(num);
            else min_heap.push(num);
        }
        if(!min_heap.empty()&&max_heap.top()>min_heap.top()){
                int val=max_heap.top();
                int val2=min_heap.top();
                max_heap.pop();
                min_heap.pop();
                max_heap.push(val2);
                min_heap.push(val);
        }
        
        cout<<max_heap.top()<<"\n";
    }
}
