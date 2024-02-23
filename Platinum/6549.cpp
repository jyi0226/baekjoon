#include <iostream>
#include <stack>
using namespace std;
int n;
long long h[101010];
long long Max;
long long max(long long a,long long b){
    if(a>b)return a;
    else return b;
}
int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    while(1){
        cin>>n;
        Max=0;
        if(n==0)break;
        stack<int> s;
        for(int i=0;i<n;i++)cin>>h[i];
        for(int i=0;i<n;i++){
            while(!s.empty()&&h[s.top()]>h[i]){
                long long Top=h[s.top()];
                int l=i;
                s.pop();
                if(!s.empty())l=i-s.top()-1;
                Max=max(Max,l*Top);
            }
            s.push(i);
        }
        int val=s.top();
        while(!s.empty()){
            long long Top=h[s.top()];
            int l=n;
            s.pop();
            if(!s.empty())l=n-s.top()-1;
            Max=max(Max,l*Top);
        }
        cout<<Max<<"\n";
    }
}
