#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1001;
int n,s,t,a[N][N],dep[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void dfs(int x,int f){
	dep[x]=dep[f]+1;
	if (x==t){
		printf("%d",dep[x]-1);
		exit(0);
	}
	for(int i=1;i<=n;i++)
	 if (a[x][i]&&i!=f) dfs(i,x);
}

int main(){
	read(n);
	for(int i=1;i<n;i++){
		int x,y;
		read(x);read(y);
		a[x][y]=a[y][x]=1;
	}
	read(s);read(t);
	dfs(s,0);
	return 0;
}
