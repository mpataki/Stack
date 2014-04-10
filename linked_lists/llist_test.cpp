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
		llist.front();
	} catch( linkListException e ){
		assert( e.type ==linkListException::ACCESSED_EMPTY_LIST );
	}

	try {
		cout << "- get_bottom throws an exception to being with" << endl;
		llist.back();
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
	assert(	llist.front() == 1 );

	cout << "- the iterator is in the right place" << endl;
	assert(	llist.get() == 1 );	

	cout << "- bottom is set correctly" << endl;
	assert(	llist.back() == 1 );

	cout << "- next returns false as there is only 1 value" << endl;
	assert(	!llist.next() );

	llist.remove_front();
	cout << "- Test removing the element causes an empty list" << endl;
	assert(	llist.empty() );
		cout << "- Test llist starts empty" << endl;
	assert(	llist.empty() );
	cout << "- Test llist starts with length == 0" << endl;
	assert(	llist.length() == 0 );

	for (int i = 0; i<10; i++) llist.push_back(i);

	cout << "- Test llist is now not empty" << endl;
	assert(	!llist.empty() );
	cout << "- Test llist has 10 values, as expected" << endl;
	assert(	llist.length() == 10 );	

	cout << "- Test that we can remove from the front" << endl;
	assert(llist.front() == 0);
	llist.remove_front();
	assert(llist.front() == 1);
	
	cout << "- Test that we can remove from thr back" << endl;
	assert(llist.back() == 9);
	llist.remove_back();
	assert(llist.back() == 8);
	
	cout << "- Test we now have 8 elements after removing 2" << endl;
	assert(llist.length() == 8);

	cout << "- Test we can iterate with next()" << endl;
	for (int i=0; i<4; i++) llist.next();
	assert(llist.get() == 5);
	
	cout << "- Test that we can remove form the middle (remove)" << endl;
	llist.remove();
	assert(llist.length() == 7);
	assert(llist.get() == 6);

	cout << "- Test that we can remove form the middle (remove after)" << endl;
	llist.remove_after();
	assert(llist.length() == 6);
	assert(llist.get() == 6);

	cout << endl << "TESTS FINISHED" << endl;
	return 0;	
}
