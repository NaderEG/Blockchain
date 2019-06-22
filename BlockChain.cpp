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

        if(!(currentBlock->hash == currentBlock->calculateHash())) {
          std::cout <<"Current Hashes not equal";
          return false;
        }
        if(!(previousBlock->hash == currentBlock->previousHash)) {
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
  bc->blockchain.push_back(new Block("Hi im the second block", bc->blockchain.at(bc->blockchain.size()-1)->hash));
  bc->blockchain.push_back(new Block("Hi im the third block", bc->blockchain.at(bc->blockchain.size()-1)->hash));


  std::cout<< bc->toString();


  return 0;
}
