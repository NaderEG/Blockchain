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
        return false;
      }

      for(TransactionInput * i: inputs) {
        i->UTXO = BlockChain->blockchain->UTXOs.at(i->transactionOutputId);
      }

      if(getInputsValue() < BlockChain->blockchain->minimumTransaction) {
        cout<<"Transaction Inputs too small"<<getInputsValue();
        return false;
      }

      float leftOver = getInputsValue() - value;
      transactionId = calculateHash();
      outputs.add(new TransactionOutput(this.recipient, value, transactionId));
      outputs.add(new TransactionOutput(this.sender, leftOver, transactionId));

      for(TransactionOutput * o : outputs) {
        BlockChain->blockchain->UTXOs[o.id] = o;
      }

      for(TransactionInput * i: inputs) {
        if(i->UTXO == NULL) continue;
        BlockChain->blockchain->UTXOs.remove(i->UTXO->id);
      }
      return true;
    }

    float getInputsValue() {
      float total = 0;
      for(Transaction * i : inputs) {
        if(i->UTXO == null) continue;
        total += i->UTXO->value;
      }
      return total;
    }

    float getOutputsValue() {
      float total = 0;
      for(Transaction o : outputs) {
        total += o->value;
      }
      return total;
    }



};
int Transaction::sequence = 0;
