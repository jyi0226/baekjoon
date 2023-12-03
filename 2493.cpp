#include <iostream>
#include <stack>
using namespace std;
int n,t;
stack<pair<int,int>> s;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        
        while(!s.empty()){
            if(s.top().second>t){
                cout<<s.top().first<<" ";
                break;
            }
            s.pop();
        }
        if(s.empty()){
            cout<<0<<" ";
        }
        
        s.push({i+1,t});
    }
}
