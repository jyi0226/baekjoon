#include <iostream>
#include <stack>
using namespace std;
int n,num;
stack<int> s;
stack<pair<int,int>> idx;
long long cnt=0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	//cout<<"   ";
	for(int i=0;i<n;i++){
	    cin>>num;
	    if(s.empty()){
	        s.push(num);
	        idx.push({s.size(),num});
	    }
	    else{
	        while(!s.empty()&&s.top()<num){
	            cnt++;
	            s.pop();
	        }
	        while(!idx.empty()&&idx.top().second<num)idx.pop();
	        if(!s.empty()&&s.top()==num){
	            s.push(num);
	            idx.pop();
	            if(idx.empty())cnt+=s.size()-1;
	            else{
	                cnt+=s.size()-idx.top().first;
	            }
	            idx.push({s.size(),num});
	            
	        }
	        else{
	            if(!s.empty())cnt++;
	            s.push(num);
	            idx.push({s.size(),num});
	        }
	    }
	    //cout<<cnt<<" ";
	}
	//cout<<"\n"<<cnt;
	cout<<cnt;
}
