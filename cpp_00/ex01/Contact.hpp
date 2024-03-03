#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string darkestSecret;
	std::string number;

	public:
	void setDetails(const std::string& fname, const std::string& lname, const std::string& nname,
		const std::string& secret, const std::string& number);
	std::string getFirstname();
	std::string getLastname();
	std::string getNickname();
	std::string getDarkestSecret();
	std::string getNumber();
	void showContact();
};

#endif