#include <bits/stdc++.h>
using namespace std;

int board[111][111]={};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int n;
    cin>>n;
    int num=0;
    if(n>9)
    {
        num+=9;
        if(n>99)
        {
            num+=99;
            if(n>999)
            {
                num+=999;
                if(n>9999)
                {
                    num+=9999;
                    if(n>99999)
                    {
                        num+=99999;
                        if(n>999999)
                        {
                            num+=999999;
                            if(n>9999999)
                            {
                                num+=9999999;
                                if(n>99999999)
                                {
                                    cout<<9+2*90+3*900+4*9000+5*90000+6*900000+7*9000000+8*90000000+9;
                                }
                                else
                                {
                                    cout<<n*8-num;
                                }
                            }
                            else
                            {
                                cout<<n*7-num;
                            }
                        }
                        else
                        {
                            cout<<n*6-num;
                        }
                    }
                    else
                    {
                        cout<<n*5-num;
                    }
                }
                else
                {
                    cout<<n*4-num;
                }
            }
            else
            {
                cout<<n*3-num;
            }
        }
        else
        {
            cout<<n*2-num;
        }
    }
    else
    cout<<n;

}