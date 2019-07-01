#include "Block.cpp"
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::endl;
using std::vector;


class BlockChain {
  public:
    int difficulty = 5; //can be changed to whatever, 5 is good for testing
    BlockChain() {
      blockchain = {};
    }

    string toString() {
      string toPrint = "";
      for(Block * b : blockchain) {
         toPrint = toPrint + b->toString();
      }
      return toPrint;
    }

    bool isChainValid() {
      Block * currentBlock;
      Block * previousBlock;

      for(int i = 1; i<blockchain.size(); i++) {
        currentBlock = blockchain.at(i);
        previousBlock = blockchain.at(i-1);

        if(!(currentBlock->hash==currentBlock->calculateHash())) {
          std::cout <<"Current Hashes not equal";
          return false;
        }
        if(!(previousBlock->hash==currentBlock->previousHash)) {
          std::cout <<"Previous Hash not equal";
          return false;
        }
      }
      return true;
    }

    vector<Block*> blockchain;

};
int main() {

  BlockChain * bc = new BlockChain();
  bc->blockchain.push_back(new Block("Hi im the first block", "0"));
  std::cout << "Trying to mine block 1...\n";
  bc->blockchain.at(0)->mineBlock(bc->difficulty);

  bc->blockchain.push_back(new Block("Hi im the second block", bc->blockchain.at(bc->blockchain.size()-1)->hash));
  std::cout << "Trying to mine block 2...\n";
  bc->blockchain.at(1)->mineBlock(bc->difficulty);

  bc->blockchain.push_back(new Block("Hi im the third block", bc->blockchain.at(bc->blockchain.size()-1)->hash));
  std::cout << "Trying to mine block 3...\n";
  bc->blockchain.at(2)->mineBlock(bc->difficulty);

  std::cout << "\nBlockChain is valid:" << bc->isChainValid() <<"\n";

  std::cout<< bc->toString();


  return 0;
}
