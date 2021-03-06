// OpenWith_textfile_hook.cpp

#include "pch.h"
#include <iostream>
#include <fstream>      // std::ifstream
#include <windows.h>
#include <string.h>

using namespace std;

bool IsTextFileForSure(char* filePath) {
	int c;
	std::ifstream a(filePath, std::ios::binary);
	int counter = 0;
	// First 2 bytes could be the BOM
	while ((c = a.get()) != EOF
		&& (c <= 127 || counter < 3)
		&& (c != 0 || counter % 2 == 1)) // Is unicode?
	{
		counter++;
		if (counter > 1000000)
		{
			cout << "File bigger than a Megabite, we are not sure if the user wan't to open this with the default text editor";
			return false;
		}
		//cout << c << " ";
	}
	cout << c << "\n";
	if (c == EOF) {
		/* file is all ASCII */
		return true;
	}
	return false;
}

int main(int argc, char *argv[])
{
	std::cout << "Hello World!\n";
	cout << "Arg: " << argv[1] << "\n";
	auto b = IsTextFileForSure(argv[1]);
	cout << "Is text: " << b;
	string file = string("\"") + argv[1] + "\"";
	if (b)
	{
		ShellExecuteA(NULL, "open", "C:\\Program Files\\Sublime Text 3\\sublime_text.exe", file.c_str(), NULL, SW_SHOWDEFAULT);
	}
	else {
		// %SystemRoot% C:\\Windows
		ShellExecuteA(NULL, "open", "C:\\Windows\\system32\\OpenWith.exe", file.c_str(), NULL, SW_SHOWDEFAULT);
	}
#ifdef _DEBUG
	cin.get();
#endif
}
