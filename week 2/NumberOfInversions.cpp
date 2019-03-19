#include<bits/stdc++.h>
using namespace std;
long int inv=0;

vector<long int> merge(vector<long int>& a, vector<long int>& b){
	long int n=a.size()+b.size();int temp=0;
	vector<long int> c(n);
	/*if(a[0]==1){
		printf("Size of b=%ld %ld %ld %ld\n",b.size(), b[0], b[1], b[2]);
	}*/
	long int i=0, j=0;
	for(int k=0;k<n;k++){
		if((i==a.size())&&(j!=b.size())){
			c[k]=b[j];
			++j;
		}
		else if(j==b.size()&&i!=a.size()){
			c[k]=a[i];
			++i;
		}
		else if(a[i]>b[j]){
			c[k]=b[j];
			inv+=a.size()-i;
			temp+=a.size()-i;
			++j;
		}
		else if(a[i]<b[j]){
			c[k]=a[i];
			++i;
		}
	}
	/*if(a[0]==1){
		printf("%ld %ld %ld\n%d\n", c[0], c[1], c[2], temp);
	}*/
	return c;
}

void inversions(vector<long int>& a){
	long int n=a.size();
	if(n==2){
		if(a[0]>a[1]){
			++inv;
			long int temp=a[1];
			a[1]=a[0];
			a[0]=temp;
		}
	}
	else if(n==1){}
	else{
		n/=2;
		vector<long int> b(n), c(a.size()-n), d(a.size());
		for(long int i=0;i<n;i++)
			b[i]=a[i];
		for(long int i=0;i<c.size();i++)
			c[i]=a[i+n];
		inversions(b);
		inversions(c);
		d=merge(b, c);
		a=d;
	}
}

int main(){
	long int n;
	scanf("%ld", &n);
	vector<long int> a(n);
	for(int i=0;i<n;i++)
		scanf("%ld", &a[i]);
	inversions(a);
	printf("%ld\n", inv);
	return 0;
}
