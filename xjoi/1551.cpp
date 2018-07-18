#include<bits/stdc++.h>
using namespace std;
const int N=5002;
int n,f[N][N];
char c[N];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	read(n);
	scanf("%s",c+1);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n+1;i++) f[i][i]=f[i][i-1]=0;
	f[n+1][n]=0;
	int k;
	for(int i=1;i<n;i++)
	 for(int j=1;j<=n-i;j++){
	 	k=j+i;
	 	f[j][k]=min(f[j][k-1],f[j+1][k])+1;
	 	if (c[j]==c[k]) f[j][k]=min(f[j][k],f[j+1][k-1]);
	 }
	cout<<f[1][n];
	return 0;
}
