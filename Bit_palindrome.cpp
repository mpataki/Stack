#include <iostream>

using namespace std;

void linear_space_solution(unsigned int num){
	bool arr[32];
	
	for ( int i=0; i<32; i++ ){
		arr[i] = num % 2;
		num = num >> 1;
	}

	for ( int i=0; i<16; i++ ){
		if ( arr[i] != arr[31-i] ) {
			cout << "false" << endl;
			return;
		}
	}

	cout << "true" << endl;
}

void constant_space_solution(unsigned int num){
	for ( int i=0; i<16; i++ ){
		unsigned int upper = 2147483648; // MSB is 1, all others are 0
		unsigned int lower = 1;					// LSB is 1, all others are 0
		upper = upper >> i;
		lower = lower << i;
		if ( (bool)(upper & num) != (bool)(lower & num) ){
			cout << "false" << endl;
			return;
		}
	}

	cout << "true" << endl;
}

int main(){
	unsigned int num;
	cin >> num;
	// linear_space_solution( num );
	constant_space_solution( num );
	return 0;
}
