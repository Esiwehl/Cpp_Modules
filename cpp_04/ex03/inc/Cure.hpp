#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		virtual ~Cure();

		virtual AMateria* clone() const override;
		virtual void use(ICharacter& target) override;
};

#endif