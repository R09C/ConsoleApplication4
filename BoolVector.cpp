#include "BoolVector.h"

void BoolVector::setUpM() {
	m = (n + 7) / 8;
}

void BoolVector::Input() {
	bv = new UC[m];
	memset(bv, 0, m);
}
void BoolVector::Input(char* s) {
	bv = new UC[m];
	memset(bv, 0, m);
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		int reversedIndex = len - 1 - i; // Индекс для записи битов справа налево
		int byteIndex = reversedIndex / 8;
		int bitIndex = reversedIndex % 8;

		if (s[i] == '1') {
			bv[byteIndex] |= (1 << bitIndex);
		}
	}
}

BoolVector::BoolVector() {
	n = 1;
	setUpM();
	Input();
}

BoolVector::BoolVector(int n):n(n) {
	setUpM();
	Input();

}

BoolVector::BoolVector(char* s,int n) :n(n) {
	setUpM();
	Input(s);

}
BoolVector::BoolVector(char* s){
	n = strlen(s);
	setUpM();
	Input(s);

}

BoolVector::BoolVector(const BoolVector& other){
	n = other.n;
	m = other.m;
	bv = other.bv;
}

BoolVector BoolVector::operator=(const BoolVector& other){
	n = other.n;
	m = other.m;
	bv = other.bv;
	return *this;
}

ostream& operator<<(ostream& r, BoolVector& V) {
	for (int i = 0; i < V.n; i++) {
		int reversedIndex = V.n - 1 - i;
		int byteIndex = reversedIndex / 8;
		int bitIndex = reversedIndex % 8;
		bool bit = (V.bv[byteIndex] & (1 << bitIndex)) != 0;
		r << (bit ? '1' : '0');
	}
	return r;
}

istream& operator>>(istream& r, BoolVector& V) {
	char temp;
	for (int i = 0; i < V.n; i++) {
		int reversedIndex = V.n - 1 - i;
		int byteIndex = reversedIndex / 8;
		int bitIndex = reversedIndex % 8;
		r >> temp;
		if (temp == '1')
			V.bv[byteIndex] |= (1 << bitIndex);
		else if (temp == '0')
			V.bv[byteIndex] &= ~(1 << bitIndex);
		else
			i--;  // Некорректный символ, повторяем итерацию
	}
	return r;
}

void BoolVector::Scan(){
	cin >> *this;
}

void BoolVector::Print(){
	cout << *this;
}

bool BoolVector::operator[](int index) {
	if (index >= 0 && index < n) {
		bool bit = (bv[(n - 1 - index) / 8] & (1 << ((n - 1 - index) % 8)));
		return bit;
	}
	else {
		return 0;
	}
}

int BoolVector::Weight() {
	int weight = 0;
	for (int i = 0; i < n; i++) {
		int byteIndex = i / 8;
		int bitIndex = i % 8;

		bool bit = (bv[byteIndex] & (1 << bitIndex)) != 0;
		bit ? weight++ : weight;
	}
	return weight;
}

bool BoolVector::operator==(const BoolVector& other) {
	if (n == other.n) {
		for (int i = 0; i < n; i++) {
			if (bv[i] != other.bv[i]) {
				return false;
			}
			return true;
		}
	}
	return false;
}

bool BoolVector::operator!=(const BoolVector& other) {
	return !(*this == other);
}

bool BoolVector::operator< (BoolVector& other) {
	if (n == other.n) {
		for (int i = 0; i < n; i++) {
			if (bv[i] > other.bv[i]) {
				return false;
			}
			return true;
		}
	}
	return false;
}

bool BoolVector::operator> (BoolVector& other) {
	if (n == other.n) {
		for (int i = 0; i < n; i++) {
			if (bv[i] < other.bv[i]) {
				return false;
			}
			return true;
		}
	}
	return false;
}

BoolVector BoolVector::operator & (const BoolVector& other) {
	int minLength = min(n,other.n);
	BoolVector newBV = BoolVector(minLength);
	for (int i = 0; i < newBV.m; i++) {
		newBV.bv[i] = bv[i] & other.bv[i];
	}
	return newBV;
}

BoolVector& BoolVector::operator &= (const BoolVector& other) {
	for (int i = 0; i < m; i++) {
		 bv[i] &= other.bv[i];
	}
	return *this;
}

