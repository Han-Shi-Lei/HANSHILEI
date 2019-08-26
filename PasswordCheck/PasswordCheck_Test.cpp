#include <iostream>

#include "PasswordCheck.h"

int main(int argc, char* argv[]){
#if 1
	if (argc != 3){
		std::cout << argv[0] << "\t0\filename" << std::endl;
		std::cout << argv[1] << "\t1\string" << std::endl;
		return 0;
	}
#endif

	PasswordCheck Password;
#if 1
	char option = *argv[1];
	switch (option){
	case '0':
		std::cout << Password.EncryptionFile(argv[2]) << std::endl;
		break;
	case '1':
		std::cout << Password.EncryptionString(argv[2]) << std::endl;
		break;
	}
#endif
	return 0;
}
