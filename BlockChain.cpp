#include "Block.cpp"
#include "Wallet.cpp"
#include "Transaction.cpp"
#include "TransactionOutput.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::cout;
using std::endl;
using std::vector;


class BlockChain {
  public:

    vector<Block*> blockchain;
    int difficulty = 5; //can be changed to whatever, 5 is good for testing
    unordered_map<string, TransactionOutput> UTXOs;
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
};
int main() {
  Wallet * walletA = new Wallet();
  Wallet * walletB = new Wallet();
  vector<TransactionInput*> in = {};
  cout << "Private Key: " << walletA->privateKey <<"\n";
  cout << "Public Key: " << walletA->publicKey <<"\n";
  cout << "Private Key: " << walletB->privateKey <<"\n";
  cout << "Public Key: " << walletB->publicKey <<"\n";
  Transaction * t = new Transaction(walletA->publicKey, walletB->publicKey, 5, in);
  t->generateSignature(walletA->privateKey);
  cout<< t->verifySignature() <<"\n";

  return 0;
}
