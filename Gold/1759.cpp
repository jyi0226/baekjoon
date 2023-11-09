#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int L,C;
char c;
int num[20];
char word[20];
bool visit[20];
void func(int cur,int cnt){
    if(cnt==L){
        string s="";
        int cnt_a=0,cnt_b=0;
        for(int i=0;i<C;i++){
            if(visit[i]){
                s+=word[i];
                if(word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u')cnt_a++;
                else cnt_b++;
            }
        }
        if(cnt_a>0&&cnt_b>1)cout<<s<<"\n";
        return;
    }
    for(int i=cur;i<C;i++){
        if(!visit[i]){
            visit[i]=1;
            func(i,cnt+1);
            visit[i]=0;
        }
    }
}
int main()
{
    cin>>L>>C;
    for(int i=0;i<C;i++){
        cin>>word[i];
    }
    sort(word,word+C);
    
    func(0,0);
    
}
