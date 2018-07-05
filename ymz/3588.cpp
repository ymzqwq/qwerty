#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1003;
char c[N];
int n,f[N],b[N][N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	scanf("%s",c+1);
	n=strlen(c+1);
	for(int i=1;i<=n;i++)
 	 for(int j=0;j<=min(i-1,n-i);j++)
  	  if (c[i-j]!=c[i+j]) break;else b[i-j][i+j]=1;
  	for(int i=1;i<n;i++)
  	 for(int j=0;j<=min(i-1,n-i-1);j++)
  	  if (c[i-j]!=c[i+j+1]) break;else b[i-j][i+j+1]=1;
  	for(int i=1;i<=n;i++) f[i]=n;
  	for(int i=1;i<=n;i++)
  	 for(int j=0;j<i;j++)
  	  if (b[j+1][i]) f[i]=min(f[i],f[j]+1);
  	cout<<f[n];
	return 0;
}
