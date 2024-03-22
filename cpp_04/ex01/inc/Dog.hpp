#ifndef Dog_HPP
# define Dog_HPP

# include "Brain.hpp"
# include "Animal.hpp"

class Dog : public Animal {
	private:
		Brain *_b;
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		virtual ~Dog();

		void makeSound() const override;
		std::string getName() const;
};

#endif