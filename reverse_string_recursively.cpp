#include <iostream>
#include <string>

using namespace std;

string reverse( string s, string result ){
	if ( s.length() == 0 ) return result;
	result.push_back( s.back() );
	s.pop_back();
	return reverse( s, result );
}

int main( int argc, char* argv[] ){
	string s;
	cin >> s;

	cout << reverse(s, "") << endl;

	return 0;
}
