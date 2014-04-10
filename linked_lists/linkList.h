#ifndef LINK_LIST_H
#define LINK_LIST_H

// (Simple) Excpetion type:
class linkListException {
public:
  enum Type { PAST_END, NO_MEMORY, REMOVE_FROM_EMPTY_LIST, ACCESSED_EMPTY_LIST } type;
  linkListException(Type type) : type(type) {};
};

template<class T> class linkList {
  
  // lower level list element
  class listElement{
    T value;
    listElement* next;

  public:
    listElement( T& value ) : value(value), next(NULL) {}

    listElement*    get_next()                { return next; }
    T&              get_value()               { return value; }
    void            set_next(listElement* n)  { next = n; }
    void            set_value(T v)            { value = v; }

  } *top, *bottom, *iterator;
  
  unsigned int m_length;

public:
  linkList() : top(NULL), bottom(NULL), iterator(NULL), m_length(0) {}
  ~linkList() {}

  
  /**************************** insert ****************************/
  void push_front(T& value) {
    listElement* new_elm = new listElement( value );
    if ( !new_elm ) throw linkListException( linkListException::NO_MEMORY );
    
    if ( !top ) { // first insert
      top = new_elm;
      iterator = new_elm;
      bottom = new_elm;
    } else {
      new_elm->set_next( top->get_next() );
      top->set_next( new_elm );
    }

    m_length++;
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

    m_length++;
  }

  void push_back(T& value) {
    listElement* new_elm = new listElement( value );
    if ( !new_elm ) throw linkListException( linkListException::NO_MEMORY );

    if ( !bottom ) {  // first insert
      top = new_elm;
      iterator = new_elm;
      bottom = new_elm;
    } else {
      bottom->set_next( new_elm );
      bottom = new_elm;
    }

    m_length++;
  }

  
  /**************************** remove ****************************/
  void remove_front() {
    if ( !top ) throw linkListException(linkListException::REMOVE_FROM_EMPTY_LIST);

    listElement* to_delete = top;
    top = top->get_next();
    if ( !top ) {
      iterator = NULL;
      bottom = NULL;
    } else if ( to_delete == iterator ) iterator = top;
    delete to_delete;
    m_length--;
  }

  // TO DO
  // need a doubly linked list to do this properly ( currently linear time )
  // if iterator is on the bottom, set it to the new bottom
  void remove_back() {
    if ( !bottom ) throw linkListException(linkListException::REMOVE_FROM_EMPTY_LIST);

    listElement* to_delete = bottom;

    listElement* elm = top;
    while (elm->get_next() != to_delete) elm = elm->get_next();
    bottom = elm;
    bottom->set_next(NULL);
    if ( iterator == to_delete ) iterator = elm;
    if ( top == to_delete ) top = NULL;

    delete to_delete;
    m_length--;
  }

  // remove current iterator positon
  void remove() {
    if ( !iterator ) throw linkListException(linkListException::REMOVE_FROM_EMPTY_LIST);
    if ( iterator == bottom ) return remove_back();
    if ( iterator == top ) return remove_front();

    listElement* to_delete = iterator;
    iterator = iterator->get_next();
    delete to_delete;
    m_length--;   
  }

  // remove after current iterator
  void remove_after() {
    if ( !iterator ) throw linkListException(linkListException::REMOVE_FROM_EMPTY_LIST);
    if ( !iterator->get_next() ) throw linkListException(linkListException::PAST_END);
    
    listElement* to_delete = iterator->get_next();
    iterator->set_next( to_delete->get_next() );

    if ( to_delete == bottom ) {
      bottom = iterator;
      bottom->set_next(NULL);
    }

    delete to_delete;
    
    m_length--;
  }

  // go to the [top, bottom, next] element
  void goto_front() { iterator = top; }
  void goto_back() { iterator = bottom; }
  bool next(){                    // true while not past the end of the list ( useful for loops )
    return iterator = iterator->get_next();
  }

  
  /**************************** access ****************************/

  // get value at iterator position
  const T& get() {
    if ( !m_length ) throw linkListException(linkListException::ACCESSED_EMPTY_LIST);
    return iterator->get_value(); 
  }

  // does not change iterator position
  const T& front() {
    if ( !m_length ) throw linkListException(linkListException::ACCESSED_EMPTY_LIST);
    return top->get_value();
  }    
  
  // does not change iterator position
  const T& back() {
    if ( !m_length ) throw linkListException(linkListException::ACCESSED_EMPTY_LIST);
    return bottom->get_value();
  } 

  unsigned int  length()  { return m_length; }
  bool          empty()   { return !m_length; }
};

#endif // LINK_LIST_H
