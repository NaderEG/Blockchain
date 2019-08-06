#include <vector>
#include "sha256.h"
#include "TransactionInput.cpp"
#include "TransactionOutput.cpp"
using namespace std;
using std::string;
using std::vector;

class Transaction {
  public:
    string transactionId;
    string sender;
    string reciepient;
    float value;
    string signature;
    static int sequence;
    vector<TransactionInput*> inputs;
    vector<TransactionOutput*> outputs;

    Transaction(string from, string to, float val, vector<TransactionInput*> in) {
      sender = from;
      reciepient = to;
      value = val;
      inputs = in;

    }
    string calculateHash() {
      sequence++;
      return sha256(sender+reciepient+std::to_string(value)+std::to_string(sequence));
    }

    void generateSignature(string privateKey) {
      signature = sha256(privateKey+sender+reciepient+std::to_string(value));
    }

    bool verifySignature() {
      return signature == sha256(sha256(sender+"secret code")+sender+reciepient+std::to_string(value));
    }

    bool processTransaction() {
      if(verifySignature()==false) {
        cout<<"Transaction Signature failed to verify";
      }
      
    }



};
int Transaction::sequence = 0;
