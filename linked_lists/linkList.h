#ifndef LINK_LIST_H
#define LINK_LIST_H

// (Simple) Excpetion type:
class linkListException{
public:
	enum Type { PAST_END, NO_MEMORY, REMOVE_FROM_EMPTY_LIST } type;
	linkListException(Type type) : type(type) {};
};

template<class T> class linkList {
	
	// lower level list element
	class listElement{
		T value;
		listElement* next;

	public:
		listElement( T& value ) : value(value), next(NULL) {}

		listElement* 		get_next() const							{ return next; }
		const T 				get_value() const 						{ return value; }
		void 						set_next(listElement* n) 	{ next = n; }
		void 						set_value(T v) 						{ value = v; }

	} *top, *bottom, *iterator;
	
	unsigned int length;

public:
	linkList() : top(NULL), bottom(NULL), iterator(NULL), length(0) {}
	~linkList() {}

	// insert
	void push_front(T& value) {
		listElement* new_elm = new listElement( value );
		if ( !new_elm ) throw linkListException( linkListException::NO_MEMORY );
		
		if ( !top ) {	// first insert
			top = new_elm;
			iterator = new_elm;
			bottom = new_elm;
		} else {
			new_elm->set_next( top->get_next() );
			top->set_next( new_elm );
		}

		length++;
	}

	// push after current iterator
	void push_after(T& value) {
		listElement* new_elm = new listElement( value );
		if ( !new_elm ) throw linkListException( linkListException::NO_MEMORY );

		if ( !iterator ) { // first insert
			top = new_elm;
			iterator = new_elm;
			bottom = new_elm;
		} else {
			new_elm->set_next( iterator->get_next() );
			iterator->set_next( new_elm );
		}

		length++;
	}

	void push_back(T& value) {
		listElement* new_elm = new listElement( value );
		if ( !new_elm ) throw linkListException( linkListException::NO_MEMORY );

		if ( !bottom ) {	// first insert
			top = new_elm;
			iterator = new_elm;
			bottom = new_elm;
		} else {
			bottom->set_next( new_elm );
			bottom = new_elm;
		}

		length++;
	}

	// remove
	void remove_front() {
		if ( !top ) throw linkListException(linkListException::REMOVE_FROM_EMPTY_LIST);

		listElement* to_delete = top;
		top = top->get_next();
		if ( !top ) {
			iterator = NULL;
			bottom = NULL;
		}
		delete to_delete;
		length--;
	}

	// remove current iterator positon
	void remove() {
		if ( !iterator ) throw linkListException(linkListException::REMOVE_FROM_EMPTY_LIST);

		listElement* to_delete = iterator;
		iterator = iterator->get_next();
		if ( !iterator ) {
			top = NULL;
			bottom = NULL;
		}
		delete to_delete;
		length--;		
	}

	// remove after current iterator
	void remove_after() {
		if ( !iterator ) throw linkListException(linkListException::REMOVE_FROM_EMPTY_LIST);
		if ( !iterator->get_next() ) throw linkListException(linkListException::PAST_END);
		
		listElement* to_delete = iterator->get_next();
		iterator->set_next( to_delete->get_next() );

		if ( to_delete == bottom ) bottom = iterator;

		delete to_delete;
		
		length--;
	}

	// TO DO
	// need a doubly linked list to do this properly
	void remove_back() {
		if ( !bottom ) throw linkListException(linkListException::REMOVE_FROM_EMPTY_LIST);

		listElement* to_delete = bottom;

		if ( iterator == to_delete ) iterator = NULL;
		bottom = NULL;
		length--;
	}

	// go to the [top, bottom, next] element
	void top() { iterator = top; }
	void bottom() { iterator = bottom }
	bool next(){ 										// true while not past the end of the list ( useful for loops )
		if ( !iterator->get_next() ) return false;
		iterator = iterator->get_next();
		return true;
	}

	// access
	const listElement& get(){ return iterator->get_value(); }				// get value at iterator position
	const listElement& get_top(){ return top->get_value(); }				// does not change iterator position
	const listElement& get_bottom(){ return bottom->get_value(); }	// does not change iterator position
	unsigned int length() { return length }
};

#endif // LINK_LIST_H
