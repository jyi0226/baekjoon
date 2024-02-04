#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int t,n,num;
stack<int> s;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>t;
    while(t--){
        cin>>n;
        while(n--){
            cin>>num;
            s.push(num);
        }
        long long Max=0,res=0;
        while(!s.empty()){
            Max=max(Max,s.top());
            res+=Max-s.top();
            s.pop();
        }
        cout<<res<<"\n";
    }
}
