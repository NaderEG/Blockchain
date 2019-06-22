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
    vector<Block*> blockchain;

};
int main() {
  BlockChain * bc = new BlockChain();
  bc->blockchain.push_back(new Block("Hi im the first block", "0"));
  bc->blockchain.push_back(new Block("Hi im the second block", bc->blockchain.at(bc->blockchain.size()-1)->hash));
  bc->blockchain.push_back(new Block("Hi im the third block block", bc->blockchain.at(bc->blockchain.size()-1)->hash));

  for(Block * b : bc->blockchain) {
    std::cout<< b->hash << "\n";
  }

  return 0;
}
