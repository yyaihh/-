#pragma once
#include"bignum.hpp"
//#define NUMBER 128
//
//struct Key {
//	DataType m_ekey;//��Կe
//	DataType m_dkey;//˽Կd
//	DataType m_nkey;//����ģ��n
//};
//
//class RSA {
//	Key m_key;
//	BigNum bg;
//
//	DataType getNkey(DataType& prime1, DataType& prime2);//��ȡ����ģ��n
//	DataType getOrla(DataType& prime1, DataType& prime2);//ŷ������, �õ�f(n)
//	DataType getEkey(DataType& orla);//��ȡ��Կ
//	DataType getDkey(DataType& ekey, DataType& orla);//��ȡ˽Կ
//	DataType exGcd(DataType a, DataType b, DataType* x, DataType* y);//��ģ��Ԫ��
//	DataType getGcd(DataType num1, DataType num2);//���Լ��
//	DataType _encrypt(DataType data, DataType& ekey, DataType& nkey);//����,��Ҫ�������ݺ͹�Կ(e, n)
//	DataType _decrypt(DataType data, DataType& dkey, DataType& nkey);//����,��ҪҪ���ܵ����ݺ�˽Կ(d, n)
//	void getKeys();
//public:
//	RSA() { getKeys();}
//	Key getKey();
//	void encrypt(const char* filename, const char* outname);//����
//	void decrypt(const char* filename, const char* outname);//����
//};