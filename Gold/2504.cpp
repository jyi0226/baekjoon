#include <iostream>
#include <string>
#include <stack>

using namespace std;
string str;
stack<char> s;
int ans=0,temp=1;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            s.push(str[i]);
            temp*=2;
        }
        else if(str[i]==')'){
            if(s.empty()||s.top()!='('){
                ans=0;
                break;
            }
            else{
                if(str[i-1]=='(')ans+=temp;
                temp/=2;
                s.pop();
            }
        }
        else if(str[i]=='['){
            s.push(str[i]);     
            temp*=3;
        }
        else{
            if(s.empty()||s.top()!='['){
                ans=0;
                break;
            }
            else{
                if(str[i-1]=='[')ans+=temp;
                temp/=3;
                s.pop();
            }
            
        }
    }
    if(!s.empty())ans=0;
    cout<<ans;
}
