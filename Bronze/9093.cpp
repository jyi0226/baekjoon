#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int t;
    cin>>t;
    cin.ignore();
    for(int i=0;i<t;i++)
    {
        string s="";
        getline(cin,s);
        s+=" ";
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << s[i];
            }
            else st.push(s[i]);
        }
    }
}
