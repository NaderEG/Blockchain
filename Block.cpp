//g++ sha256.cpp BlockChain.cpp -o sha256_example && ./sha256_example
#include <ctime>
#include <string>
#include <iostream>
#include "sha256.h"
using namespace std;
using std::string;
using std::cout;
using std::endl;

//Block
class Block {
  public:

    //constructor
    Block(string _data, string _previousHash) {
      data = _data;
      previousHash = _previousHash;
      timeStamp = time(NULL);
      hash = calculateHash();
    }

    //public variables
    string hash;
    string previousHash;

    //public methods
    string calculateHash() {
      std::string timeStamp_string = std::to_string(timeStamp);
      string input = previousHash + timeStamp_string + data;
      string calculatedhash = sha256(input);
      return calculatedhash;
    }

    string toString() {
      std::string timeStamp_string = std::to_string(timeStamp);
      return std::string("{") + "\n\t" + "\"hash\": " +hash+
      "\n\t" + "\"previousHash\": " +previousHash+
      "\n\t" + "\"data\": "+data+
      "\n\t" + "\"timeStamp\": "+timeStamp_string+
      "\n}\n";
    }
  //private variables
  private:
    string data;
    long timeStamp;
};
