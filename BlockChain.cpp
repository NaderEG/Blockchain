#include "Block.cpp"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class BlockChain {



};
int main() {
  Block * genesisBlock = new Block("Hi im the first block", "0");
  cout << "Hash for block 1:" << genesisBlock->hash << endl;
  return 0;
}
