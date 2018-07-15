#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100005;
int n,f[N],tot[N],k;
char c[N];
LL ans;

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	scanf("%d%s",&k,c+1);
	int n=strlen(c+1);
	if (k==0){
		LL sum=0;
		for(int i=1;i<=n;i++)
		 if (c[i]=='0') sum++;
		  else ans+=sum*(sum+1)/2,sum=0;
		ans+=sum*(sum+1)/2;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) f[i]=f[i-1]+(c[i]=='1');
	for(int i=0;i<=n;i++) tot[f[i]]++;
	for(int i=0;i<=f[n]-k;i++)
	 ans+=1LL*tot[i]*tot[i+k];
	cout<<ans;
	return 0;
}
