#include <stdio.h>
//#define bitSet(x, bit) (x|(1<<(bit)))
//#define bitSet_(x, bit) (x|=(1<<(bit)))
#define bitSet(x, bit) (x | (1<<(bit)))
#define bitClear(x,bit) (x & ~(1<<bit))
#define bitFlip(x, bit) (x^(1<<bit)) 
#define bitIsSet(x,bit) (x & 1<<bit)

// 시간 있을 땐 truth table 작성하는 것이 좋은 듯

int main() {
	unsigned cnum = 0x16;// 0001 0110 각 자리수 4bit임.
	int x = bitSet(cnum, 3);			// 0x1e
	int y = bitClear(cnum, 3); // 기대값 0001 0110
	int z = bitFlip(cnum, 3); // 기대값 0001 1110
	bitIsSet(cnum, 3); // 0 나와야함


	printf("%x\n", x);
	printf("%x\n", y);
	printf("%x\n", z);
	printf("%d\n", bitIsSet(cnum, 3));
	return 0;
}
