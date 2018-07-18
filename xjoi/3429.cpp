#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=101;
const int p=10000;
int n;
LL ans,sum;

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	cin>>n;
	/*ans=1;sum=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i+1)%p;
		//printf("%d %lld\n",i,ans);
	}
	if (n<=6) cout<<ans<<endl;
	 else{
	 	int sum;
	 	if (ans<10) sum=3;
	 	 else if (ans<100) sum=2;
	 	  else if (ans<1000) sum=1;
	 	   else sum=0;
	 	for(int i=1;i<=sum;i++) printf("0");
	 	printf("%lld\n",ans);
	 }*/
	 
	ans=1;sum=1;
	for(int i=n;i>=max(1,n-p);i--){
		sum=sum*i%p;
		ans=(ans+sum)%p;
	}
	if (n<=6) cout<<ans;
	 else{
	 	int sum;
	 	if (ans<10) sum=3;
	 	 else if (ans<100) sum=2;
	 	  else if (ans<1000) sum=1;
	 	   else sum=0;
	 	for(int i=1;i<=sum;i++) printf("0");
	 	printf("%lld",ans);
	 }
	return 0;
}
