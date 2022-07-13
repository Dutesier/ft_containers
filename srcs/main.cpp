#include <iostream>
#include <string>
#include <deque>
#include <typeinfo>

#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	// #include <map.hpp>
	// #include <stack.hpp>
	#include <vector.hpp>
	#include <vector>
#endif

#include <stdlib.h>

template <typename T>
void test_member_types(T x) {
	std::cout << "Testing: " << x << std::endl;
	ft::vector<T> my_vector();

	typename ft::vector<T>::value_type vt;
	typename ft::vector<T>::allocator_type at;
	typename ft::vector<T>::size_type st;
	typename ft::vector<T>::difference_type dt;
	typename ft::vector<T>::reference r = vt;
	typename ft::vector<T>::const_reference cr = vt;
	typename ft::vector<T>::pointer ptr = &r;
	typename ft::vector<T>::const_pointer cptr = &cr;
	// typename ft::vector<T>::iterator iter;
	// typename ft::vector<T>::const_iterator citer;
	// typename ft::vector<T>::reverse_iterator riter;
	// typename ft::vector<T>::const_reverse_iterator criter;

	std::cout << "Value Type: " << typeid(vt).name() << std::endl;
	std::cout << "Allocator Type: " << typeid(at).name() << std::endl;
	std::cout << "Syze Type: " << typeid(st).name() << std::endl;
	std::cout << "Difference Type: " << typeid(dt).name() << std::endl;
	std::cout << "Reference: "<< r << std::endl;
	std::cout << "Const Reference: " << cr << std::endl;
	std::cout << "Pointer: " << ptr << std::endl;
	std::cout << "Const Pointer: " << cptr << std::endl;
	// std::cout << "Iterator: " << iter << std::endl;
	// std::cout << "Const Iterator: " << citer << std::endl;
	// std::cout << "Reverse Iterator: " << riter << std::endl;
	// std::cout << "Const Reverse Iterator: " << criter << std::endl;
	static_cast<void>(x);
	std::cout << std::endl;

}

#include <vector>
void test_rai(){
	std::cout << "Testing Random Access Iterator" << std::endl;

	// Setup
	ft::vector<int> v;

	// Test - Using my RAI as an iterator for ft::vector
	ft::vector<int>::iterator it = v.begin();
	std::cout << "Iterator points to: " << it.base() << std::endl;
	*it = 2;
	for (; it != v.end(); it++) {
		std::cout << *it << std::endl;
	}
	ft::vector<int>::iterator r = v.begin();
	std::cout << "Iterator points to: " << r.base() << std::endl;
	std::cout << r[0] << std::endl;
	
	it = v.begin();
	std::cout << "Iterator points to: " << it.base() << std::endl;
	std::cout << it[0] << std::endl;
}

int main(void) {
	int i = 42;
	float f = 42.2;
	char c = 42;
	test_member_types(i);
	test_member_types(f);
	test_member_types(c);
	test_rai();
}

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
//	}
