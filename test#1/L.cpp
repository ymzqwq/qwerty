#include<bits/stdc++.h>
using namespace std;
const int N=301;
const int M=26;
int n,a[N],c[N];
map<int,int> mp;

inline void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(c[i]);
	map<int,int>::iterator it;
	mp[0]=0;
	for(int i=1;i<=n;i++)
	 for(it=mp.begin();it!=mp.end();it++){
	 	int g=gcd(a[i],it->first);
	 	if (!mp.count(g)) mp[g]=c[i]+it->second;
	 	 else mp[g]=min(mp[g],c[i]+it->second);
	 }
	if (!mp.count(1)) printf("-1");
	 else printf("%d",mp[1]);
	return 0;
}
