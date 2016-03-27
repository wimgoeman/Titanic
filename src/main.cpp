#include <iostream>

#include "Scanner/FileInfo.h"

using namespace std;

int main(int argc, char* argv[]) {
	titanic::scanner::FileInfo fileInfo;
	fileInfo.setFilename("Booyah");
	cout << fileInfo.getFilename() << endl;
	return 0;
}
