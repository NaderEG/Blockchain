#include <string>
#include "TransactionOutput.cpp"
using namespace std;
using std::string;

class TransactionInput {
  public:
    string transactionOutputId;
    TransactionOutput * UTXO;

    TransactionInput(string _transactionOutputId) {
      transactionOutputId = _transactionOutputId;
    }

};
