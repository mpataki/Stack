#ifndef LINK_LIST_H
#define LINK_LIST_H

// (Simple) Excpetion type:
class linkListException{
public:
	enum Type { PAST_END, NO_MEMORY } type;
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
	void remove_front();
	void remove_after();						// remove after current iterator
	void remove_back();

	// go to the [first, next, last] element
	void first();
	bool next(); 										// true while not past the end of the list
	void last();

	// access
	const listElement& get();				// get value at iterator position
	const listElement& get_first();	// does not change iterator position
	const listElement& get_last(); 	// does not change iterator position

	unsigned int length() { return length }
};

#endif // LINK_LIST_H
