#include <bits/stdc++.h>
using namespace std;
vector < char > que[ 10001 ];
int main( ) {
	int i, j, k;
	for( i = 2; i <= 10000; i ++ ) {
		 que[ i ].resize( i ); 
	}
	int N, M;
	scanf("%d %d", &N, &M );
	for( i = 1; i <= N; i ++ ) {
		scanf("%d %d", &j, &k );
		if( j < k ) {
			swap( &j, &k );
		} 
		que[ j ][ k ] = 1;
	}
	scanf("%d", &M );
	for( i = 1; i <= M; i ++ ) {
	     scanf("%d", &k );
	     for( j = 1; j <= k; j ++ ) {
	     	 
		 }
	}
}