BoolVector BoolVector::operator | (const BoolVector& other) {
	int maxLength = max(n, other.n);
	BoolVector newBV = BoolVector(maxLength);
	for (int i = 0; i < newBV.m; i++) {
		newBV.bv[i] = bv[i] | other.bv[i];
	}
	return newBV;
}

BoolVector& BoolVector::operator |= (const BoolVector& other) {
	int i_m= max(m, other.m);
	for (int i = 0; i < other.m; i++) {
		bv[i] |= other.bv[i];
	}
	return *this;
}

BoolVector BoolVector::operator ^ (const BoolVector& other) {
	BoolVector newBV = BoolVector(n);
	for (int i = 0; i < n; i++) {
		newBV.bv[i] = bv[i] ^ other.bv[i];
	}
	return newBV;
}

BoolVector& BoolVector::operator ^= (const BoolVector& other) {
	for (int i = 0; i < n; i++) {
		bv[i] ^= other.bv[i];
	}
	return *this;
}

BoolVector BoolVector::operator ~() {
	BoolVector newBV = BoolVector(n);
	for (int i = 0; i < n; i++) {
		newBV.bv[i] = ~bv[i];
	}
	return newBV;
}

BoolVector BoolVector::operator <<(const int shift) {
	BoolVector newBV = BoolVector(n);
	int byteShift = shift / 8;
	int bitShift = shift % 8;

	for (int i = 0; i < n - byteShift; i++) {
		newBV.bv[i] = bv[i + byteShift] << bitShift;
		if (i + byteShift + 1 < n) {
			newBV.bv[i] |= bv[i + byteShift + 1] >> (8 - bitShift);
		}
	}

	return newBV;
}


BoolVector& BoolVector::operator <<= (const int shift) {
	int byteShift = shift / 8;
	int bitShift = shift % 8;

	for (int i = 0; i < n - byteShift; i++) {
		bv[i] = bv[i + byteShift] << bitShift;
		if (i + byteShift + 1 < n) {
			bv[i] |= bv[i + byteShift + 1] >> (8 - bitShift);
		}
	}

	return *this;
}

BoolVector BoolVector::operator >>(const int shift) {
	BoolVector newBV = BoolVector(n);
	int byteShift = shift / 8;
	int bitShift = shift % 8;

	for (int i = n - 1; i >= byteShift; i--) {
		newBV.bv[i] = bv[i - byteShift] >> bitShift;
		if (i - byteShift - 1 >= 0) {
			newBV.bv[i] |= bv[i - byteShift - 1] << (8 - bitShift);
		}
	}

	return newBV;
}

BoolVector& BoolVector::operator >>= (const int shift) {
	int byteShift = shift / 8;
	int bitShift = shift % 8;

	for (int i = n - 1; i >= byteShift; i--) {
		bv[i] = bv[i - byteShift] >> bitShift;
		if (i - byteShift - 1 >= 0) {
			bv[i] |= bv[i - byteShift - 1] << (8 - bitShift);
		}
	}

	return *this;
}


BoolVector BoolVector::SetUp1(int pos) {
	int byteIndex = pos / 8;
	int bitIndex = pos % 8;
	bv[byteIndex] |= (1 << bitIndex);
	return *this;
}

BoolVector BoolVector::SetUp0(int pos) {
	
	int byteIndex = pos / 8;
	int bitIndex = pos % 8;
	bv[byteIndex] &= ~(1 << bitIndex);
	return *this;
}

BoolVector BoolVector::Invert(int pos) {
	bv[pos / 8] ^= (1 << pos % 8);
	return *this;
}

BoolVector BoolVector::SetUp1(int kol, int pos) {
	for (int i = pos; i < pos+kol; i++) {
		this->SetUp1(i);
	}
	return *this;
}

BoolVector BoolVector::SetUp0(int kol, int pos) {
	for (int i = pos; i < pos+kol; i++) {
		this->SetUp0(i);
	}
	return *this;
}

BoolVector BoolVector::Invert(int kol, int pos) {
	for (int i = pos; i < pos+kol; i++) {
		this->Invert(i);
	}
	return *this;
}

BoolVector& BoolVector::Invert() {
	for (int i = 0; i <n; i++) {
		int reversedIndex = n - 1 - i;
		int byteIndex = reversedIndex / 8;
		int bitIndex = reversedIndex % 8;
		bv[byteIndex] ^= (1 << bitIndex);
	}
	return *this;
}












