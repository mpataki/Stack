#include <iostream>
#include <string>
using namespace std;

string excel_column(int k){
	string result = "";
	
	while (k){
		result.push_back((char)('A'+ (k % 26)));
		k -= (k%26);
		k /= 26;
	}

	// reverse string
	return result;
}

int main(){
	int k;
	cin >> k;
	cout << excel_column(k) << endl;
	return 0;
}
