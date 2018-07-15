#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=27;
const int dx[8]={-2,-2,-1,-1,1,1,2,2};
const int dy[8]={-1,1,-2,2,-2,2,-1,1};
int n,m,b[N][N],c[N],d[N],cnt;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void dfs(int x,int y){
	if (cnt==n*m){
		for(int i=1;i<=cnt;i++) printf("%c%d",c[i]+'A'-1,d[i]);
		exit(0);
	}
	cnt++;
	for(int i=0;i<8;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if (xx>0&&xx<=n&&yy>0&&yy<=m&&b[xx][yy]==0){
			b[xx][yy]=1;
			c[cnt]=xx;d[cnt]=yy;
			dfs(xx,yy);
			b[xx][yy]=0;
		}
	}
	cnt--;
	/*printf("impossible");
	exit(0);*/
}

int main(){
	read(m);read(n);
	cnt=1;
	c[1]=1;d[1]=1;
	b[1][1]=1;
	dfs(1,1);
	printf("impossible");
	return 0;
}
