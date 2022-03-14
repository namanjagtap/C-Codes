#include <iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int N, K;
		cin>>N>>K;
		int arr[N];
		for(int i=0;i<N;i++)
			cin>>arr[i];
		int result = 0;
		for(int i=0;i<N;i++){
			result += arr[i];
			result -= K;
			if(result<0){
				cout<<"NO "<<i+1<<endl;
				break;
			}
		}
		if(result>0)
			cout<<"YES"<<endl;
	}
	return 0;
}