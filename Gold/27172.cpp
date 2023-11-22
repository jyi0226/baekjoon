#include <iostream>
using namespace std;

int n;
int pla[101010];
bool num[1010101];
int score[1010101];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>pla[i];
        num[pla[i]]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=2;j*pla[i]<=1000000;j++){
            if(num[j*pla[i]]){
                score[pla[i]]++;
                score[j*pla[i]]--;
            }
        }
    }
    for(int i=0;i<n;i++)cout<<score[pla[i]]<<" ";
}
