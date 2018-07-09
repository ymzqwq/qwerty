#include<bits/stdc++.h>
using namespace std;
const int N=1000001;
const int M=2000001;
const int Lg=20;
int n,m,Next[M],head[N],v[M],f[N][Lg],b[N],cnt,dep[N];

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
	 if (v[i]!=fa) dfs(v[i],x);
}

int getf(int x){
	for(int i=Lg-1;i>=0;i--)
	 if (!b[f[x][i]]) x=f[x][i];
	return f[x][0];
}

void baoli(int x){
	for(;!b[x];x=f[x][0]) b[x]=1;
}

int main(){
	read(n);read(m);
	m=n-m;
	memset(head,-1,sizeof head);
	for(int i=1;i<n;i++){
		int x,y;
		read(x);read(y);
		add(x,y);
		add(y,x);
	}
	dfs(n,0);
	for(int i=1;i<Lg;i++)
	 for(int j=1;j<=n;j++)
	  f[j][i]=f[f[j][i-1]][i-1];
	b[n]=1;b[0]=1;m--;
	for(int i=n-1;i;i--)
	 if (!b[i]){
		int fa=getf(i);
		if (dep[i]-dep[fa]<=m){
			m-=dep[i]-dep[fa];
			baoli(i);
		}
	 }
	for(int i=1;i<=n;i++)
	 if (!b[i]) printf("%d ",i);
	return 0;
}
