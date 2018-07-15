#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
int n,a[N],cnt;
map<int,int> mp;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i]),mp[a[i]]++;
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		int v=it->second;
		it->second=cnt+1;
		cnt+=v;
	}
	for(int i=1;i<=n;i++) printf("%d ",mp[a[i]]);
	return 0;
}
