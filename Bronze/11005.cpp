#include <iostream>
#include <string>

using namespace std;
long long n,num;
string s;
int main()
{
    cin>>num>>n;
    long long val=n;
    while(1){
        if(num>val)val*=n;
        else{
            if(num<val)val/=n;
            while(num!=0||val!=0){
                int wd=num/val;
                int next=num%val;
                if(wd<10)s+=wd+'0';
                else s+=wd+'A'-10;
                num=next;
                val/=n;
            }
            break;
        }
    }
    cout<<s;
}
