// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
	TELEM bits;
 	if (len<1) {
 		throw invalid_argument("Len<0...");
 	}
 	bits = (len + (BitInTELEM - 1)) >> BitInTELEM;
 	MemLen = bits;
 	BitLen = len;
 	pMem = new TELEM[MemLen];
 	for (int i = 0; i < MemLen; i++) {
		pMem[i] = 0;}
}

TBitField::TBitField(const TBitField &bf)
{
	BitLen = bf.BitLen;
 	MemLen = bf.MemLen;
 	pMem = new TELEM[MemLen];
 	for (int i = 0; i < MemLen; i++)
 		 pMem[i] = bf.pMem[i];

}

TBitField::~TBitField()
{
	delete[]pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return n >> BitInTELEM;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	return 1 << (n & (BitInTELEM - 1));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if (n<0) 
	{
 		throw invalid_argument("Bit < 0...");	
 	}
 	if (n>=BitLen) 
	{
 	throw invalid_argument("BitLen < n...");
 	}
 	pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if (n<0) {
 		throw invalid_argument("Bit < 0...");
 		
 	}
 	if (n>=BitLen) {
 		throw invalid_argument("BitLen < n...");
 		
 	}
 	pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] & ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
  	if (n<0) {
 		throw invalid_argument("n < 0...");
 	
 	}
 if (n>=BitLen) {
 		throw invalid_argument("BitLen < n...");
 		
 	}
 	if ((pMem[GetMemIndex(n)] & GetMemMask(n)) == 0) return 0;
 	else return 1;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  return 0;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
}

TBitField TBitField::operator~(void) // отрицание
{
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
}
