#include <iostream>
#include <fstream>

using namespace std;

// assumes file contains positive ints
int main(int argc, char* argv[]){
	if ( argc < 2 ) { cout << "must supply file" << endl; return 1; }
	
	fstream fstrm(argv[1]);
	unsigned int max1 = 0;
	unsigned int max2 = 0;
	unsigned int input = 0;

	while ( fstrm >> input ){
		if ( input >= max1 ) {
			max2 = max1;
			max1 = input;
		}
	}

	cout << max2;
	return 0;
}
