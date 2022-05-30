#ifndef MAP_HPP
#	define MAP_HPP

namespace ft{

	class map {
	public:
		map();
		map(const map& orig);
		map &operator=(const map& orig);
		virtual ~map();
	private:
		T data[];

	protected:
		
	};
}

#endif