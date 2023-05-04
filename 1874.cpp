#include <bits/stdc++.h>
using namespace std;

stack<int> stk;
int max_num=0;
string str="";
int status=0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int n,num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        if(stk.empty())
        {
            for(int j=max_num+1;j<=num;j++)
            {
                stk.push(j);
                str+="+";
                //cout<<j<<" "<<str<<endl;
            }
            stk.pop();
            str+="-";
            max_num=num;
            //cout<<max_num<<" "<<str<<endl;
        }
        else
        {
            if(num==stk.top())
            {
                stk.pop();
                str+="-";
               // cout<<max_num<<" "<<str<<endl;
            }
            else if(stk.top()<num)
            {
                for(int k=max_num+1;k<=num;k++)
                {
                    stk.push(k);
                    str+="+";
                }
                stk.pop();
                str+="-";
                max_num=num;
                //cout<<max_num<<" "<<str<<endl;
            }
            else
            {
                status=1;
                break;
            }
        }
    }
    if(status==1)
    {
        cout<<"NO";
        return 0;
    }

    else
    {
        int size=str.length();
        for(int i=0;i<size;i++)
        {
            cout<<str[i]<<"\n";
        }
    }
}