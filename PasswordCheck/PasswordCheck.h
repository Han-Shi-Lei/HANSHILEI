#pragma once 

#define N 64
#include <string>

class PasswordCheck{
public:



	PasswordCheck();

	std::string EncryptionFile(const char* filename);
	std::string EncryptionString(const std::string& str);



private:

	//��ʼ������
	void init();
	//����ÿһ������
	void Encryption(size_t* chunk);
	//�������һ������
	void EncryptionLast();

	//ת����ʮ�������ַ���
	std::string TurnHexString(size_t num);

	size_t shiftLeftRotate(size_t num, size_t n){
		return (num << n) | (num >> (32 - n));
	}

	size_t F(size_t x, size_t y, size_t z){
		return (x & y) | ((~x) & z);
	}
	size_t G(size_t x, size_t y, size_t z){
		return (x & z) | (y & (~z));
	}
	size_t H(size_t x, size_t y, size_t z){
		return x ^ y ^ z;
	}
	size_t I(size_t x, size_t y, size_t z){
		return y ^ (x | (~z));
	}

private:
	size_t a_;
	size_t b_;
	size_t c_;
	size_t d_;

	size_t k_[N];
	size_t sft_[N];

	const size_t chunkByte_;
	unsigned char chunk_[N];

	size_t lastByte_;
	unsigned long long totalByte_;
};
