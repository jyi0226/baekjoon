#include <iostream>
#include <stack>
using namespace std;
int n,num[1010],cnt=1,cnt2=1;
stack<int> s;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>num[i];
    while(1){
        if(cnt>n)break;
        if(cnt==num[cnt2]){
            cnt++;
            cnt2++;
        }
        else{
            if(s.empty()){
                s.push(num[cnt2]);
                cnt2++;
            }
            else{
                if(s.top()==cnt){
                    s.pop();
                    cnt++;
                }
                else{
                    if(s.top()>num[cnt2]){
                        s.push(num[cnt2]);
                        cnt2++;
                    }
                    else{
                        cout<<"Sad";
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"Nice";
    return 0;
}
