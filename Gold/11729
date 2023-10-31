#include <iostream>
int n,cnt=1;
using namespace std;

void hanoi(int n,int a,int b,int c){
    if(n==1){
        cout<<a<<" "<<c<<"\n";
        return;
    }
    hanoi(n-1,a,c,b);
    hanoi(1,a,b,c);
    hanoi(n-1,b,a,c);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cnt*=2;
    cout<<cnt-1<<"\n";
    hanoi(n,1,2,3);
}
