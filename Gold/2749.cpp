#include <bits/stdc++.h>
using namespace std;

string string_sum(string a,string b)
{
    string sum;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    int num=0;
    while(a.length()<b.length())
    {
        a+='0';
    }
    while(a.length()>b.length())
    {
        b+='0';
    }
    int size=a.length();
    
    for(int i=0;i<size;i++)
    {
        num=a[i]-'0'+b[i]-'0'+num;
        sum+=to_string(num%10);
        num/=10;
    }
    if(num!=0)sum+=to_string(num);
    reverse(sum.begin(),sum.end());
    return sum;

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    string fibo[10101];
    fibo[0]='0';
    fibo[1]='1';
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        fibo[i]=string_sum(fibo[i-1],fibo[i-2]);
    }
    cout<<fibo[n];
}
