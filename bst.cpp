#include <iostream>
#include <string>

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

	Node* findSmallest(){
		if (left == NULL) return this;
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

};

int main( int argc, char* argv[] ){
	int val;
	cin >> val;

	Node* root = new Node(val);
	cout << "\033[2J\033[1;1H";
	root->print("");

	while (cin >> val){
		if ( val == -1 ) break; // use -1 to start deleting
		root->insert(val);
		cout << "\033[2J\033[1;1H";
		root->print("");
	}

	while (cin >> val){
		if ( val == -1 ) break; // break and destroy everything
		root->remove(val);
		cout << "\033[2J\033[1;1H";
		root->print("");
	}

	// use -2147483647 is smallest int value
	cout << "The second largest element is " << root->secondLargest(-2147483647) << endl;

	root->deleteAll();
	return 0;
}
