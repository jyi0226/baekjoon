#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string s[5];
int main()
{
    for(int i=0;i<5;i++)cin>>s[i];
    for(int i=1;i<=15;i++){
        for(int j=0;j<5;j++){
            if(s[j].size()<i)continue;
            else cout<<s[j][i-1];
        }
    }
}
