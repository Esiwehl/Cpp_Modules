#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include "Data.hpp"

class Serializer{
	private:
		Serializer() = default;
		~Serializer() = default;

	public:
		static std::uintptr_t serialize(Data* ptr);
		static Data* deserialize(std::uintptr_t raw);
};

#endif