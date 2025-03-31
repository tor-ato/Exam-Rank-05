#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <map>

class TargetGenerator {
private:
	std::map<std::string, ATarget *> targetBook;
 
public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget *target);
	void forgetTarget(const std::string &targetType);
	ATarget* createTarget(std::string const &targetType);
};

#endif

