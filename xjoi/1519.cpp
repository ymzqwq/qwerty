#include<bits/stdc++.h>
using namespace std;
const int N=51;
const int dx[6]={0,0,0,0,1,-1};
const int dy[6]={0,0,1,-1,0,0};
const int dz[6]={1,-1,0,0,0,0};
int l,w,h,m,a[N][N][N],f[N][N][N],cnt;
struct data{
	int x,y,z;
};
queue<data> q;

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void bfs(data e){
	q.push(e);
	while(!q.empty()){
		e=q.front();
		q.pop();
		for(int i=0;i<6;i++){
			int x=e.x+dx[i],y=e.y+dy[i],z=e.z+dz[i];
			if (x>0&&x<=l&&y>0&&y<=w&&z>0&&z<=h&&abs(a[e.x][e.y][e.z]-a[x][y][z])<=m&&f[x][y][z]==0){
				f[x][y][z]=cnt;
				q.push((data){x,y,z});		
			}
		}
	}
}

int main(){
	read(l);read(w);read(h);
	read(m);
	for(int i=1;i<=l;i++)
	 for(int j=1;j<=w;j++)
	  for(int k=1;k<=h;k++)
	   read(a[i][j][k]);
	for(int i=1;i<=l;i++)
	 for(int j=1;j<=w;j++)
	  for(int k=1;k<=h;k++)
	   if (!f[i][j][k]){
	   		f[i][j][k]=++cnt;
	   		bfs((data){i,j,k});
	   }
	cout<<cnt;
	return 0;
}
