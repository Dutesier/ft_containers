#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "random_access_iterator.hpp"

namespace ft {

	template<
		class T,
		class Allocator = std::allocator<T>
		>
	class vector {
	public:
		/* Member types */
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef random_access_iterator<value_type> iterator;
		typedef random_access_iterator<const value_type> const_iterator;
		// typedef std::reverse_iterator<iterator> reverse_iterator;
		// typedef std::reverse_iterator<const_iterator> const_reverse_iterator; 

		/****************/

		vector():
			data(new T[2]),
			begin_ptr(data),
			end_ptr(data + 1){

		};
		vector(const vector& orig);
		vector &operator=(const vector& orig);
		virtual ~vector(){
			delete[] data;
		};

		/* Iterator Functions */
		// For testing only
		iterator begin() {
			return (begin_ptr);
		}

		iterator end() {
			return (end_ptr);
		}
		/**********************/

		/* Capacity */

		/************/

		/* Element Access */
		/******************/
		/* Modifiers */
		/*************/

		/* Allocator */
		/*************/


	private:
		T*		data;
		pointer	begin_ptr;
		pointer end_ptr;

	protected:
	};

}

#endif