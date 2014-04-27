#include <iostream>
#include <string>

using namespace std;

int main( int argc, char* argv[] ){
	string s;
	cin >> s;

	for ( int i=0; i<s.length()/2; i++ ){
		char tmp = s[i];
		s[i] = s[s.length()-1-i];
		s[s.length()-1-i] = tmp;
	}

	cout << s;

	return 0;
}
