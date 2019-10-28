#pragma once
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

class OfficeBlock
{
private:
    Intern*         _intern;
    Bureaucrat*     _signer;
    Bureaucrat*     _executor;

    OfficeBlock(OfficeBlock const &);
    OfficeBlock&    operator=(OfficeBlock const &);
public:
    OfficeBlock();
    OfficeBlock(Intern& intern, Bureaucrat& signer, Bureaucrat& executor);
    ~OfficeBlock();

    void            doBureaucracy(std::string function, std::string target);

    void            setIntern(Intern &intern);
    void            setSigner(Bureaucrat &signer);
    void            setExecutor(Bureaucrat &executor);








    class SignLowGradeException: public std::exception
    {
    public:
        SignLowGradeException();
        SignLowGradeException(SignLowGradeException const &);
        ~SignLowGradeException() throw();

        SignLowGradeException&  operator=(SignLowGradeException const &);

        const char*	            what() const throw();
    };



    class ExecLowGradeException: public std::exception
    {
    public:
        ExecLowGradeException();
        ExecLowGradeException(ExecLowGradeException const &);
        ~ExecLowGradeException() throw();

        ExecLowGradeException&  operator=(ExecLowGradeException const &);

        const char*	            what() const throw();
    };



    class NoInternException: public std::exception
    {
    public:
        NoInternException();
        NoInternException(NoInternException const &);
        ~NoInternException() throw();

        NoInternException&  operator=(NoInternException const &);

        const char*	            what() const throw();
    };



    class NoSignerException: public std::exception
    {
    public:
        NoSignerException();
        NoSignerException(NoSignerException const &);
        ~NoSignerException() throw();

        NoSignerException&  operator=(NoSignerException const &);

        const char*	            what() const throw();
    };



    class NoExecutorException: public std::exception
    {
    public:
        NoExecutorException();
        NoExecutorException(NoExecutorException const &);
        ~NoExecutorException() throw();

        NoExecutorException&  operator=(NoExecutorException const &);

        const char*	            what() const throw();
    };
};