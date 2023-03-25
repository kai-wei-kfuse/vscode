/*********************************************************************
    程序名:
    日期: 2022-04-06 17:45
*********************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
int line1[ 10000 ];
int line2[ 10000 ];
int right1 = 0, right2 = 0;

int Getyear( int month, int day ) {
	int year = 0;
	year += day % 10;
	day /= 10;
	year *= 10;
	year += day;
	year *= 10;
	year += month % 10;
	month /= 10;
	year *= 10;
	year += month;
	return year;
}

bool check( int year ) {
	if ( year % 4 ) {
		return false;
	} else if ( !( year % 100 ) ) {
		return false;
	}
	return true;
}

int main( ) {
	int month, day, year;
	int monthday[ 13 ] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool run = 0;
	for ( month = 1; month <= 12; month ++ ) {
		for ( day = 1; day <= monthday[ month ]; day ++ ) {
			if ( day % 10 == 0 ) {
				continue;
			}
			year = Getyear( month, day );
			if ( !check( year ) && month == 2 && day == 29  ) {
				continue;
			} else {
				year *= 10000;
				year += month * 100;
				year += day;
			}
			line1[ ++ right1 ] = year;
			if ( month == day ) {
				line2[ ++ right2 ] = year;
			}
		}
	}
	sort( line1 + 1, line1 + right1 + 1 );
	sort( line2 + 1, line2 + right2 + 1 );
	int T, need;
	int i, j, k;
	scanf("%d", &T );
	while ( T -- ) {
		scanf("%d", &need );
		for ( i = 1; i <= right1; i ++ ) {
			if ( line1[ i ] > need ) {
				printf("%d\n", line1[ i ] );
				break;
			}
		}
		for ( i = 1; i <= right2; i ++ ) {
			if ( line2[ i ] > need ) {
				printf("%d\n", line2[ i ] );
				break;
			}
		}
	}
	return 0;
}