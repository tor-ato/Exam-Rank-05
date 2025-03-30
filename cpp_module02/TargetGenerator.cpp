#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
	for (std::map<std::string, ATarget *>::iterator it = targetBook.begin(); it != targetBook.end(); ++it)
		delete it->second;
	targetBook.clear();
}

void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
		targetBook.insert(std::make_pair(target->getType(), target->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &targetType)
{
	if (targetBook.find(targetType) != targetBook.end())
	{
		delete targetBook[targetType];
		targetBook.erase(targetBook.find(targetType));
	}
}

ATarget* TargetGenerator::createTarget(std::string const &targetType)
{
	ATarget* tmp = NULL;
	if (targetBook.find(targetType) != targetBook.end())
		tmp = targetBook[targetType];
	return (tmp);
}
