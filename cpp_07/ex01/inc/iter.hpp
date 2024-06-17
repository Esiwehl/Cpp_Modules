#ifndef ITER_HPP
# define ITER_HPP

# include <cstdint>

template <typename T, typename F>
void iter(T arr, size_t length, F func){
	for (size_t it = 0; it < length; it++){
		func(arr[it]);
	}
}

#endif