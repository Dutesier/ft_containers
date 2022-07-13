#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {

    template <class T>
    class random_access_iterator {
    public:

    /*-------------------- Member Types -------------------------*/
        typedef T value_type;
        typedef value_type& reference;
        typedef value_type *pointer;
        typedef value_type& const_reference;
        typedef value_type *const_pointer;
        typedef std::ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
    /*-----------------------------------------------------------*/


    /* Is default-constructible, copy-constructible, copy-assignable and destructible
       Can be compared for equivalence using the equality/inequality operators 
       Can be dereferenced as an rvalue
       Can be dereferenced as an lvalue
       Can be incremented 
       Can be decremented 
       Supports the arithmetic operators + and - between an iterator and an integer value,
       or subtracting an iterator from another.
       Can be compared with inequality relational operators (<, >, <= and >=).
       Supports compound assignment operations += and -=
       Supports the offset dereference operator ([])*/

       
    /*-------------------- Constructors -------------------------*/
    random_access_iterator():ptr(0){}
    random_access_iterator(pointer orig):ptr(orig){}
    random_access_iterator(const random_access_iterator& orig): ptr(orig.ptr){}

    /*-----------------------------------------------------------*/

    /*-------------------- Destructor----------------------------*/
    ~random_access_iterator(){}
    /*-----------------------------------------------------------*/


    /*------------------- Member Functions ----------------------*/
    
    // Assignment operator
    random_access_iterator& operator=(const random_access_iterator& orig) {
        ptr = orig.ptr;
        return (*this);
    }

    // Equality operator
    bool operator==(const random_access_iterator& right_hand_side) const {
        return (ptr == right_hand_side.ptr);
    }

    // Innequality operator
    bool operator!=(const random_access_iterator& right_hand_side) const {
        return (ptr != right_hand_side.ptr);
    }

    // Dereference operator
    reference operator*() const {
        return (*ptr);
    }

    // 
    pointer operator->() const {
        return (&(operator*()));
    }

    // Offset dereference operator
    reference operator[](difference_type n) const {
        return (ptr[n]);
    }



    // Smaller than operator
    bool operator<(const random_access_iterator& right_hand_side) const {
        return (ptr < right_hand_side.ptr);
    }
    
    // Greater than operator
    bool operator>(const random_access_iterator& right_hand_side) const {
        return (ptr > right_hand_side.ptr);
    }
    
    // Smaller or equal operator
    bool operator<=(const random_access_iterator& right_hand_side) const {
        return (ptr <= right_hand_side.ptr);
    }
    
    // Greater or equal operator
    bool operator>=(const random_access_iterator& right_hand_side) const {
        return (ptr >= right_hand_side.ptr);
    }

    // Post increment operator
    random_access_iterator& operator++(void) {
        ptr++;
        return (*this);
    }

    // Pre increment operator
    random_access_iterator operator++(int) {
        random_access_iterator temp;

        temp.ptr = ptr++;
        return (temp);
    }

    // Post decrement operator
    random_access_iterator& operator--(void) {
        ptr--;
        return (*this);
    }

    // Pre decrement operator
    random_access_iterator operator--(int) {
        random_access_iterator temp;

        temp.ptr = ptr--;
        return (temp);
    }

    // Arithmetic addition operator
    random_access_iterator operator+(difference_type n) {
        return (ptr + n);
    }

    random_access_iterator operator-(difference_type n) {
        return (ptr - n);
    }

    difference_type operator-(const random_access_iterator& orig) {
        return (ptr - orig.ptr);
    }

    // Compound assignment operators
    random_access_iterator& operator+=(difference_type n) {
        ptr += n;
        return (*this);
    }

    random_access_iterator& operator-=(difference_type n) {
        ptr -= n;
        return (*this);
    }

    /*-----------------------------------------------------------*/



    pointer base() const {
        return (ptr);
    }
    private:
        pointer ptr;
    };


}


    /*------------------------ Generic --------------------------*/
    /*-----------------------------------------------------------*/


#endif