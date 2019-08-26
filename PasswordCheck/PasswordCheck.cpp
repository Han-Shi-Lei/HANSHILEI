#include <math.h>
#include <string.h>
#include <fstream>
#include "PasswordCheck.h"

PasswordCheck::PasswordCheck()
:chunkByte_(N){
	init();
	memset(chunk_, 0, chunkByte_);
	totalByte_ = lastByte_ = 0;
}

void PasswordCheck::init(){
	//初始化 A,B,C,D
	a_ = 0x67452301;
	b_ = 0xefcdab89;
	c_ = 0x98badcfe;
	d_ = 0x10325476;

	size_t shift[] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
		12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
		4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
		15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };
	memcpy(sft_, shift, sizeof(shift));
	for (int i = 0; i < 64; ++i){
		k_[i] = (size_t)(abs(sin(i + 1.0)) * pow(2.0, 32));
	}
}

//加密文件
std::string PasswordCheck::EncryptionFile(const char* filename){
	std::ifstream fin(filename, std::ifstream::binary);
	if (fin.is_open()){
		while (!fin.eof()){
			fin.read((char*)chunk_, chunkByte_);
			if (chunkByte_ != fin.gcount())
				break;

			totalByte_ += chunkByte_;
			Encryption((size_t*)chunk_);
		}
		lastByte_ = fin.gcount();
		totalByte_ += lastByte_;
		EncryptionLast();
	}
	return TurnHexString(a_) + TurnHexString(b_) + TurnHexString(c_) + TurnHexString(d_);
}
//加密字符串
std::string PasswordCheck::EncryptionString(const std::string& str){
	if (str.empty()){
		return "";
	}
	else{
		unsigned char* pstr = (unsigned char*)str.c_str();
		size_t numChunk = str.size() / chunkByte_;
		for (size_t i = 0; i < numChunk; ++i){
			totalByte_ += chunkByte_;
			Encryption((size_t*)(pstr + i * chunkByte_));
		}
		lastByte_ = str.size() % chunkByte_;
		memcpy(chunk_, pstr + totalByte_, lastByte_);
		totalByte_ += lastByte_;
		EncryptionLast();
		return TurnHexString(a_) + TurnHexString(b_) + TurnHexString(c_) + TurnHexString(d_);
	} //end else
}


void PasswordCheck::Encryption(size_t* chunk){
	size_t a = a_;
	size_t b = b_;
	size_t c = c_;
	size_t d = d_;

	//chunk[g]   f:哈希函数的返回值
	size_t f, g;

	//变换四轮
	for (size_t i = 0; i < 64; ++i){
		if (i >= 0 && i < 16){
			f = F(b, c, d);
			g = i;
		}
		else if (i >= 16 && i < 32){
			f = G(b, c, d);
			g = (5 * i + 1) % 16;
		}
		else if (i >= 32 && i < 48){
			f = H(b, c, d);
			g = (3 * i + 5) % 16;
		}
		else{
			f = I(b, c, d);
			g = (7 * i) % 16;
		}

		size_t dtemp = d;
		d = c;
		c = b;
		b = b + shiftLeftRotate(a + f + k_[i] + chunk[g], sft_[i]);
		a = dtemp;
	}


	a_ += a;
	b_ += b;
	c_ += c;
	d_ += d;
}

//加密最后一块数据
void PasswordCheck::EncryptionLast(){
	//lastByte_：小于64个字节，表示最后一块数据大小
	//需要填充的起始位置
	unsigned char* p = chunk_ + lastByte_;
	//填充位的前八位:1000 0000 十六进制:0X80
	*p++ = 0x80;
	//剩余的填充位 chunkByte_ 64个字节 
	size_t remainFillByte = chunkByte_ - lastByte_ - 1;
	//remainFillByte < 8
	if (remainFillByte < 8){
		//从下一个字节开始全部填0
		memset(p, 0, remainFillByte);
		Encryption((size_t*)chunk_);
		//重新造一块数据，全部填0
		memset(chunk_, 0, chunkByte_);
	}
	else{
		//如果大于八个字节，也全部置0
		memset(p, 0, remainFillByte);
	}

	//最后64位存放原文档的bit长度
	((unsigned long long*)chunk_)[7] = totalByte_ * 8;
	Encryption((size_t*)chunk_);
}

std::string PasswordCheck::TurnHexString(size_t num){
	static std::string strMap = "0123456789abcdef";
	std::string ret;
	std::string byteStr;
	for (int i = 0; i < 4; ++i){
		byteStr = "";
		size_t tmp = (num >> (i * 8)) & 0xff;
		for (int j = 2; j > 0; --j){
			//头插
			byteStr.insert(0, 1, strMap[tmp % 16]);
			tmp /= 16;
		}
		//相当于尾插
		ret += byteStr;
	}
	return ret;
}
