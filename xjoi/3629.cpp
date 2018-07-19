#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=200001;
const int M=N<<1;
const int Lg=21;
int n,m,f[N][Lg+1],b[M],d[N][Lg+1],rt,cnt=-1;
int head[N],Next[M],v[M],w[M],dep[N];
LL mn,cx=1e18;
struct data{
	int u,v,w;
}a[M];

void read(int &x){
	scanf("%d",&x);
	/*char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';*/
}

int cmp(const data &q,const data &w){
	return q.w<w.w;
}

void add(int x,int y,int z){
	Next[++cnt]=head[x];
	head[x]=cnt;
	v[cnt]=y;w[cnt]=z;
}

void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=head[x];i!=-1;i=Next[i])
	 if (v[i]!=fa){
	 	d[v[i]][0]=w[i];
	 	dfs(v[i],x);
	 }
}

int lca(int x,int y){
	int ans=0;
	if (dep[x]<dep[y]) x^=y^=x^=y;
	for(int j=Lg;j>=0;j--)
	 if (dep[f[x][j]]>=dep[y]){
	 	ans=max(ans,d[x][j]);
	 	x=f[x][j];
	 }
	if (x==y) return ans;
	for(int j=Lg;j>=0;j--)
	 if (f[x][j]!=f[y][j]){
	 	ans=max(ans,max(d[x][j],d[y][j]));
	 	x=f[x][j];y=f[y][j];
	 }
	ans=max(ans,max(d[x][0],d[y][0]));
	return ans;
}

int gf(int x) { return f[x][0]==x?x:f[x][0]=gf(f[x][0]); }

int main(){
	memset(head,-1,sizeof head);
	read(n);read(m);
	for(int i=1;i<=m;i++) read(a[i].u),read(a[i].v),read(a[i].w);
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++) f[i][0]=i;
	for(int i=1;i<=m;i++){
		int fx=gf(a[i].u),fy=gf(a[i].v);
		if (fx!=fy){
			b[i]=1;
			mn+=a[i].w;
			add(a[i].u,a[i].v,a[i].w);
			add(a[i].v,a[i].u,a[i].w);
			f[fx][0]=fy;
			//d[fx][0]=a[i].w;
		}
	}
	for(int i=1;i<=n;i++) if (f[i][0]==i) { rt=i;break; };
	dfs(rt,0);
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=Lg;j++){
	 	f[i][j]=f[f[i][j-1]][j-1];
	 	d[i][j]=max(d[i][j-1],d[f[i][j-1]][j-1]);
	 }
	for(int i=1;i<=m;i++)
	 if (!b[i]){
	 	int zd=lca(a[i].u,a[i].v);
	 	cx=min(cx,mn-zd+a[i].w);
	 }
	cout<<mn<<' '<<cx<<endl;
	return 0;
}
