#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=203;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int n,m,sx,sy,f[N][N],b[N][N];
char c[N][N];
struct data{
	int x,y;
};
queue<data> q;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int pd(int x,int y){
	if (x<1||y<1||x>n||y>m||c[x][y]=='#') return 0;
	return 1;
}

int bfs(int x,int y){
	memset(f,0x3f,sizeof f);
	q.push((data){x,y});f[x][y]=0;b[x][y]=1;
	while(!q.empty()){
		data w=q.front();
		q.pop();b[w.x][w.y]=0;
		for(int i=0;i<4;i++){
			x=w.x+dx[i];y=w.y+dy[i];
			if (pd(x,y)){
				int ans=f[w.x][w.y]+1;
				if (c[x][y]=='G') ans++;
				if (ans<f[x][y]){
					f[x][y]=ans;
					if (!b[x][y]) q.push((data){x,y}),b[x][y]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  if (c[i][j]=='M')
	   if (f[i][j]>n*m) return -1;else return f[i][j];
}

int main(){
	read(n);read(m);
	for(int i=1;i<=n;i++) scanf("%s",c[i]+1);
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  if (c[i][j]=='@'){
	  	int ans=bfs(i,j);
	  	if (ans==-1) printf("You can't save Mengxin");
	  	 else printf("%d",ans);
	  	return 0;
	  }
	return 0;
}
