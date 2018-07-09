#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1001;
const int p=1e9+7;
int n,k;
LL s[N][N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);read(k);
	s[0][0]=1;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=i;j++)
	  s[i][j]=(s[i-1][j-1]+s[i-1][j]*(i-1))%p;
	cout<<s[n][k];
	return 0;
}
