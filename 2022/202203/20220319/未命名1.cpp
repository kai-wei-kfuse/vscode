int upper_bound(int *a,int n,int x){
	int l = 1,r = n;
	while(l<r){
		int mid = l + r >> 1; 
		if(a[mid]>x){
			r = mid ;
		}else l = mid + 1; 
	}
	return l;
} 
int lower_bound(int * a,int n,int x){
	int l = 1, r = n;
	while(l<r){
		int mid = l + r >> 1;
		if(a[mid] >= x)r = mid;
		else l = mid+1;
	}
}
