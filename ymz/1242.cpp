#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2001;
int n,tot[N],b[N][N];
char c[N];
LL ans;

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
	  if (c[i-j]!=c[i+j]) break;
	   else b[i-j][i+j]=1;
	for(int i=1;i<n;i++)
	 for(int j=0;j<=min(i-1,n-i-1);j++)
	  if (c[i-j]!=c[i+j+1]) break;
	   else b[i-j][i+j+1]=1;
	for(int i=1;i<=n;i++)
	 for(int j=i;j<=n;j++)
	  if (b[i][j]) tot[i]++;
	for(int i=n-1;i;i--) tot[i]+=tot[i+1];
	for(int i=1;i<=n;i++)
	 for(int j=i;j<=n;j++)
	  if (b[i][j]) ans+=tot[j+1];
	cout<<ans;
	return 0;
}
