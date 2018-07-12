#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5001;
int n,m,s,t,dis[N],b[N];
vector<int> a[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);read(m);
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		int x,y;
		read(x);read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	read(s);read(t);
	dis[s]=0;
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=1;j<=n;j++)
		 if (b[j]==0&&dis[j]<dis[k]) k=j;
		if (k==0) break;
		b[k]=1;
		for(int j=0;j<a[k].size();j++)
		 if (b[a[k][j]]==0) dis[a[k][j]]=min(dis[a[k][j]],dis[k]+1);
	}
	if (dis[t]>1e8) printf("-1");
	 else printf("%d",dis[t]);
	return 0;
}
