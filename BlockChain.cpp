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

  Block * secondBlock = new Block("Hi im the first block", genesisBlock->hash);
  cout << "Hash for block 2:" << secondBlock->hash << endl;

  Block * thirdBlock = new Block("Hi im the first block", secondBlock->hash);
  cout << "Hash for block 1:" << thirdBlock->hash << endl;
  return 0;
}
