/*
 * Created by Rafael Schreiber raf.schreiber@gmail.com
 * Licensed under the BSD 3-Clause License
 */

#include <cstdio>
#include <string>
#include "crypt.h"

using namespace std;

string xorize(string data, string key) {
    string xorizedString;
    unsigned long keyLen = key.size();
    for(int i = 0; i < data.length(); i++){
        xorizedString += data[i] ^ key[i % keyLen];
    }
    return xorizedString;
}
