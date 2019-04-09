#include<bits/stdc++.h>
long int comparisons=0;

int partition(std::vector<int>& a, int l, int r){
	int p=a[l];
	int temp=0;
	if(a.size()>2&&a.size()%2!=0){
		int k=a[a.size()/2];
		if((a[l]>k&&a[r-1]<k)||(a[l]<k&&a[r-1]>k))
			temp=a.size()/2;
		else if((a[l]>k&&a[r-1]>a[l])||(a[l]<k&&a[r-1]<a[l]))
			temp=l;
		else if((a[r-1]>k&&a[r-1]<a[l])||(a[r-1]<k&&a[r-1]>a[l]))
			temp=r-1;
	}
	else if(a.size()>2&&a.size()%2==0){
		int k=a[(a.size()/2)-1];
		if((a[l]>k&&a[r-1]<k)||(a[l]<k&&a[r-1]>k))
			temp=(a.size()/2)-1;
		else if((a[l]>k&&a[r-1]>a[l])||(a[l]<k&&a[r-1]<a[l]))
			temp=l;
		else if((a[r-1]>k&&a[r-1]<a[l])||(a[r-1]<k&&a[r-1]>a[l]))
			temp=r-1;
	}
	int t=a[0];
	a[0]=a[temp];
	a[temp]=t;
	p=a[0];
	int i=l+1;
	for(int j=l+1;j<r;j++)
		if(a[j]<p){
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
			i+=1;
		}
	t=a[l];
	a[l]=a[i-1];
	a[i-1]=t;
	return i-1;
}

void quicksort(std::vector<int>& a, int n){
	if(a.size()<=1)return;
	/*for(int i=0;i<n;i++)
		std::cout<<"Hey "<<a[i]<<" ";
	std::cout<<"\n";*/
	int p=0;
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
