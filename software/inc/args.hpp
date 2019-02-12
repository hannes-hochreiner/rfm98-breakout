#ifndef __ARGS_HPP__
#define __ARGS_HPP__

#include <array>
#include <exception>
#include <string>

class args
{
private:
  int _argc;
  char const ** _argv;
public:
  args(int argc, char const *argv[]);
  ~args();
  std::array<uint8_t, 16> get_key();
};

#endif
