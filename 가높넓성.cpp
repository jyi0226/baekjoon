#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int n;
long long a,b;
int lev[1010];

struct pos{
	long long x,y,idx;
};

bool vis[1010];

vector<pos> v,ans,con;

long long ccw(pos a,pos b,pos c){
    return a.x*b.y + b.x*c.y + c.x*a.y - (b.x*a.y + c.x*b.y + a.x*c.y);
}

bool comp(pos a,pos b){//반시계방향 정렬
	long long cc=ccw(con[0],a,b);

	if(cc) return cc>0; //각도 작은순으로 정렬
	else if(a.y!=b.y) return a.y<b.y;//x가 작은 순
	else return a.x<b.x;//y가 작은 순
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		pos val;
		val.x=a;
		val.y=b;
		val.idx=i;
		v.push_back(val);
		vis[i]=0;
	}
	int lv=1;
    while(1){
        con.clear();
        ans.clear();
        for(int i=0;i<v.size();i++){
            if(!vis[v[i].idx])con.push_back(v[i]);
        }
        //cout<<con.size()<<"\n";
        if(con.size()<=2)break;
        
        for(int i=1;i<con.size();i++){
    		if(con[i].y<con[0].y || (con[i].y==con[0].y && con[i].x<con[0].x)){
    			long long temp=con[0].x;
    			con[0].x=con[i].x;
    			con[i].x=temp;
    	
    			temp=con[0].y;
    			con[0].y=con[i].y;
    			con[i].y=temp;
    			
    			temp=con[0].idx;
    			con[0].idx=con[i].idx;
    			con[i].idx=temp;
    		}
    	}
    
    	sort(con.begin()+1,con.end(),comp);
    	int Idx=con.size()-1;
    	while(!ccw(con[0],con[Idx-1],con[Idx]))Idx--; //↓방향의 점들을 다시 정렬해줌
    	reverse(con.begin()+Idx,con.end());
    
    	ans.push_back(con[0]);
    	ans.push_back(con[1]);
    
    	for(int i=2;i<con.size();i++){
    		while(ans.size()>=2){
    			pos top2=ans.back();
    			ans.pop_back();
    			pos top1=ans.back();
    			if(ccw(top1,top2,con[i])>0){
    				ans.push_back(top2);
    				break;
    			}
    		}
    		ans.push_back(con[i]);
    	}
    	
    	if(ans.size()<3)break;
    	else{
    	    pos top3=ans.back();
        	ans.pop_back();
        	pos top2=ans.back();
            pos top1=ans[0];
            if(ccw(top1,top2,top3)!=0)ans.push_back(top3);
    	}
        
    	//cout<<ans.size()<<"\n";
    	for(int i=0;i<ans.size();i++){
    	    vis[ans[i].idx]=1;
    	    lev[ans[i].idx]=lv;
    		//cout<<ans[i].x<<" "<<ans[i].y<<"\n";
    	}
    	lv++;
    	//for(int i=0;i<n;i++)cout<<vis[i]<<" ";
    	//cout<<"\n";
    }  
    for(int i=0;i<n;i++)cout<<lev[i]<<" ";
    
    //3 0 0 1 1 2 2 오류만 해결하면 끝
    //ans를 vector이 아닌 stack로 해볼까?
}
