#include <iostream>
#include <string>

using namespace std;

int main( int argc, char* argv[] ) {
	string input, result;
	cin >> input;
	for ( int i=input.length()-1; i>= 0; i-- )
		result.push_back( input[i] );
	cout << result << endl;
	return 0;
}
