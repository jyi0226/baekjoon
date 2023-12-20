#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
string a,b;
int n;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin>>n){
        a="-";
        for(int i=0;i<n;i++){
            b=a;
            for(int j=0;j<b.size();j++){
                a+=" ";
            }
            a+=b;
        }
        cout<<a<<"\n";
    }
        
}
