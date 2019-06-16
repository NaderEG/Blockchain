#include <ctime>
#include <iostream>
#include <string>
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
      string calculatedhash = sha256(previousHash + timeStamp_string + data);
      return calculatedhash;
    }
  //private variables
  private:
    string data;
    long timeStamp;
};
