#ifndef JEUEXCEPTION_HPP
#define JEUEXCEPTION_HPP

#include <exception>
#include <string>


class JeuException : public std::runtime_error
{
	public:
		JeuException(const std::string& message): std::runtime_error(message) {}
		virtual ~JeuException() throw() {}
};

#endif
