#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
LL n,ans,sum;
char c[11];

void read(LL &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void dfs(int k){
	if (k>=strlen(c)){ ans++;return; }
	dfs(k+1);
	if (c[k]!='0') dfs(k+1);
}

int main(){
	scanf("%s",c);
	dfs(1);
	cout<<ans+(1<<strlen(c)-1)-1;
	return 0;
}
