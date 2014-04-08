#ifndef LINK_LIST_H
#define LINK_LIST_H

// (Simple) Excpetion type:
class linkListException {
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

    listElement*    get_next() const              { return next; }
    const T         get_value() const             { return value; }
    void            set_next(listElement* n)  { next = n; }
    void            set_value(T v)            { value = v; }

  } *m_top, *m_bottom, *iterator;
  
  unsigned int m_length;

public:
  linkList() : m_top(NULL), m_bottom(NULL), iterator(NULL), m_length(0) {}
  ~linkList() {}

  
  /**************************** insert ****************************/
  void push_front(T& value) {
    listElement* new_elm = new listElement( value );
    if ( !new_elm ) throw linkListException( linkListException::NO_MEMORY );
    
    if ( !m_top ) { // first insert
      m_top = new_elm;
      iterator = new_elm;
      m_bottom = new_elm;
    } else {
      new_elm->set_next( m_top->get_next() );
      m_top->set_next( new_elm );
    }

    m_length++;
  }

  // push after current iterator
  void push_after(T& value) {
    listElement* new_elm = new listElement( value );
    if ( !new_elm ) throw linkListException( linkListException::NO_MEMORY );

    if ( !iterator ) { // first insert
      m_top = new_elm;
      iterator = new_elm;
      m_bottom = new_elm;
    } else {
      new_elm->set_next( iterator->get_next() );
      iterator->set_next( new_elm );
    }

    m_length++;
  }

  void push_back(T& value) {
    listElement* new_elm = new listElement( value );
    if ( !new_elm ) throw linkListException( linkListException::NO_MEMORY );

    if ( !m_bottom ) {  // first insert
      m_top = new_elm;
      iterator = new_elm;
      m_bottom = new_elm;
    } else {
      m_bottom->set_next( new_elm );
      m_bottom = new_elm;
    }

    m_length++;
  }

  
  /**************************** remove ****************************/
  void remove_front() {
    if ( !m_top ) throw linkListException(linkListException::REMOVE_FROM_EMPTY_LIST);

    listElement* to_delete = m_top;
    m_top = m_top->get_next();
    if ( !m_top ) {
      iterator = NULL;
      m_bottom = NULL;
    }
    delete to_delete;
    m_length--;
  }

  // remove current iterator positon
  void remove() {
    if ( !iterator ) throw linkListException(linkListException::REMOVE_FROM_EMPTY_LIST);

    listElement* to_delete = iterator;
    iterator = iterator->get_next();
    if ( !iterator ) {
      m_top = NULL;
      m_bottom = NULL;
    }
    delete to_delete;
    m_length--;   
  }

  // remove after current iterator
  void remove_after() {
    if ( !iterator ) throw linkListException(linkListException::REMOVE_FROM_EMPTY_LIST);
    if ( !iterator->get_next() ) throw linkListException(linkListException::PAST_END);
    
    listElement* to_delete = iterator->get_next();
    iterator->set_next( to_delete->get_next() );

    if ( to_delete == m_bottom ) m_bottom = iterator;

    delete to_delete;
    
    m_length--;
  }

  // TO DO
  // need a doubly linked list to do this properly ( currently linear time )
  // if iterator is on the bottom, set it to the new bottom
  void remove_back() {
    if ( !m_bottom ) throw linkListException(linkListException::REMOVE_FROM_EMPTY_LIST);

    listElement* to_delete = m_bottom;

    listElement* elm = m_top;
    while (elm->get_next()) elm = elm->get_next();
    m_bottom = elm;
    
    if ( iterator == to_delete ) iterator = elm;
    if (m_top == to_delete ) m_top = NULL;

    delete to_delete;
    m_length--;
  }

  // go to the [top, bottom, next] element
  void top() { iterator = m_top; }
  void bottom() { iterator = m_bottom; }
  bool next(){                    // true while not past the end of the list ( useful for loops )
    if ( !iterator->get_next() ) return false;
    iterator = iterator->get_next();
    return true;
  }

  
  /**************************** access ****************************/
  const listElement& get()        { return iterator->get_value(); }   // get value at iterator position
  const listElement& get_top()    { return m_top->get_value(); }        // does not change iterator position
  const listElement& get_bottom() { return m_bottom->get_value(); }     // does not change iterator position
  unsigned int length()           { return m_length; }
};

#endif // LINK_LIST_H
