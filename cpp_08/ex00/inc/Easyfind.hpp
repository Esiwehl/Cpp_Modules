#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm> // std::find
# include <exception> // std::exception

template <typename T>
typename T::iterator easyfind(T& container, int value){
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()){
		throw std::runtime_error("Couldn't find value in container..");
	}
	return it;
}

#endif