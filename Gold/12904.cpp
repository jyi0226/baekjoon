#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a,b;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>a>>b;
    while(b.size()>=a.size()){
        if(a==b){
            cout<<1;
            return 0;
        }
        if(b.back()=='A'){
            b.pop_back();
        }
        else{
            b.pop_back();
            reverse(b.begin(),b.end());
        }
    }
    cout<<0;
}
