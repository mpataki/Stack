#include <iostream>
#include <string>

using namespace std;

int atoi(string s){
	int result = 0;
	unsigned int i = 0;
	int sign = 1;
	
	if ( s[0] == '-' ) {
		sign = -1;
		i++;
	}

	for (; i<s.length(); i++){
		if ( s[i] < '0' || s[i] > '9' ) return -1; // error: string not a number ( would throw an error here )
		result *= 10;
		result += s[i] - '0';
	}

	result *= sign;

	return result;
}

int main( int argc, char* argv[] ){
	string s;	
	cin >> s;

	cout << atoi(s);

	return 0;
}
