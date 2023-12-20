#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int cnt=0,n;
string str;
int recursion(string& s,int l,int r){
    //참조에 의한 호출로 값을 복사하지 않고 바로 넘김
    cnt++;
    if(l>=r)return 1;
    else if(s[l]!=s[r])return 0;
    else return recursion(s,l+1,r-1);
}

int isPalindrome(string& s){
    return recursion(s,0,s.size()-1);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cnt=0;
        cin>>str;
        cout<<isPalindrome(str)<<" "<<cnt<<"\n";
    }
}
