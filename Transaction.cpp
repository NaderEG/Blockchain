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
    String signature;

    vector<TransactionInput*> inputs;
    vector<TransactionOutput*> outputs;

    Transaction(string from, string to, float val, vector<TransactionInput> in) {
      sender = from;
      reciepient = to;
      value = val;
      inputs = in;

    }

  private:
    static int sequence = 0;

    String calculateHash() {
      sequence++;
      return sha256(sender+reciepient+std::to_string(value)+std::to_string(sequence));
    }

}