#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1001;
int n,sum[N];
vector<int> a[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void dfs(int x){
	for(int i=0;i<a[x].size();i++){
		dfs(a[x][i]);
		sum[x]+=sum[a[x][i]];
	}
	sum[x]++;
}

int main(){
	read(n);
	for(int i=2;i<=n;i++){
		int fa;
		read(fa);
		a[fa].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=n;i++) printf("%d ",sum[i]);
	return 0;
}
