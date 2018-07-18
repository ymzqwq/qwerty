#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int n,x,f[N],ans;
vector<int> a[N];

void read(int &x){//scanf("%d",&x);
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	read(n);
	//cout<<n<<endl;
	for(int i=1;i<=n;i++){
		read(x);
		for(int j=2;j*j<=x;j++)
		 if (x%j==0){
		 	a[i].push_back(j);
		 	while(x%j==0) x/=j;
		 }
		if (x>1) a[i].push_back(x);
	}
	for(int i=1;i<=n;i++){
		int mx=0;
		for(int j=0;j<a[i].size();j++)
		 f[a[i][j]]++,mx=max(mx,f[a[i][j]]);
		for(int j=0;j<a[i].size();j++)
		 f[a[i][j]]=max(f[a[i][j]],mx);
	}
	for(int i=1;i<N;i++) ans=max(ans,f[i]);
	cout<<max(1,ans);
	return 0;
}
