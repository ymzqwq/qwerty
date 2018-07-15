#include<bits/stdc++.h>
using namespace std;
const int N=7;
const int d[7][7]={{0},{0,2,6,3,4,1,5},{0,4,2,1,6,5,3},{0,3,2,6,1,5,4},{0,5,1,3,4,6,2},{0,1,4,2,5,3,6},{0,1,3,5,2,4,6}};
int n,ans,a[N];
char c[N];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void wr(int x){
	int b[N];
	for(int i=1;i<N;i++)
	 b[i]=a[d[x][i]];
	for(int i=1;i<N;i++) a[i]=b[i];
}

int main(){
	read(n);
	ans++;
	for(int i=1;i<N;i++) a[i]=i;
	for(int i=1;i<=n;i++){
		scanf("%s",c);
		if (c[0]=='N') wr(1);
		if (c[0]=='E') wr(2);
		if (c[0]=='W') wr(3);
		if (c[0]=='S') wr(4);
		if (c[0]=='L') wr(5);
		if (c[0]=='R') wr(6);
		ans+=a[1];
	}
	cout<<ans;
	return 0;
}
