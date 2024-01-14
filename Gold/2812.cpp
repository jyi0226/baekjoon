#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int n,k,cnt=0;
string str;
stack<char> s;
stack<char> q;
int main()
{
    cin>>n>>k>>str;
    s.push(str[0]);
    for(int i=1;i<n;i++){
        char c=str[i];
        int val=c-'0';
        while(!s.empty()&&cnt<k){
            int num=s.top()-'0';
            if(num>=val)break;
            s.pop();
            cnt++;
        }
        s.push(c);
    }
    cnt=0;
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    while(!q.empty()&&cnt<n-k){
        cout<<q.top();
        q.pop();
        cnt++;
    }
}
