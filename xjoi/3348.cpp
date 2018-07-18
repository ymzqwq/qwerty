#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=201;
int n,a[N][N],m,f[N][2],ans;
struct data{
	int x,b;
};
queue<data> h;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void bfs(){
	h.push((data){1,0});
	while(!h.empty()){
		data q=h.front();
		h.pop();
		for(int i=1;i<=n;i++)
		 if (a[q.x][i]&&f[i][q.b^1]==0){
		 	f[i][q.b^1]=1;
		 	h.push((data){i,q.b^1});
		 }
	}
}

int main(){
	read(n);read(m);
	for(int i=1;i<=m;i++){
		int x,y;
		read(x);read(y);
		a[x][y]=1;
		a[y][x]=1;
	}
	f[1][0]=1;
	bfs();
	for(int i=1;i<=n;i++)
	 if (f[i][1]) ans++;
	cout<<ans;
	return 0;
}
