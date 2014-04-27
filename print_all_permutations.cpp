#include <iostream>
#include <string>

using namespace std;

void print_with_replacement(string s){
	unsigned int c[s.length()];
	for( unsigned int i=0; i<s.length(); i++ ) 
		c[i] = 0;	

	while (1){
		for( unsigned int i=0; i<s.length(); i++ ) 
			cout << s[c[i]];
		cout << endl;

		for( unsigned int i=s.length() -1; ; i-- ){
			unsigned int tmp = c[i];
			c[i] = (c[i] +1) % s.length();
			if ( i == 0 && tmp >= c[i] ) return 0;
			if ( tmp < c[i] ) break;
		}
	}
}

void print_wo_replacement(string prefix, string s){
	if (s.length() == 1) cout << prefix << s << endl;
	else 
		for ( int i=0; i<s.length(); i++ ){
			string new_prefix = prefix + s[i];
			string new_s = s;
			string::iterator it = new_s.find(s[i]);
			new_s.erase(it);
			print_wo_replacement( new_prefix, new_s );
		}
}

int main( int argc, char* argv[] ){
	string s;
	cin >> s;

	// print_with_replacement(s);
	print_wo_replacement("", s);

	return 0;
}
