#include <ctime>
#include <iostream>
using namespace std;

//Block
class Block {
  // Access specifier
  public:

  //instance variables
  public String hash;
  public String previousHash;
  private String data;
  private long timeStamp;

  Block(String _data, String _previousHash) {
    data = _data;
    previousHash = _previousHash;
    timeStamp = time(NULL);
  }

}
