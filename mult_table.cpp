#include <iostream>

using namespace std;

int main( int argc, char* argv[] ){
	for (int i=1; i<13; i++){
		for (int j=1; j<13; j++){
			cout << i*j << "\t";
		}
		cout << endl;
	}
	return 0;
}
