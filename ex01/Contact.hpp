#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;


public:
	Contact(void);
	~Contact(void);
	
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickName(std::string nickName);
	void setPhoneNumber(std::string phoneNumber);
	void setDarkestSecret(std::string darkestSecret);
	std::string getFirstName(void) const;

};
#endif