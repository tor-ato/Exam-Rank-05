#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include "ATarget.hpp"
# include <map>

class TargetGenerator
{
	private:
		std::map<std::string, ATarget *> targetBook;

	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *target);
		void forgetTargetType(std::string const &targetType);
		ATarget* createTarget(std::string const &targetType);
};

#endif