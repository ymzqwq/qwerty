#include<bits/stdc++.h>
using namespace std;
const int N=40;
int a[13][3],n,po[11],sum[11];
char c[N];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	while(scanf("%s",c)>0){
		n++;
		if (c[0]=='/') a[n][1]=10,a[n][2]=-1;
		 else{
		 	a[n][1]=c[0]-'0';
		 	if (c[1]=='/') a[n][2]=10-a[n][1];
		 	 else a[n][2]=c[1]-'0';
		 }
	}
	for(int i=1;i<=10;i++){
		if (a[i][1]==10){
			po[i]=10+a[i+1][1];
			if (a[i+1][2]!=-1) po[i]+=a[i+1][2];
			 else po[i]+=a[i+2][1];
			sum[i]=sum[i-1]+po[i];
			continue;
		}
		if (a[i][1]+a[i][2]<10){
			po[i]=a[i][1]+a[i][2];
			sum[i]=sum[i-1]+po[i];
			continue;
		}
		po[i]=10+a[i+1][1];
		sum[i]=sum[i-1]+po[i];
	}
	for(int i=1;i<=10;i++) printf("%d ",po[i]);
	printf("\n");
	for(int i=1;i<=10;i++) printf("%d ",sum[i]);
	return 0;
}
