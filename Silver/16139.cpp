#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n,a,b;
string s;
int alp[202020][26];
char word;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>s>>n;
    for(int i=0;i<s.size();i++){
        if(i>0){
            alp[i][s[i]-'a']=1;
        }
        else{
            alp[i][s[i]-'a']=1;
        }
    }
    for(int i=1;i<s.size();i++){
        for(int j=0;j<26;j++){
            if(alp[i-1][j]){
                if(alp[i][j])alp[i][j]+=alp[i-1][j];
                else alp[i][j]=alp[i-1][j];
            }
        }
    }/*
    for(int i=0;i<s.size();i++)cout<<alp[i][0]<<" ";
    cout<<"\n";*/
    for(int i=0;i<n;i++){
        cin>>word>>a>>b;
        if(a==0){
            cout<<alp[b][word-'a']<<"\n";
        }
        else{
            cout<<alp[b][word-'a']-alp[a-1][word-'a']<<"\n";
        }
    }
}
