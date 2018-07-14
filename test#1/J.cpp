#include<bits/stdc++.h>
using namespace std;
const int N=100001;
const int M=200001;
const int Lg=18;
int n,m,Next[M],head[N],v[M],f[N][Lg],b[N],cnt,dep[N],sum[N];

inline void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void add(int x,int y){
	Next[++cnt]=head[x];
	head[x]=cnt;
	v[cnt]=y;
}

void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=head[x];i!=-1;i=Next[i])
	 if (v[i]!=fa) dfs(v[i],x),sum[x]+=sum[v[i]];
	sum[x]++;
}

int sol(int x,int y){
	if (x==y) return n;
	if (dep[x]<dep[y]) x^=y^=x^=y;
	int fx=x,fy=y;
	for(int i=Lg-1;i>=0;i--)
	 if (dep[f[fx][i]]>dep[y]) fx=f[fx][i];
	if (f[fx][0]==y) fy=y;
	 else{
	 	if (dep[fx]>dep[fy]) fx=f[fx][0];
	 	for(int i=Lg-1;i>=0;i--)
	 	 if (f[fx][i]!=f[fy][i]) fx=f[fx][i],fy=f[fy][i];
	 }
	if (dep[x]==dep[y]) return n-sum[fx]-sum[fy];
	int lca=f[fx][0],len=dep[x]+dep[y]-2*dep[lca];
	if (len%2) return 0;
	len=len/2;
	fx=x;
	for(int i=Lg-1;i>=0;i--)
	 if (len>1<<i) fx=f[fx][i],len-=1<<i;
	return sum[f[fx][0]]-sum[fx];
}

int main(){
	read(n);
	memset(head,-1,sizeof head);
	for(int i=1;i<n;i++){
		int x,y;
		read(x);read(y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<Lg;i++)
	 for(int j=1;j<=n;j++)
	  f[j][i]=f[f[j][i-1]][i-1];
	read(m);
	while(m--){
		int x,y;
		read(x);read(y);
		printf("%d\n",sol(x,y));
	}
	return 0;
}
