#include "sha256.h"
#include <unordered_map>
using namespace std;
using std::string;

class Keys {
  private:
    unordered_map<string, string> keyPairs;

    void setMap() {
      for(int i = 1; i<10000; i++) {
        string privateKey = std::to_string(i);
        string publicKey = sha256(std::to_string(i));
        keyPairs[privateKey] = publicKey;
      }
    }

  public:
    Keys() {
      setMap();
    }
    string getPrivateKey(int client) {
      return std::to_string(client);
    }
    string getPublicKey(string priv) {
      return keyPairs.at(priv);
    }
}
