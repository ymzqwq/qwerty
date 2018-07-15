#include<bits/stdc++.h>
#define LL long long
#define lson ch[x][0]
#define rson ch[x][1]
using namespace std;
const int N=100001;
int n,a[N],ch[N][2],s[N],L,sum[N];
LL ans;

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void dfs(int x){
	if (lson) dfs(lson);
	if (rson) dfs(rson);
	sum[x]=sum[lson]+sum[rson]+1;
	ans=max(ans,1LL*a[x]*sum[x]);
}

int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if (a[i]>=a[s[L]]){
			s[++L]=i;
			ch[s[L-1]][1]=i;
			continue;
		}
		for(;L>0&&a[s[L]]>a[i];L--);
		L++;
		ch[i][0]=s[L];
		s[L]=i;
		ch[s[L-1]][1]=i;
	}
	dfs(s[1]);
	cout<<ans;
	return 0;
}
