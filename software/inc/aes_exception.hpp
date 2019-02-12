#ifndef __AES_EXCEPTION_HPP__
#define __AES_EXCEPTION_HPP__

#include <exception>
#include <string>

class aes_exception: public std::exception {
private:
  std::string _description;
public:
  aes_exception(std::string description);
  virtual const char* what() const throw();
};

#endif
