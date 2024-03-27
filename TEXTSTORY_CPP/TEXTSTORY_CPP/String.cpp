#define _CRT_SECURE_NO_WARNINGS

#include "String.h"
#include <iostream>
#include <ctype.h>
#include <string>
#include <fstream>


using namespace std;


String::String() {
	cout << "+++ string constructor +++" << endl;

	strNew = new char[0];
}

String::~String() {
	cout << "--- string deconstructor ---" << endl;
	delete[] strNew;
}

String::String(const String& other) {
	cout << "+++ string copy +++" << endl;

	size_t size;
	size = strlen(other.strNew);
	strNew = new char[size + 1];
	strcpy(strNew, other.strNew);



}

String::String(const char* str) {
	cout << "+++ string const: " << str << " +++" << endl;

	size_t size;
	size = strlen(str);
	strNew = new char[size + 1];
	strcpy(strNew, str);


}

size_t String::Length() const // writes the length of the string's char array
{
	cout << "\n--- length? operator ---" << endl;
	int length = strlen(strNew);
	cout << "length of " << strNew << " is: " << length << endl;
	return length;
}

char& String::CharacterAt(size_t index)
{
	cout << "\n--- character at? function ---" << endl;
	cout << "letter " << index << " of " << strNew << " is the character: ";
	

	if (strlen(strNew) <= 0) cout << "NO STRING INPUT";

	if (strNew[index - 1] < (strlen(strNew)) || ('\0') || (strNew[index - 1] <= -1)) cout << "INVALID INPUT";
	else cout << strNew[index - 1] << endl;;


	return strNew[index];

}

bool String::EqualTo(const String& other) // equality FUNCTION, different to the operator but does the same thing
{
	cout << "\n--- equal to? function ---" << endl;

	if (strcmp(strNew, other.strNew) == 0) {
		cout << "The strings are equal" << endl;
	}
	else cout << "The strings are not equal" << endl;

	return this;

}

String& String::Append(const String& _str)
{
	cout << "\n--- append? function ---" << endl;
	strcat(strNew, " ");
	strcat(strNew, _str.strNew);
	cout << strNew << endl;
	return *this;
}

String& String::Prepend(const String& _str)
{
	cout << "\n--- prepend? function ---" << endl;
	strcat(_str.strNew, " ");
	strcat(_str.strNew, strNew);
	cout << _str.strNew << endl;
	return *this;
}

const char* String::CStr() const
{
	return strNew; // collected from private class
}

String& String::ToLower() // makes every char lowercase
{
	for (size_t i = 0; i < strlen(strNew); i++) {

		strNew[i] = tolower(strNew[i]);
	}

	cout << "Lowercase: " << strNew << endl;

	return *this;
}

String& String::ToUpper() // makes every char UPPERCASE
{
	for (size_t i = 0; i < strlen(strNew); i++) {

		strNew[i] = toupper(strNew[i]);
	}

	cout << "Uppercase: " << strNew << endl;

	return *this;
}

size_t String::Find(const String& _str)
{
	char* found = strstr(strNew, _str.strNew);

	

	if (found == nullptr) return -1;

	cout << "First occurance is " << found << endl;

	return found - strNew;
}

size_t String::Find(size_t _startIndex, const String& _str)
{
	if ((_startIndex < 0) || (_startIndex >= strlen(strNew))) return -1;

	char* foundIndexed = strstr(strNew + _startIndex, _str.strNew);

	if (foundIndexed == nullptr) return -1;

	return foundIndexed - strNew;
}

String& String::Replace(const String& _find, const String& _replace)
{
	size_t replace = 0;

	while (replace != -1) {
		replace = Find(replace, _find.strNew);

		strNew[replace] = *_replace.strNew;
	}

	return *this;
}

String& String::ReadFromConsole()
{
	cout << "READING FROM FILE: " << "Hello_World.txt:" << endl;
	fstream wordsReader("Hello_World.txt", ios::in);
	string word;

	while (!wordsReader.eof())
	{
		wordsReader >> word;
		cout << word << " ";
	}
	cout << endl;

	wordsReader.close();

	return *this;
}

String& String::WriteToConsole()
{
	cout << "WRITING TO FILE" << endl;
	fstream file;
	file.open("test.txt", ios::out);
	file << strNew << endl;
	file.close();

	return *this;
}

bool String::operator==(const String& _other) // operator overload for equality ('==')
{
	if (strcmp(strNew, _other.strNew) == 0) return true;

	else return false;
}

bool String::operator!=(const String& _other) // operator overload for inequality ('!=')
{
	if (strcmp(strNew, _other.strNew) != 0) return true;

	else return false;
}

String& String::operator=(const String& _str) // operator overload for assignment ('=')
{
	strcpy(strNew, _str.strNew);
	return *this;
}

char& String::operator[](size_t index)
{

	if (strlen(strNew) <= 0) cout << "NO STRING INPUT";

	if (strNew[index - 1] < (strlen(strNew)) || ('\0') || (strNew[index - 1] <= -1)) cout << "INVALID INPUT";
	else cout << strNew[index - 1];


	return strNew[index];
}



