#include "stdafx.h"
#include "encryption.h"

#include <string>
#include <cmath>
#include <iostream>

int mod(int, int, int);

std::string encryption::encrypt(std::string toEncrypt, int p, int q)
{
	int n = p * q;
	int phin = (p - 1) * (q - 1);
	int e = 17;
	int d = 0;
	for (int i = 1; i < phin; i++)
	{
		if ((i * e) % phin == 1)
		{
			d = i;
			break;
		}
	}
	int* arr_enc = new int[toEncrypt.length()];

	for (int i = 0; i < toEncrypt.length(); i++)
	{
		arr_enc[i] = mod((int)toEncrypt[i] - 96, e, n);
	}
	std::string encrypted = "";
	for (int i = 0; i < toEncrypt.length(); i++)
	{
		encrypted += std::to_string((arr_enc[i])) + ",";
	}
	encrypted.erase(encrypted.length() - 1, 1);
	delete[] arr_enc;
	return encrypted;
}

std::string encryption::decrypt(std::string toDecrypt, int p, int q)
{
	int n = p * q;
	int phin = (p - 1) * (q - 1);
	int e = 17;
	int d = 0;
	for (int i = 1; i < phin; i++)
	{
		if ((i * e) % phin == 1)
		{
			d = i;
			break;
		}
	}
	int numChars = 0;
	for (int i = 0; i < toDecrypt.length(); i++)
	{
		if (toDecrypt[i] == ',')
			numChars++;
	}

	int* arr_enc = new int[numChars + 1];

	size_t pos1 = toDecrypt.find_first_of(',');
	//std::string sub = "";
	for (int i = 0; i < numChars + 1; i++)
	{
		//sub = toDecrypt.substr(0, pos1);
		arr_enc[i] = std::stoi(toDecrypt.substr(0, pos1));
		toDecrypt = toDecrypt.substr(pos1+ 1, toDecrypt.length() - pos1);
		pos1 = toDecrypt.find_first_of(',');
	}
	std::string decrypted = "";
	for (int i = 0; i < numChars + 1; i++)
	{
		decrypted += (char)(mod(arr_enc[i], d, n) + 96);
	}
	delete[] arr_enc;
	return decrypted;
}

int mod(int base, int exp, int modulus)
{
	int c = 1;
	for (int i = 1; i <= exp; i++)
	{
		c = (c*base) % modulus;
	}
	return c;
}
