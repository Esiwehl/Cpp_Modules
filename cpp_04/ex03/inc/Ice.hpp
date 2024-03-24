#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>

# include "ICharacter.hpp"
# include "AMateria.hpp"


class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		~Ice();

		virtual AMateria* clone() const override;
		virtual void use(ICharacter& target) override;
};



#endif