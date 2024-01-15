#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n,m,num;
vector<int> book_m;
vector<int> book_p;

stack<int> M;
stack<int> P;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num;
        if(num>0){
            book_p.push_back(num);
        }
        else{
            book_m.push_back(-1*num);
        }
    }
    sort(book_p.begin(),book_p.end());
    sort(book_m.begin(),book_m.end());
    /*for(int i=0;i<book_p.size();i++)cout<<book_p[i]<<" ";
    cout<<"\n";
    for(int i=0;i<book_m.size();i++)cout<<book_m[i]<<" ";
    cout<<"\n";*/
    for(int i=0;i<book_p.size();i++)P.push(book_p[i]);
    for(int i=0;i<book_m.size();i++)M.push(book_m[i]);
    int res=0;
    //cout<<P.size()<<" "<<M.size()<<"\n";
    if(!P.empty()&&!M.empty()){
        if(P.top()>M.top()){
            res+=P.top();
            int cnt=0;
            while(!P.empty()&&cnt<m){
                P.pop();
                cnt++;
            }
        }
        else{
            res+=M.top();
            int cnt=0;
            while(!M.empty()&&cnt<m){
                M.pop();
                cnt++;
            }
        }
    }
    else{
        if(P.empty()){
            res+=M.top();
            int cnt=0;
            while(!M.empty()&&cnt<m){
                M.pop();
                cnt++;
            }
        }
        else{
            res+=P.top();
            int cnt=0;
            while(!P.empty()&&cnt<m){
                P.pop();
                cnt++;
            } 
        }
    }
    //cout<<res<<" "<<P.top()<<" "<<M.top()<<"\n";
    while(!P.empty()){
        res+=2*P.top();
        int cnt=0;
        while(!P.empty()&&cnt<m){
            P.pop();
            cnt++;
        }
    }
    while(!M.empty()){
        res+=2*M.top();
        int cnt=0;
        while(!M.empty()&&cnt<m){
            M.pop();
            cnt++;
        }
    }
    cout<<res;
}
