#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n;
string word,ans;
int alp[26];

void func(int cur){
    if(cur==word.size()){
        cout<<ans<<"\n";
        return;
    }
    for(int i=0;i<26;i++){
        if(alp[i]>0){
            ans.push_back('a'+i);
            alp[i]--;
            func(cur+1);
            alp[i]++;
            ans.pop_back();
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>word;
        for(int j=0;j<26;j++)alp[j]=0;
        for(int j=0;j<word.size();j++){
            int val=word[j]-'a';
            alp[val]++;
        }
        int cur=0;
        func(cur);
    }
}
