#include <iostream>
using namespace std;
string str,bomb,cur="";
int main()
{
    cin>>str>>bomb;
    int size1=str.size();
    int size2=bomb.size();
    for(int i=0;i<size1;i++){
        cur+=str[i];
        if(cur.size()<size2)continue;
        if(cur.back()==bomb.back()){
            bool val=0;
            for(int j=0;j<size2;j++){
                if(cur[cur.size()-1-j]!=bomb[size2-1-j]){
                    val=1;
                    break;
                }
            }
            if(!val)for(int i=0;i<size2;i++)cur.pop_back();
        }
    }
    if(!cur.empty())cout<<cur;
    else cout<<"FRULA";
}
