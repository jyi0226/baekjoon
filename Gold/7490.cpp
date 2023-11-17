#include <iostream>
#include <string>

using namespace std;
int t,n;
string s;
int num[11];

void func(int cur,int n){
    if(cur==n+1){
        string number[10]={"","","","","","","","","",""};
        int cnt=0;
        //cout<<s<<"\n";
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')continue;
            else if(s[i]=='+'||s[i]=='-')cnt++;
            else number[cnt]+=s.at(i);
        }
        //for(int i=0;i<=cnt;i++)cout<<number[i]<<" ";
        //cout<<"\n";
        cnt=0;
        int tot=stoi(number[cnt++]);
        for(int i=0;i<s.size();i++){
            if(s[i]=='+')tot+=stoi(number[cnt++]);
            else if(s[i]=='-')tot-=stoi(number[cnt++]);
        }
        //cout<<tot;
        if(tot==0)cout<<s<<"\n";
    }
    if(cur<=n){
        
        s+=' '+to_string(cur);
        func(cur+1,n);
        s.resize(s.size()-2);
        
        s+='+'+to_string(cur);
        func(cur+1,n);
        s.resize(s.size()-2);
        
        s+='-'+to_string(cur);
        func(cur+1,n);
        s.resize(s.size()-2);
    }
}

int main()
{
    
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>num[i];
    }
    for(int i=0;i<t;i++){
        s="1";
        func(2,num[i]);
        cout<<"\n";
    }
}
