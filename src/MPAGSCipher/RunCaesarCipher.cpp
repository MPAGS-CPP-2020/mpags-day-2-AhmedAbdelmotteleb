#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h> 
#include <cmath>
#include "RunCaesarCipher.hpp"

std::string runCaesarCipher(
  const std::string& inputText,
  const size_t key,
  bool encrypt){

  const std::vector<char> alphabet({ 
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'});

std::string outputText {""};

for(std::string::size_type i = 0; i < inputText.size(); ++i) {
  auto it = std::find(alphabet.begin(), alphabet.end(), inputText[i]);
      if (it != alphabet.end()){
          // Get index of element from iterator
          int index = std::distance(alphabet.begin(), it);
          //std::cout <<"Index of element in vector : "<<index<<std::endl;
          if (encrypt){
            outputText += alphabet[index+key];
            //outputText += alphabet[(index +key-65)%26 +65];
          }
          else{
            outputText += alphabet[index-key];
          }
      }
      else
      {
          std::cout << "Error! Character not found in the English alphabet." << std::endl;
      }
}

/*for(std::string::size_type i = 0; i < inputText.size(); ++i){
    int initial_position = alphabet[inputText[i]];
    std::cout << "initial position: " << initial_position << std::endl; 
    if (encrypt = true){ outputText += alphabet[initial_position + key]; }
    else {outputText += alphabet[initial_position - key];}
  }*/
  return outputText;
  }