#include "Keys.cpp"

class Wallet {
  public:
    string privateKey;
    string publicKey;



  Wallet() {
    generateKeyPair();
  }
  private:
    static int memberNum;
    Keys *keyGen;
    void generateKeyPair() {
      publicKey = keyGen->getPublicKey(memberNum);
      privateKey = keyGen->getPrivateKey(publicKey);
      memberNum++;
    }

};
int Wallet::memberNum = 0;
