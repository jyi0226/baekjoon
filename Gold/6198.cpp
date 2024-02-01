#include <iostream>
#include <stack>
using namespace std;
int n,num;
stack<int> s;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    long long cnt=0;
    while(n--){
        cin>>num;
        if(s.empty())s.push(num);
        else{
            while(!s.empty()&&s.top()<=num)s.pop();
            cnt+=s.size();
            s.push(num);
        }
    }
    cout<<cnt;
}
