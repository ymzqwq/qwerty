#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
int n,dis[N];
vector<int> a[N],v[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void dfs(int x,int f){
	for(int i=0;i<a[x].size();i++)
	 if (a[x][i]!=f){
	 	dis[a[x][i]]=dis[x]+v[x][i];
	 	dfs(a[x][i],x);
	 }
}

int main(){
	read(n);
	for(int i=1;i<n;i++){
		int x,y,z;
		read(x);read(y);read(z);
		a[x].push_back(y);
		a[y].push_back(x);
		v[x].push_back(z);
		v[y].push_back(z);
	}
	dfs(1,0);
	int x=1;
	for(int i=1;i<=n;i++) if (dis[i]>dis[x]) x=i;
	dis[x]=0;
	dfs(x,0);
	x=0;
	for(int i=1;i<=n;i++) x=max(x,dis[i]);
	cout<<x;
	return 0;
}
