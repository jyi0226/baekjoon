#include <iostream>
#include <stack>
using namespace std;
int n;
long long h[101010];
int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    while(1){
        cin>>n;
        if(n==0)break;
        stack<int> s;
        for(int i=0;i<n;i++)cin>>h[i];
        for(int i=0;i<n;i++){
            if(s.empty())s.push(i);
            else{
                if(s.top())
            }
        }
        
        
    }
}
