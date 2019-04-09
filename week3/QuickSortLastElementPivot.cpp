#include<bits/stdc++.h>
long int comparisons=0;

int partition(std::vector<int>& a, int l, int r){
	int t=a[l];
	a[l]=a[0];
	a[0]=t;
	int p=a[0];
	int i=1;
	for(int j=1;j<r;j++)
		if(a[j]<p){
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
			i+=1;
		}
	t=a[0];
	a[0]=a[i-1];
	a[i-1]=t;
	return i-1;
}

void quicksort(std::vector<int>& a, int n){
	if(a.size()<=1)return;
	/*for(int i=0;i<n;i++)
		std::cout<<"Hey "<<a[i]<<" ";
	std::cout<<"\n";*/
	int p=n-1;
	int r=partition(a, p, n);
	comparisons+=n-1;
	std::vector<int> c(r);
	for(int i=0;i<r;i++)
		c[i]=a[i];
	quicksort(c, r);
	std::vector<int> b(n-r-1);
	for(int i=0;i<n-r-1;i++)
		b[i]=a[i+r+1];
	quicksort(b, n-r-1);
}

int main(){
	int n;
	scanf("%d", &n);
	std::vector<int> a(n);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	quicksort(a, a.size());
	std::cout<<comparisons<<std::endl;
	return 0;
}
