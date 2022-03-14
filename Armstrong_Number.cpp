#include<iostream>
#include<math.h>
using namespace std;

int power(int x, unsigned int y)
{
	if( y == 0)
		return 1;
	if (y%2 == 0)
		return power(x, y/2)*power(x, y/2);
	return x*power(x, y/2)*power(x, y/2);
}

int main(){

  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  // #endif
int n;
cin>>n;
int original=n;
int temp = n;
int cubeno=0;

// counting digits
int count = 0;
while(temp!=0){
  temp=temp/10;
  count++;
}

// Checking Armstrong
while(n > 0){
  int lastdigit=n%10;
  cubeno += power(lastdigit,count);
  n=n/10;
  cout<<lastdigit<<endl;

  cout<<cubeno<<endl;

}
if(cubeno==original){
cout<<"Its a Armstrong Number"<<endl;
}
else{
  cout<<"Not a Armstrong Number";
}

  return 0;
}