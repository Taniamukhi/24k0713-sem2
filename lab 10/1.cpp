#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    string input;
    cout<< "Enter the string: " << endl;
    getline(cin, input);

    string encrypted = "";
    for(int i=0; i< input.length(); ++i)
    {
        char encryptedchar = input[i] + (i+1);
        encrypted += encryptedchar;
    }

    ofstream outputfile("encrypted.txt");
    outputfile << encrypted;
    outputfile.close();

    cout<< "Text: " << input << endl;
    cout<< "Encrypted text inserted in file." << endl;

    string readencrypted, line;
    ifstream infile("encrypted.txt");
    while(getline(infile, line)){
        readencrypted += line;
    }
    infile.close();

    string decrypted = "";
    for(int i=0; i< readencrypted.length(); ++i)
    {
        char decryptedchar = readencrypted[i] - (i+1);
        decrypted += decryptedchar;
    }

    cout<< "Decryted text: "<< decrypted << endl;
    return 0;
  }
