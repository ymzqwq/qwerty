#include<bits/stdc++.h>
using namespace std;
const int N=1000001;
int n,m,a[N],ch[N][2],s[N],L,tag[N];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void dfs(int x,int d){
	d^=tag[x];
	if (d){
		if (ch[x][1]) dfs(ch[x][1],d);
		printf("%d ",x);
		if (ch[x][0]) dfs(ch[x][0],d);
	} else{
		if (ch[x][0]) dfs(ch[x][0],d);
		printf("%d ",x);
		if (ch[x][1]) dfs(ch[x][1],d);
	}
}

int main(){
	read(n);read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if (a[i]>s[L]){
			s[++L]=a[i];
			ch[s[L-1]][1]=a[i];
			continue;
		}
		for(;s[L]>a[i];L--);
		ch[s[L]][1]=a[i];
		ch[a[i]][0]=s[L+1];
		s[++L]=a[i];
	}
	for(int i=1;i<=m;i++){
		int x;
		read(x);
		tag[x]^=1;
	}
	dfs(s[1],0);
	return 0;
}
