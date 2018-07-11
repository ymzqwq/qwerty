#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
LL n,a[N],f[N][2],be[N];
string s[N][2];

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	getline(cin,s[0][0]);
	for(int i=1;i<=n;i++){
		getline(cin,s[i][0]);
		s[i][1]=s[i][0];
		reverse(s[i][1].begin(),s[i][1].end());
	}
	memset(f,0x3f,sizeof f);
	f[1][1]=a[1];f[1][0]=0;
	for(int i=2;i<=n;i++)
	 for(int j=0;j<2;j++)
	  for(int k=0;k<2;k++)
	   if (s[i-1][j]<=s[i][k]) f[i][k]=min(f[i][k],f[i-1][j]+k*a[i]);
	LL ans=min(f[n][0],f[n][1]);
	if (ans>1e14) cout<<"-1";
	 else cout<<ans;
	return 0;
}
