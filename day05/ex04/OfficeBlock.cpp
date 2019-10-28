#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock()
{
    this->_intern = nullptr;
    this->_signer = nullptr;
    this->_executor = nullptr;
}

OfficeBlock::OfficeBlock(Intern& intern, Bureaucrat& signer, Bureaucrat& executor)
{
    this->_intern = &intern;
    this->_signer = &signer;
    this->_executor = &executor;
}

OfficeBlock::~OfficeBlock()
{
    return;
}

void
OfficeBlock::doBureaucracy(std::string function, std::string target)
{
    Form* form;

    if (!this->_intern)
        throw OfficeBlock::NoInternException();
    if (!this->_signer)
        throw OfficeBlock::NoSignerException();
    if (!this->_executor)
        throw OfficeBlock::NoExecutorException();

    
    form = this->_intern->makeForm(function, target);
    if (form != nullptr)
    {
        try
        {
            this->_signer->signForm(*form);
        }
        catch (std::exception& e)
        {
            throw OfficeBlock::SignLowGradeException();
        }
        
        try
        {
            this->_executor->executeForm(*form);
        }
        catch(const std::exception& e)
        {
            throw OfficeBlock::ExecLowGradeException();
        }

        if (form != nullptr)
            delete form;
    }
}

void
OfficeBlock::setIntern(Intern &intern)
{
    this->_intern = &intern;
}

void
OfficeBlock::setSigner(Bureaucrat &signer)
{
    this->_signer = &signer;
}

void
OfficeBlock::setExecutor(Bureaucrat &executor)
{
    this->_executor = &executor;
}










OfficeBlock::SignLowGradeException::SignLowGradeException()
{
    return;
}

OfficeBlock::SignLowGradeException::~SignLowGradeException() throw()
{
    return;
}

OfficeBlock::SignLowGradeException::SignLowGradeException(SignLowGradeException const &src)
{
    *this = src;
    return;
}

OfficeBlock::SignLowGradeException&
OfficeBlock::SignLowGradeException::operator=(SignLowGradeException const & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char*
OfficeBlock::SignLowGradeException::what() const throw()
{
    return ("Bureaucrat's grade is too low");
}










OfficeBlock::ExecLowGradeException::ExecLowGradeException()
{
    return;
}

OfficeBlock::ExecLowGradeException::~ExecLowGradeException() throw()
{
    return;
}

OfficeBlock::ExecLowGradeException::ExecLowGradeException(ExecLowGradeException const &src)
{
    *this = src;
    return;
}

OfficeBlock::ExecLowGradeException&
OfficeBlock::ExecLowGradeException::operator=(ExecLowGradeException const & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char*
OfficeBlock::ExecLowGradeException::what() const throw()
{
    return ("Bureaucrat's grade is too low");
}











OfficeBlock::NoInternException::NoInternException()
{
    return;
}

OfficeBlock::NoInternException::~NoInternException() throw()
{
    return;
}

OfficeBlock::NoInternException::NoInternException(NoInternException const &src)
{
    *this = src;
    return;
}

OfficeBlock::NoInternException&
OfficeBlock::NoInternException::operator=(NoInternException const & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char*
OfficeBlock::NoInternException::what() const throw()
{
    return ("No intern");
}












OfficeBlock::NoSignerException::NoSignerException()
{
    return;
}

OfficeBlock::NoSignerException::~NoSignerException() throw()
{
    return;
}

OfficeBlock::NoSignerException::NoSignerException(NoSignerException const &src)
{
    *this = src;
    return;
}

OfficeBlock::NoSignerException&
OfficeBlock::NoSignerException::operator=(NoSignerException const & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char*
OfficeBlock::NoSignerException::what() const throw()
{
    return ("No signer");
}








OfficeBlock::NoExecutorException::NoExecutorException()
{
    return;
}

OfficeBlock::NoExecutorException::~NoExecutorException() throw()
{
    return;
}

OfficeBlock::NoExecutorException::NoExecutorException(NoExecutorException const &src)
{
    *this = src;
    return;
}

OfficeBlock::NoExecutorException&
OfficeBlock::NoExecutorException::operator=(NoExecutorException const & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char*
OfficeBlock::NoExecutorException::what() const throw()
{
    return ("No executor");
}