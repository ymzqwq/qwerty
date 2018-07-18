#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=200001;
const int M=N<<2;
int T,n,m,Q,K,S,cnt,v[M],L[M],h[M],head[N],Next[M],dis[N],b[N];
struct data{
	int dis,num;
	
	bool operator < (const data &q) const{
		return dis>q.dis;
	}
};
priority_queue<data> hp;

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void add(int x,int y,int z,int a){
	Next[++cnt]=head[x];
	head[x]=cnt;
	v[cnt]=y;L[cnt]=z;h[cnt]=a;
}

void dijk(){
	while(!hp.empty()) hp.pop();
	memset(dis,0x7f,sizeof dis);
	memset(b,0,sizeof b);
	//cout<<dis[0]<<endl<<endl;
	dis[1]=0;
	hp.push((data){0,1});
	for(int i=1;i<=n;i++){
		data q=hp.top();hp.pop();
		while(b[q.num]) q=hp.top(),hp.pop();
		b[q.num]=1;
		for(int j=head[q.num];j!=-1;j=Next[j])
		 if (b[v[j]]==0&&dis[q.num]+L[j]<dis[v[j]]){
		 	dis[v[j]]=dis[q.num]+L[j];
		 	hp.push((data){dis[v[j]],v[j]});
		 }
	}
}

int dfs(int x,int p){
	int ans=dis[x];
	b[x]=1;
	for(int j=head[x];j!=-1;j=Next[j])
	 if (!b[v[j]]&&h[j]>p)
	 	ans=min(ans,dfs(v[j],p));
	return ans;
}

int main(){
	freopen("return.in","r",stdin);
	freopen("return.out","w",stdout);
	read(T);
	while(T--){
		read(n);read(m);
		bool flag=0;
		memset(head,-1,sizeof head);
		memset(Next,-1,sizeof Next);
		cnt=0;
		
		if (m==n-1){
			memset(dis,0,sizeof dis);
			for(int i=1;i<=m;i++){
				int x,y,z,a;
				read(x);read(y);read(z);read(a);
				dis[y]=z;h[y]=a;
			}
			for(int i=2;i<=n;i++) dis[i]+=dis[i-1];
			int x,p,ans=0;
			read(Q);read(K);read(S);
			for(int i=1;i<=Q;i++){
				read(x);read(p);
				x=(x+K*ans-1)%n+1;
				p=(p+K*ans)%(S+1);
				while(x!=1&&h[x]>p) x--;
				printf("%d\n",dis[x]);
				ans=dis[x];
			}
			continue;
		}
		
		for(int i=1;i<=m;i++){
			int x,y,z,a;
			read(x);read(y);read(z);read(a);
			add(x,y,z,a);add(y,x,z,a);
			if (a!=1) flag=1;
		}
		read(Q);read(K);read(S);
		dijk();
		
		if (!flag){
			int x,p,ans=0;
			for(int i=1;i<=Q;i++){
				read(x);read(p);
				x=(x+K*ans-1)%n+1;
				p=(p+K*ans)%(S+1);
				if (p==0) ans=0;
				 else ans=dis[x];
				printf("%d\n",ans);
			}
			continue;
		}
		
		int x,p,ans=0;
		for(int i=1;i<=Q;i++){
			read(x);read(p);
			x=(x+K*ans-1)%n+1;
			p=(p+K*ans)%(S+1);
			memset(b,0,sizeof b);
			ans=dfs(x,p);
			printf("%d\n",ans);
		}
	}
	return 0;
}
