#include <iostream>
#include <stack>
using namespace std;
int t,n,num;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>t;
    while(t--){
        stack<int> u,d,p;   
        u.push(0);
        int db=0,pb=0;
        cin>>n;
        bool flag=1;
        while(n--){
            cin>>num;
            if(num==u.top()+1)u.push(num);
            else{
                if(!d.empty()&&!p.empty()){
                    if(num==d.top()+1)d.push(num);
                    else if(num==p.top()+1)p.push(num);
                    else{
                        flag=0;
                    }
                }
                else{
                    if(!d.empty()&&p.empty()){
                        if(num==d.top()+1)d.push(num);
                        else{
                            pb=num;
                            p.push(num);
                        }
                    }
                    else if(d.empty()&&!p.empty()){
                        if(num==p.top()+1)p.push(num);
                        else{
                            db=num;
                            d.push(num);
                        }
                    }
                    else{
                        db=num;
                        d.push(num);
                    }
                }
            }
            for(int i=0;i<2;i++){
                if(db==u.top()+1){
                    u.push(d.top());
                    while(!d.empty())d.pop();
                }
                
                if(pb==u.top()+1){
                    u.push(p.top());
                    while(!p.empty())p.pop();
                }
            }
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
