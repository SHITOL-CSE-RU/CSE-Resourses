///Nahid Hasan Raju
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string TextToCipher(string text, int width)
{
	string encrypt;

	int col = 0;

	int i = col;

	while( col < width )
	{
		encrypt += text[i];

		i += width;

		if (i >= text.length())
		{
			i = ++col;
		}
	}

	return encrypt;
}


string CipherToText(string encrypt, int width)
{
	string dercypt(encrypt.length(), '$');

	int row = 0;
	int i,j;

	for(i = 0, j = row; i < encrypt.length(); i++)
	{
		dercypt[j] = encrypt[i];

		j += width;

		if (j >= encrypt.length())
		{
			j = ++row;
		}
	}

	return dercypt;
}


int main()
{
    ifstream inp;
    ofstream encrypt, decrypt;

    inp.open ("text.txt");
    encrypt.open ("encrypt.txt");
    decrypt.open ("decrypt.txt");

	string text, ts;

	while(getline(inp,ts))text+=ts;

	inp.close();

	//text = "DEPARTMENT OF COMPUTER SCIENCE AND TECHNOLOGY UNIVERSITY OF RAJSHAHI BANGLADESH";

	cout<<"Input text: "<< text << endl;

	string encrypted = TextToCipher(text, 5);

	cout<<"After Encryption: "<< encrypted << endl;
	encrypt << encrypted<<endl;
    encrypt.close();

	string decrypted = CipherToText(encrypted, 5);

	cout<< "After Decryption: "<< decrypted <<endl;
	decrypt << decrypted<<endl;
    decrypt.close();

	return 0;
}
