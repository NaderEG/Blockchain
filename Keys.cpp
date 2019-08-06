#include "sha256.h"
#include <unordered_map>
using namespace std;
using std::string;

class Keys {

  public:

    string getPublicKey(int client) {
      return std::to_string(client);
    }
    string getPrivateKey(string pub) {
      return sha256(pub+"secret code");
    }
};
