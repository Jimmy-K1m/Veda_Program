#include <stdio.h>
//#define bitSet(x, bit) (x|(1<<(bit)))
//#define bitSet_(x, bit) (x|=(1<<(bit)))
#define bitSet(x, bit) (x | (1<<(bit)))
#define bitClear(x,bit) (x & ~(1<<bit))
#define bitFlip(x, bit) (x^(1<<bit)) 
#define bitIsSet(x,bit) (x & 1<<bit)

// �ð� ���� �� truth table �ۼ��ϴ� ���� ���� ��

int main() {
	unsigned cnum = 0x16;// 0001 0110 �� �ڸ��� 4bit��.
	int x = bitSet(cnum, 3);			// 0x1e
	int y = bitClear(cnum, 3); // ��밪 0001 0110
	int z = bitFlip(cnum, 3); // ��밪 0001 1110
	bitIsSet(cnum, 3); // 0 ���;���


	printf("%x\n", x);
	printf("%x\n", y);
	printf("%x\n", z);
	printf("%d\n", bitIsSet(cnum, 3));
	return 0;
}
