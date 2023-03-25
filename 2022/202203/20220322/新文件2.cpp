#include <bits/stdc++.h>
#define MaxN 1000001
using namespace std;
int abc[ 26 ];
map<char, int >mp;
queue< char > que;
deque< char > ch;
int leftnum = 0, rightnum = 0, linenum = 0;

int main( )  {
	int i, j, k, total = 0;
	string linel, liner;
	char temp;
	bool test = 1;
	while ( 1 ) {
		temp = getchar( );
		if ( temp == '\n' ) {
			break;
		} else if ( temp == '<' ) {
			leftnum ++;
		} else if ( temp == '>' ) {
			rightnum ++;
		} else if ( temp == '/' ) {
			linenum ++;
		} else {
			total ++;
			abc[ temp - 'a' ] ++;
			mp[ temp ] ++;
		}
	}
	if ( !linenum ) {
		cout << "Impossible\n";
		return 0;
	}
	total /= 2;
	if ( total < linenum ) {
		test = 0;
	}
	if ( leftnum != linenum * 2 || rightnum != linenum * 2 ) {
		test = 0;
	}
	for (map<char, int > ::iterator i = mp.begin(); i != mp.end(); i++) {
		//cout<<(*i).first<<' ';
		while ((*i).second) {
			que.push((*i).first);
			(*i).second--;
		}
		if ((*i).first != '/' && (*i).second % 2 != 0) {
			cout << "Impossible";
			return 0;
		}
	}
	for ( i = 0; i < 26; i ++ ) {
		if ( abc[ i ] % 2 ) {
			test = 0;
		}
		//while ( abc[ i ] ) {
		//que.push( 'a' + i );
		//abc[ i ] --;
		//}
		while ( mp[ 'a' + i ] ) {
			//que.push( 'a' + i );
			//mp[ 'a' + i  ] --;
		}
	}
	if ( !test ) {
		cout << "Impossible\n";
		return 0;
	}
	map<char, int > ::iterator ii = mp.find('>');
	ii++;
	string a;
	for ( i = 1; i < linenum; i ++ ) {

		/*linel += '<';
		linel += que.front( );
		que.pop( );
		linel += '>';
		string temp1;
		temp1 += "</";
		temp1 += que.front( );
		que.pop( );
		temp1 += '>';
		temp1 += liner;
		liner = temp1;*/
		ch.push_back('<');
		ch.push_back('/');
		ch.push_back(que.front( ));
		que.pop( );
		ch.push_back('>');
		//ch.push_front('>');
		//ch.push_front(que.front( ));
		a += ">";
		a += que.front();
		a += "<";
		que.pop( );
		ch.push_front(a);
		a.clear();
	}
	string temp2;
	temp2 += "</";
	linel += '<';
	ch.push_back('<');
	ch.push_back('/');
	//ch.push_front('>');
	a += ">";
	while ( !que.empty( ) ) {
		//linel += que.front( );
		ch.push_back(que.front( ));
		que.pop( );
		//temp2 += que.front( );
		//ch.push_front(que.front( ));
		a += que.front();
		que.pop( );

	}
	temp2 += '>';
	linel += '>';
	temp2 += liner;
	ch.push_back('>');
	//ch.push_front('<');
	a += "<";
	ch.push_front(a);
	//cout << linel << temp2 << endl;
	//for (int i = a.length() - 1; i >= 0; i --)
	//cout << a[i];
	for (deque<char>::iterator i = ch.begin(); i != ch.end(); i++) {
		cout << (*i);
	}
}