#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
	if ( argc < 2 ) {
		cerr << "must supply file" << endl;
		return 1;
	}

	fstream strm(argv[1]);
	int i, result;
	result = 0;
	
	while( strm >> i )	
		result += i;

	cout << result << endl;
	return 0;
}
