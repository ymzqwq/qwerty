#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1001;
int n,size,m,a[N],w,ans;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);read(size);read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if (a[i]==m){
			printf("1");
			return 0;
		}
	}
	sort(a+1,a+1+n);
	w=n*size;
	for(int i=n;i;i--){
		if (m>a[i]&&m<=w) ans++;
		if (-a[i]+1==(-i+1)*size) w=a[i]-1;
	}
	cout<<ans;
	return 0;
}
