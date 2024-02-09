#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int n,t;
long long a,b;
char c;

struct pos{
	long long x,y;
};

vector<pos> v,con;
stack<pos> s;

long long ccw(pos a,pos b,pos c){
    return a.x*b.y + b.x*c.y + c.x*a.y - (b.x*a.y + c.x*b.y + a.x*c.y);
}

long long cccw(pos a,pos b,pos c,pos d){
    d.x-=(c.x-b.x);
    d.y-=(c.y-b.y);
    return ccw(a,b,d);
}

bool comp(pos a,pos b){//반시계방향 정렬
	long long cc=ccw(v[0],a,b);

	if(cc) return cc>0; //각도 작은순으로 정렬
	else if(a.x!=b.x) return a.x<b.x;//x가 작은 순
	else return a.y<b.y;//y가 작은 순
}

long long dis(pos a,pos b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
	    v.clear();
	    con.clear();
	    
	    cin>>n;
    	for(int i=0;i<n;i++){
    		cin>>a>>b;
    		pos val;
    		val.x=a;
    		val.y=b;
    		v.push_back(val);
    	}
    
    	for(int i=1;i<n;i++){
    		if(v[i].x<v[0].x || (v[i].x==v[0].x && v[i].y<v[0].y)){
    			long long temp=v[0].x;
    			v[0].x=v[i].x;
    			v[i].x=temp;
    	
    			temp=v[0].y;
    			v[0].y=v[i].y;
    			v[i].y=temp;
    		}
    	}
    
    	sort(v.begin()+1,v.end(),comp);
    	/*int idx=n-1;
    	while(!ccw(v[0],v[idx-1],v[idx]))idx--; //↓방향의 점들을 다시 정렬해줌
    	reverse(v.begin()+idx,v.end());*/
    
    	con.push_back(v[0]);
    	con.push_back(v[1]);
    
    	for(int i=2;i<n;i++){
    		while(con.size()>=2){
    			pos top2=con.back();
    			con.pop_back();
    			pos top1=con.back();
    			if(ccw(top1,top2,v[i])>0){
    				con.push_back(top2);
    				break;
    			}
    		}
    		con.push_back(v[i]);
    	}
    	int size=con.size();
    	/*cout<<size<<"\n";
    	for(int i=0;i<size;i++){
    	    cout<<con[i].x<<" "<<con[i].y<<"\n";
    	}*/
    	long long Max=0;
    	pos ans1,ans2;
    	int ed=1;
    	
    	for(int st=0;st<size;st++){
    	    while(1){
    	        pos v1,v2;
    	        v1.x=con[(st+1)%size].x-con[st].x;
    	        v1.y=con[(st+1)%size].y-con[st].y;
    	        v2.x=con[(ed+1)%size].x-con[ed].x;
    	        v2.y=con[(ed+1)%size].y-con[ed].y;
    	        
    	        pos temp;
    	        temp.x=0;temp.y=0;
    	        
    	        if(ccw(temp,v1,v2)>0)ed=(ed+1)%size;
    	        else break;
    	    }
    	    long long dist=dis(con[st],con[ed]);
    	    if(Max<dist){
    	        Max=dist;
    	        ans1=con[st];
    	        ans2=con[ed];
    	    }
    	}
    	cout<<ans1.x<<" "<<ans1.y<<" "<<ans2.x<<" "<<ans2.y<<"\n";
	}
}
