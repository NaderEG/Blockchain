#include <string>
#include "sha256.h"
using namespace std;
using std::string;

class TransactionOutput {
  public:
    string id;
    string reciepient;
    float value;
    string parentTransactionId;

    TransactionOutput(string _reciepient, float _value, string _parentTransactionId) {
      reciepient = _reciepient;
      value = _value;
      parentTransactionId = _parentTransactionId;
      id = sha256(reciepient+std::to_string(value), parentTransactionId);
    }

    bool isMine(string publicKey) {
      return publicKey == reciepient;
    }
};
