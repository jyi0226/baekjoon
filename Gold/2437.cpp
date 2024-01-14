#include <iostream>
#include <algorithm>
using namespace std;

int num[1010],res=1,n;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++)cin>>num[i];
    sort(num,num+n);
    for(int i=0;i<n;i++){
        if(res<num[i])break;
        res+=num[i];
    }
    cout<<res;
}
