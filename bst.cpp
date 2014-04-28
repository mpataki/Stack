#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Node {
	Node* left;
	Node* right;
	int val;

public:

	Node(int val) : val(val), left(NULL), right(NULL) {}
	
	void deleteAll(){
		if ( left ) left->deleteAll();
		if ( right ) right -> deleteAll();
		delete this;
	}

	Node* getLeft() { return left; }
	Node* getRight() { return right; }
	int getVal() { return val; }

	int findLargest(){
		if (right == NULL) return val;
		return right->findLargest();
	}

	int findSmallest(){
		if (left == NULL) return val;
		return left->findSmallest();
	}

	void insert(int i){
		if ( i == val ) return;
		
		if ( i < val ) {
			if ( left == NULL ) left = new Node(i);
			else left->insert(i);
		} else if ( i > val ) {
			if ( right == NULL ) right = new Node(i);
			else right->insert(i);
		}
	}

	void remove(int i){
		if ( i == val ){
			if ( (left == NULL) && (right == NULL) ) delete this; // leaf

			else if ( (left == NULL) != (right == NULL) ){ 		// only one child
				Node* child = ( left ) ? left : right; 	// pick non-null child
				left = child->getLeft();
				right = child->getRight();
				val = child->getVal();
				delete child;
			}

			else { // two children
				val = left->findLargest();
				left->remove(val);
			}

		} else if ( i < val ) {
			if ( left == NULL ) return; 	// not found
			if ( left->getLeft() == NULL && left->getRight() == NULL ) {
				left->remove(i);
				left = NULL;
			} else left->remove(i);
		
		} else if ( i > val ) {
			if ( right == NULL ) return; 	// not found
			if ( right->getLeft() == NULL && right->getRight() == NULL ) {
				right->remove(i);
				right = NULL;
			} else right->remove(i);
		}
	}

	bool search(int i){
		if ( val == i ) return true;
		if ( i < val && left ) return left->search(i);
		if ( i > val && right ) return right->search(i);
		return false;
	}

	void print(string spaces){
		string child_spaces = spaces;
		child_spaces.push_back( '\t' );
		if ( right ) right->print( child_spaces );
		cout << spaces << val << endl;
		if ( left ) left->print( child_spaces );
	}

	// find the second largest element
	int secondLargest(int second_largest){
		if ( right ) return right->secondLargest( val );
		if ( left ) return left->findLargest();
		return second_largest;
	}

	// count the number of edges between nodes i and j
	// for now, assume i and j are distinct and that they exist in the tree
	int findDistance(int i, int j){
		if ( i > j ) { int tmp = j; j = i; i = tmp; }	// enforce i < j
		if ( i == j ) return 0;
		if ( i == val && right ) return right->findDistance(right->getVal(), j) + 1;
		if ( j == val && left ) return left->findDistance(i, left->getVal()) + 1;
		if ( i < val && j < val && left ) return left->findDistance(i, j);
		if ( i > val && j > val && right ) return right->findDistance(i, j);
		if ( i < val && j > val && left && right ) return left->findDistance( i, left->getVal() ) +
																											right->findDistance( right->getVal(), j ) + 2;
    return -1; // node doesn't exist. ( this will produce unexpected results currently. )
	}

	// find the closest element
	int findClosest(int i, int closest){
		if ( (i != val) && (abs(i - closest) > abs(i - val)) ) closest = val;
		
		if ( i < val ){
		 if (left) left->findClosest(i, closest);
		 else return closest;
		}
		
		else if ( i > val ) {
			if (right) right->findClosest(i, closest);
			else return closest;
		} 
		
		else { // i == val
			if (left) {
				int k = left->findLargest();
				closest = (abs(i-k) < abs(i-closest)) ? k : closest;
			}
			if (right) {
				int k = right->findSmallest();
				closest = (abs(i-k) < abs(i-closest)) ? k : closest;
			}
		}

		return closest;
	}

};

int main( int argc, char* argv[] ){
	int val;
	cout << "Enter values to be inserted into a tree. Enter -1 to stop insertion." << endl;
	cin >> val;

	Node* root = new Node(val);
	cout << "\033[2J\033[1;1H";			// clear terminal
	root->print("");

	while (cin >> val){
		if ( val == -1 ) break; // use -1 to start deleting
		root->insert(val);
		cout << "\033[2J\033[1;1H";		// clear terminal
		root->print("");
	}

	cout << "Insertion stopped. Enter values to be removed from the tree. Enter -1 to stop removal." << endl;

	while (cin >> val){
		if ( val == -1 ) break; // break and destroy everything
		root->remove(val);
		cout << "\033[2J\033[1;1H";		// clear terminal
		root->print("");
	}

	// use -2147483647 is smallest int value
	cout << "The second largest element is " << root->secondLargest(-2147483647) << endl;

	int i, j;
	cout << "Enter a value for i: ";
	cin >> i;
	cout << "Enter a value for j: ";
	cin >> j;
	cout << "The distance between " << i << " and " << j << " is " << root->findDistance(i, j) << endl;

	cout << "Enter a value i. The closest value to i in the tree will be returned." << endl;
	cin >> i;
	cout << "The closest value to " << i << " is " << root->findClosest(i, 2147483647) << endl;

	root->deleteAll();
	return 0;
}
