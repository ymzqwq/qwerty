#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1001;
int n,m,a[N][N],col[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void dfs(int x){
	for(int i=1;i<=n;i++)
	 if (a[x][i]){
	 	if (col[i]==col[x]){
	 		printf("No");
	 		exit(0);
	 	}
	 	if (!col[i]){
	 		col[i]=3-col[x];
	 		dfs(i);
	 	}
	 }
}

int main(){
	read(n);read(m);
	for(int i=1;i<=m;i++){
		int x,y;
		read(x);read(y);
		a[x][y]=a[y][x]=1;
	}
	for(int i=1;i<=n;i++)
	 if (!col[i]) col[i]=1,dfs(i);
	printf("Yes");
	return 0;
}
