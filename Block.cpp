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
      std::string nonce_string = std::to_string(nonce);
      string input = previousHash + timeStamp_string +nonce_string+ data;
      string calculatedhash = sha256(input);
      return calculatedhash;
    }

    void mineBlock(int difficulty) {
      //cout<<"test 1";
      std::string target = "";

      for(int i = 0; i<difficulty; i++) {
        target = target+"0";
      }

      while(hash.substr(0, difficulty) != target) {
        nonce++;
        hash = calculateHash();
      }

      std::cout <<"Block Mined: " + hash;
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
    int nonce = 0;
};
