/*
/
/ Gestion de nos exceptions
/
*/

#include <iostream> 
#include <sstream> 
#include <exception> 


class appli_exception : public std::exception
{
public:
	appli_exception(const char * Msg)
	{
		std::ostringstream oss;
		oss << "Erreur dessin " << " : " << Msg;

		this->msg = oss.str();
	}

	virtual ~appli_exception() throw()
	{

	}

	virtual const char * what() const throw()
	{
		return this->msg.c_str();
	}

private:
	std::string msg;
};