#include <iostream>
#include <deque>
using namespace std;
deque<int> d;
int n,ord,num;
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
            d.push_front(num);
        }
        else if(ord==2){
            cin>>num;
            d.push_back(num);
        }
        else if(ord==3){
            if(!d.empty()){
                cout<<d.front()<<"\n";
                d.pop_front();
            }
            else{
                cout<<"-1\n";
            }
        }
        else if(ord==4){
            if(!d.empty()){
                cout<<d.back()<<"\n";
                d.pop_back();
            }
            else{
                cout<<"-1\n";
            }
        }
        else if(ord==5){
            cout<<d.size()<<"\n";
        }
        else if(ord==6){
            cout<<d.empty()<<"\n";
        }
        else if(ord==7){
            if(!d.empty()){
                cout<<d.front()<<"\n";
            }
            else{
                cout<<"-1\n";
            }
        }
        else{
            if(!d.empty()){
                cout<<d.back()<<"\n";
            }
            else{
                cout<<"-1\n";
            }
        }
    }
}
