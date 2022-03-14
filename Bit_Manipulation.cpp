#include <iostream>
using namespace std;

int getBit(int n, int pos){
    return ((n & (1<<pos))!=0);
}
int setBit(int n, int pos){
    return (n | (1<<pos));
}
int clearBit(int n, int pos){
    int mask = ~(1<<pos);
    return (n&mask);
}
int updateBit(int n, int pos, int value){
    int mask = ~(1<<pos);
    n = n & mask;
    return n | (value<<pos);
}
bool isPower(int n){
    return (n && !(n & n-1));
}

unsigned int countSetBits(unsigned int n)
{
	unsigned int count = 0;
	while (n) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}

int PositionRightmostSetbit(int n)
{
    int position = 0;
    int m = 1;
 
    while (!(n & m)) {
 
        // left shift
        m = m << 1;
        position++;
    }
    return position;
}

int GetMSB(int shortValue)
{
    return (shortValue & 0xFF00);
}
    
int main(){
    // cout<<getBit(5, 2)<<endl;
    // cout<<setBit(5, 2)<<endl;
    // cout<<clearBit(5, 2)<<endl;
    // cout<<updateBit(5, 1, 1)<<endl;
    // cout<<isPower(16)<<endl;
    cout<<countSetBits(10)<<endl;
    cout<<PositionRightmostSetbit(10)<<endl;
    cout<<GetMSB(10)<<endl;
    
}