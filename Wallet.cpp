#include "Keys.cpp"

class Wallet {
  public:
    String privateKey;
    String publicKey;

  private:
    static int memberNum;

  Wallet() {
    generateKeyPair();
  }
  void generateKeyPair() {

 }

}
