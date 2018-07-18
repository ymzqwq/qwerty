#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2001;
const int p=1e9+7;
int n,a[N],sum,q,b[N];
LL mul[N],P[N],C[N][N],ans;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if (a[i]==-1) sum++;
		 else b[a[i]]=1;
	}
	for(int i=1;i<=n;i++) if (b[i]&&a[i]==-1) q++;
	
	mul[0]=1;
	for(int i=1;i<=n;i++) mul[i]=mul[i-1]*i%p;
	/*P[0]=1;P[1]=0;
	for(int i=2;i<=n;i++) P[i]=(n-1)*(P[i-1]+P[i-2])%p;*/
	C[0][0]=1;
	for(int i=1;i<=n+1;i++)
	 for(int j=1;j<=n+1;j++)
	  C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
	
	ans=mul[sum];int w=1;
	for(int i=1;i<=sum-q;i++){
		w*=-1;
		ans=(ans+w*C[sum-q+1][i+1]*mul[sum-i]%p)%p;
	}
	
	cout<<(ans+p)%p;
	return 0;
}
