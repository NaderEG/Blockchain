#include <vector>
#include "sha256.h"
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

    vector<TransactionInput*> inputs;
    vector<TransactionOutput*> outputs;

    Transaction(string from, string to, float val, vector<TransactionInput> in) {
      sender = from;
      reciepient = to;
      value = val;
      inputs = in;

    }

  private:
    string calculateHash() {
      sequence++;
      return sha256(sender+reciepient+std::to_string(value)+std::to_string(sequence));
    }

    void generateSignature(string privateKey) {
      signature = sha256(privateKey+sender+reciepient+std::to_string(value));
    }

    boolean verifySignature() {
      return signature == sha256(sha256(sender+"secret code")+sender+reciepient+std::tostring(value));
    }

}
