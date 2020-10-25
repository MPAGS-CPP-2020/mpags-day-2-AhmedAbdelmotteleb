//==============================LIBRARIES==============================
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
//==============================Header Files
#include "MPAGSCipher/TransformChar.hpp"
#include "MPAGSCipher/ProcessCommandLine.hpp"
#include "MPAGSCipher/RunCaesarCipher.hpp"


//================================================================
//==============================MAIN==============================
//================================================================
// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Add a typedef that assigns another name for the given type for clarity
  //typedef std::vector<std::string>::size_type size_type;
  //const size_type nCmdLineArgs {cmdLineArgs.size()};
  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  bool encrypt {false};
  bool decrypt {false};
  size_t key{};
  std::string inputFile {""};
  std::string outputFile {""};

  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  bool processedOK{processCommandLine(cmdLineArgs,helpRequested,versionRequested, encrypt, decrypt, key, inputFile,outputFile)};
  if(!processedOK){ return 1; } 


//==============================input file
//std::string input{"input_file.txt"};
std::ifstream in_file{inputFile};
bool ok_to_read = in_file.good();
if (!ok_to_read){return 1;}
//==============================output file
//std::string output{"output_file.txt"};
std::ofstream out_file{outputFile};
bool ok_to_write = out_file.good();
if (!ok_to_write){return 1;}


  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n";
      out_file << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    out_file << "0.1.0" << std::endl;
    return 0;
  }


  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  if (!inputFile.empty()) {
    std::cout << "[warning] input from file ('"
              << inputFile
              << "') not implemented yet, using stdin\n";
  }

  // Loop over each character from user input
  // (until Return then CTRL-D (EOF) pressed)
  while(in_file>>inputChar) //std::cin >> inputChar
  {
    inputText+=transformChar(inputChar);
  }

//encryption and decryption
 if (encrypt){
    out_file << inputText<< " encrypted to " <<runCaesarCipher(inputText,key,encrypt) << " with key " << key;
  }


if (decrypt){
  encrypt=false;
  out_file << inputText<< " decrypted to " <<runCaesarCipher(inputText,key,encrypt) << " with key " << key;
  }



  // Output the transliterated text
  // Warn that output file option not yet implemented
  if (!outputFile.empty()) {
    std::cout  << "[warning] output to file ('"
              << outputFile
              << "') not implemented yet, using stdout\n";
  }

  //std::cout 
  out_file<< inputText << std::endl;

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}

//END-----------------------------------------------