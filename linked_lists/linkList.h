#ifndef LINK_LIST_H
#define LINK_LIST_H

// (Simple) Excpetion type:
class linkListException{
public:
	enum Type { PAST_END } type;
	linkListException(Type type) : type(type) {};
};

template<class T> class linkList {
	
	// lower level list element
	class listElement{
		const T& value;
		listElement* next;

	public:
		listElement(const T& value, ) : value(value), next(NULL) {}

		listElement* 		next() const							{ return next; }
		const T& 				value() const 						{ return value; }
		void 						setNext(listElement* n) 	{ next = n; }
		void 						setValue(T& v) 						{ value = v; }

	} *top, *bottom, *iterator;
	
	unsigned int length;

public:
	linkList() : top(NULL), bottom(NULL), length(0) {}
	~linkList();

	// insert
	void push_front();
	void push_after();							// push after current iterator
	void push_back();

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
