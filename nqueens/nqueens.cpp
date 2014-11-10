#include <iostream>
#include <cstdlib>
using namespace std;

bool nqueens(int* rows, int n, int cur_row) {
	if ( n <= cur_row ) return true;
	for ( int q=0; q<n; q++ ) {
		for ( int i=0; i<cur_row; i++ )
			if ( (rows[i] == q) || (abs(rows[i]-q) == cur_row-i) ) goto CONTINUE;
		rows[cur_row] = q;
		if ( nqueens(rows, n, cur_row+1) ) return true;
		CONTINUE: continue;
	}
	return false;
}

int main( int argc, char* argv[] ) {
	cout << "Enter the size of the board." << endl;
	int n;
	cin >> n;
	// error checking on n would go here

	int rows[n];
	nqueens(rows, n, 0);

	for (int i=0; i<n; i++) {
		for (int j=0; j<rows[i]; j++) cout << " . ";
		cout << " Q ";
		for (int j=rows[i]+1; j<n; j++) cout << " . ";
		cout << endl;
	}

	return 0;
}
