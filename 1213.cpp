#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    deque<char> deq;
    char word[55];
    cin>>word;
    int size=strlen(word);
    sort(word,word+size);
    int abc[30]={0,};
    for(int i=0;i<size;i++)
    {
        abc[word[i]-'A']++;
    }
    int even=-1;
    for(int i=0;i<26;i++)
    {
        if(abc[i]%2!=0)
        {
            if(even==-1)
            {
                even=i;
                deq.push_back(even+'A');
                abc[even]--;
            }
            else
            {
                cout<<"I'm Sorry Hansoo";
                return 0;
            }
        }
    }
    //for(int i=0;i<26;i++)cout<<abc[i]<<" ";
    //cout<<abc[0]+'A';
    for(int i=25;i>=0;i--)
    {
        while(abc[i]>0)
        {
            deq.push_front(i+'A');
            deq.push_back(i+'A');
            abc[i]-=2;
        }
    }
    while(!deq.empty())
    {
        cout<<deq.front();
        deq.pop_front();
    }
}