#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a,b,c;

void func(string str){
    if(str==a){
        cout<<1;
        exit(0);
    }
    if(str.back()=='A'){
        str.pop_back();
        func(str);
        str+="A";
    }
    if(str.front()=='B'){
        c=str;
        c.erase(0,1);
        reverse(c.begin(),c.end());
        func(c);
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>a>>b;
    func(b);
    cout<<0;
}
