#include <iostream>
#include <string>

using namespace std;
int n,sum=0;
string s;
int main()
{
    cin>>s>>n;
    for(int i=0;i<s.size();i++){
        int val=1;
        for(int j=1;j<s.size()-i;j++){
            val*=n;
        }
        if(s[i]-'A'<0)sum+=val*(s[i]-'0');
        else sum+=val*(s[i]-'A'+10);
    }
    cout<<sum;
}
