#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=200001;
int n,t,x,a[N],cnt,f[N];
char c[N],ch;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);read(t);
	for(int i=1;i<=n;i++){
		ch=getchar();
		if (ch=='.') x=i;
		 else a[++cnt]=ch-'0';
	}
	for(int i=n-2;i>=0;i--)
	 if (a[i+1]>4) f[i]=1;
	  else if (a[i+1]==4&&f[i+1]>0) f[i]=f[i+1]+1;
	int i;
	for(i=0;i<n;i++)
	 if (f[i]>0&&f[i]<=t) break;
	a[i]++;
	if (i==0){
		printf("1");
		for(int i=1;i<x;i++) printf("0");
		return 0;
	}
	if (i==n) i--;
	for(int j=1;j<=i;j++)
	 if (j==x) printf(".%d",a[j]);
	  else printf("%d",a[j]);
	if (i<x-1) for(int j=i+1;j<=x-1;j++) printf("0");
	return 0;
}
