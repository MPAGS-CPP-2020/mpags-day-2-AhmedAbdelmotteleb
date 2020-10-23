//guards
//this ensures that the header is not included more than once
#ifndef MPAGSCIPHER_PROCESSCOMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMANDLINE_HPP
#include <vector>
#include <string>

bool processCommandLine(
  const std::vector <std::string>& cmdLineArgs,
  bool& helpRequested,
  bool& versionRequested,
  std::string& inputFile,
  std::string& outputFile);
  

#endif // MPAGSCIPHER_PROCESSCOMANDLINE_HPP