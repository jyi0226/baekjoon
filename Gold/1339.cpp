#include <iostream>
#include <algorithm>
using namespace std;
int n;
int alp[26];
bool compare(int a,int b){
    return a>b;
}
string s[10];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    
    //for(int i=0;i<n;i++)cout<<s[i]<<"\n";
    for(int i=0;i<n;i++){
        int val=1;
        for(int j=s[i].size()-1;j>=0;j--){
            alp[s[i][j]-'A']+=1*val;
            val*=10;
        }
    }
    sort(alp,alp+26,compare);
    int sum=0;
    for(int i=9;i>=0;i--){
        sum+=i*alp[9-i];
    }
    cout<<sum;
}
