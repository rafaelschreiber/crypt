/*
 * Created by Rafael Schreiber raf.schreiber@gmail.com
 * Licensed under the BSD 3-Clause License
 */

#include <iostream>
#include "crypt.h"
#include <string>
#include <fstream>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]) {
    if(argc <= 1){
        cerr << "Please specify a file" << endl;
        return 1;
    }
    string filepath = argv[1];
    string password;
    ifstream file;
    file.open(filepath);
    if(!file.is_open()){
        cerr << "Could not read the file: " << filepath << " Maybe the file doesn't exist?" << endl;
        file.close();
        return 1;
    }
    password = getpass("Password: ");
    string filecontent((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    file.close();
    if(password.length() == 0){
        cout << filecontent;
        return 0;
    }
    cout << xorize(filecontent, password);
    return 0;
}
