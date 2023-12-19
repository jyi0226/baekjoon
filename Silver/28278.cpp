#include <iostream>
#include <stack>
using namespace std;
int n,ord,num;
stack<int> s;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ord;
        if(ord==1){
            cin>>num;
            s.push(num);
        }
        else if(ord==2){
            if(!s.empty()){
                cout<<s.top()<<"\n";
                s.pop();
            }
            else cout<<"-1\n";
        }
        else if(ord==3){
            cout<<s.size()<<"\n";
        }
        else if(ord==4){
            cout<<s.empty()<<"\n";
        }
        else{
            if(!s.empty()){
                cout<<s.top()<<"\n";
            }
            else cout<<"-1\n";
        }
    }
}
