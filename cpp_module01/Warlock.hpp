#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <map>
#include "ATarget.hpp"
#include <iostream>

class Warlock {
private:
	std::string name;
	std::string title;
	std::map<std::string, ASpell *> spellBook;
 
public:
	Warlock(const std::string &name, const std::string &title);
	~Warlock();

	const std::string &getName() const;
	const std::string &getTitle() const;
	void setTitle(const std::string &title);

	void introduce() const;
	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spellname);
	void launchSpell(const std::string &apellname, const ATarget &target);
};

#endif
