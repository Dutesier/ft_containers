#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {

    template <class T>
    class random_access_iterator {
    public:

    /*-------------------- Member Types -------------------------*/
        typedef iterator_traits<T> iter_traits;
        typedef iter_traits::difference_type difference_type;
        typedef iter_traits::value_type value_type;
        typedef iter_traits::pointer pointer;
        typedef iter_traits::const_pointer const_pointer;
        typedef value_type& reference;
        typedef std::random_access_iterator_tag iterator_category;
    /*-----------------------------------------------------------*/

    /*-------------------- Constructors -------------------------*/
    random_access_iterator():ptr(null){}
    random_access_iterator(pointer orig):ptr(orig){}
    random_access_iterator(const random_access_iterator& orig): ptr(orig.ptr){}

    /*-----------------------------------------------------------*/

    /*-------------------- Destructor----------------------------*/
    ~random_access_iterator(){}
    /*-----------------------------------------------------------*/


    /*------------------- Member Functions ----------------------*/
    
    // Assignment operator
    random_access_iterator& operator=(const random_access_iterator& orig) {
        *this = orig;
        return (*this);
    }

    // Dereference operator
    reference operator*() const {
        return (*ptr);
    }

    // Equality operator
    bool operator==(const random_access_iterator& right_hand_side) const {
        return (ptr == right_hand_side.ptr);
    }

    // Innequality operator
    bool operator!=(const random_access_iterator& right_hand_side) const {
        return (ptr != right_hand_side.ptr)
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
    /*-----------------------------------------------------------*/




    private:
        pointer ptr;
    };
}

    /*------------------------ Generic --------------------------*/
    /*-----------------------------------------------------------*/


#endif