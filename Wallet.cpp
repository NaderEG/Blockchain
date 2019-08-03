#include "Keys.cpp"

class Wallet {
  public:
    String privateKey;
    String publicKey;

  private:
    static int memberNum;
    Keys *keyGen;

  Wallet() {
    generateKeyPair();
  }
  void generateKeyPair() {
    privateKey = keyGen->getPrivateKey(memberNum);
    publicKey = keyGen->getPublicKey(privateKey);
    memberNum++;
 }

}
