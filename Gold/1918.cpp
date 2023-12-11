#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;
void change(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            s.push(str[i]);
        }
        else if(str[i]==')'){
            while(s.top()!='('){
                cout<<s.top();
                s.pop();
            }
            s.pop();
        }
        else if(str[i]=='+'||str[i]=='-'){
            while(!s.empty()&&(s.top()=='*'||s.top()=='/'||s.top()=='+'||s.top()=='-')){
                cout<<s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else if(str[i]=='*'||str[i]=='/'){
            while(!s.empty()&&(s.top()=='*'||s.top()=='/')){
                cout<<s.top();
                s.pop();
            }
            s.push(str[i]);
        }
        else cout<<str[i];
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>str;
    change(str);
}
