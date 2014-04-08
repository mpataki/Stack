#include <iostream>
#include "linkList.h"
#include <cassert>

using namespace std;

int main( int argc, char* argv[] ){
	cout << "BEGIN TESTS" << endl << endl;

	linkList<int> llist;
	
	cout << "- Test llist starts empty" << endl;
	assert(	llist.empty() );
	cout << "- Test llist starts with length == 0" << endl;
	assert(	llist.length() == 0 );

	try {
		cout << "- remove" << endl;
		llist.get();
	} catch( linkListException e ){
		assert( e.type ==linkListException::ACCESSED_EMPTY_LIST );
	}

	try {
		cout << "- get_top throws an exception to being with" << endl;
		llist.get_top();
	} catch( linkListException e ){
		assert( e.type ==linkListException::ACCESSED_EMPTY_LIST );
	}

	try {
		cout << "- get_bottom throws an exception to being with" << endl;
		llist.get_bottom();
	} catch( linkListException e ){
		assert( e.type ==linkListException::ACCESSED_EMPTY_LIST );
	}

	try {
		cout << "- remove_front throws an exception (can't remove from empty list)" << endl;
		llist.remove_front();
	} catch( linkListException e ){
		assert( e.type ==linkListException::REMOVE_FROM_EMPTY_LIST );
	}

	try {
		cout << "- remove throws an exception (can't remove from empty list)" << endl;
		llist.remove();
	} catch( linkListException e ){
		assert( e.type ==linkListException::REMOVE_FROM_EMPTY_LIST );
	}

	try {
		cout << "- remove_after throws an exception (can't remove from empty list)" << endl;
		llist.remove_after();
	} catch( linkListException e ){
		assert( e.type ==linkListException::REMOVE_FROM_EMPTY_LIST );
	}
	
	try {
		cout << "- remove_back throws an exception (can't remove from empty list)" << endl;
		llist.remove_back();
	} catch( linkListException e ){
		assert( e.type ==linkListException::REMOVE_FROM_EMPTY_LIST );
	}

	int v = 1;
	llist.push_front(v);

	cout << "- not empty after push to front" << endl;
	assert(	!llist.empty() );

	cout << "- length is 1 after single insert" << endl;
	assert(	llist.length() == 1 );	

	cout << "- the right value was stored in top" << endl;
	assert(	llist.get_top() == 1 );

	cout << "- the iterator is in the right place" << endl;
	assert(	llist.get() == 1 );	

	cout << "- bottom is set correctly" << endl;
	assert(	llist.get_bottom() == 1 );	

	cout << "- next returns false as there is only 1 value" << endl;
	assert(	!llist.next() );

	cout << endl << "TESTS FINISHED" << endl;
	return 0;	
}
