#include <iostream>

using namespace std;

class Board {
	char board[3][3];
public:
	Board(){
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				board[i][j] = ' ';
	}

	void print(){
		for(int i=0; i<3; i++){
			cout << "|";
			for(int j=0; j<3; j++){
				cout << board[i][j] << "|";
			}
			cout << endl;
			if (i != 3) cout << "-------" << endl;
		}
	}

	// 0 == no winner, 1 == winner, 2 == cat game, 3 == out of bounds
	int select(char c, int i, int j){
		if (i<3 && j<3) board[i][j] = c;
		else return 3;
		
		//horizontal
		int k=0;
		for (; k<3; k++)
			if (board[i][k] != c) break;
		if (k == 3) return 1;
		
		// vertical
		k=0;
		for (; k<3; k++)
			if (board[k][j] != c) break;
		if (k == 3) return 1;

		// diagonal
		int p=0; 
		int q=0;
		for (; p<3 && q<3; p++, q++)
			if (board[p][q] != c) break;
		if ( p == 3 ) return 1;

		p=2; 
		q=2;
		for (; p>=0 && q>=0; p--, q--)
			if (board[p][q] != c) break;
		if ( p == -1 ) return 1;

		// cat game
		for (p=0; p<3; p++)
			for (q=0; q<3; q++)
				if (board[p][q] == ' ') goto label;
		label: if ( p == 3 ) return 2;
		return 0;
	}
};

int main(){
	Board board;
	int player = 1;
	while(1){
		int i, j;
		board.print();
		cout << "Player" << player << "'s turn" << endl;
		cin >> i;
		cin >> j;
		int result = board.select( (player == 1) ? 'X' : 'O' , i, j);
		if ( result == 1 ) {
			cout << "Player " << player << " wins!" << endl;
			break;
		} else if ( result == 2 ) {
			cout << "Cat game!" << endl;
			break;
		} else if ( result == 3 ) continue;
		player = (player == 1) ? 2 : 1;
	}
	return 0;
}
