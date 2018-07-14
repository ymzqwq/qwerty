#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=8;
const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};
int n,m,T,sx,sy,tx,ty,a[N][N],f[N][N];
char c[N];
struct data{
	int x,y;
};
queue<data> h;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
} 

void bfs(){
	h.push((data){sx,sy});
	while(!h.empty()){
		int x=h.front().x,y=h.front().y;
		h.pop();
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if (xx>0&&xx<=n&&yy>0&&yy<=m&&a[xx][yy]==0&&f[xx][yy]==-1){
				f[xx][yy]=f[x][y]+1;
				h.push((data){xx,yy});
			}
		}
	}
}

int main(){
	read(n);read(m);read(T);
	for(int i=1;i<=n;i++){
		scanf("%s",c+1);
		for(int j=1;j<=m;j++)
		 if (c[j]=='X') a[i][j]=1;
		  else if (c[j]=='S') sx=i,sy=j;
		   else if (c[j]=='D') tx=i,ty=j;
	}
	memset(f,-1,sizeof f);
	f[sx][sy]=0;
	bfs();
	if (f[tx][ty]==-1){
		printf("NO");
		return 0;
	}
	if (f[tx][ty]<=T && f[tx][ty]%2==T%2) printf("YES");
	 else printf("NO");
	return 0;
}
