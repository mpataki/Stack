#ifndef LINK_LIST_H
#define LINK_LIST_H

template<class T> class linkList {
	
	class listElement{
		const T& value;
		listElement* next;

	public:
		listElement(const T& value, ) : value(value), next(NULL) {}

		listElement* next() const{

		}

		const T& value() const {

		}

		void setNext() {

		}

		void setValue(T val) {

		}

	} *top, *bottom, *iterator;
	
	unsigned int length;

	// Excpetion types:
	/* TO DO */

public:
	linkList() : top(NULL), bottom(NULL), length(0) {}
	~linkList();

	// insert
	void push_front();
	void push_after();
	void push_back();

	// remove
	void remove_front();
	void remove_after();
	void remove_back();

	// lookup
	const T& find(const T& value);
	const T& find(unsigned int index);

	// go to the [first, next, last] element
	void first();
	void next();
	void last();

	// access
	const listElement& getElement();

	unsigned int length() { return length }
};

#endif // LINK_LIST_H
