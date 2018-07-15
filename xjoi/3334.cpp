#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1001;
int n,dep[N],x,y,f[N];
vector<int> a[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void dfs(int x){
	for(int i=0;i<a[x].size();i++){
		dep[a[x][i]]=dep[x]+1;
		dfs(a[x][i]);
	}
}

int main(){
	read(n);
	for(int i=2;i<=n;i++){
		int fa;
		read(fa);
		f[i]=fa;
		a[fa].push_back(i);
	}
	dfs(1);
	read(x);read(y);
	if (dep[x]<dep[y]) x^=y^=x^=y;
	while(dep[x]>dep[y]) x=f[x];
	while(x!=y) x=f[x],y=f[y];
	cout<<x;
	return 0;
}
