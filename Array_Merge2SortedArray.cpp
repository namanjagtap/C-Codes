#include <bits\stdc++.h>
using namespace std;

void mergeES(int arr1[], int arr2[], int m, int n){
    int i=0, j=0, k=m-1;

    while(i<=k && j<=n){
        if(arr1[i]<arr2[j])
            i++;
        else
            swap(arr2[j++], arr1[k--]);
    }
    sort(arr1, arr1+m);
    sort(arr2, arr2+n);
}

void mergeWES(int arr1[], int arr2[], int m, int n){
    for(int i=0;i<=m;i++){
        if(arr1[i]>arr2[0]){
            swap(arr1[i], arr2[0]);
            int j=0;

            while(j+1<n && arr2[j]>arr2[j+1]){
                swap(arr2[j],arr2[j+1]);
                j++;
            }
        }
    }
}

int main()
{

	int ar1[] = {2, 4, 6, 8};
	int ar2[] = {1, 3, 5, 7};
	int m = sizeof(ar1) / sizeof(ar1[0]);
	int n = sizeof(ar2) / sizeof(ar2[0]);
  cout<<m<<"---"<<n<<endl;
	mergeWES(ar1, ar2, m, n);

	cout << "After Merging \nFirst Array: ";
	for (int i = 0; i < m; i++)
		cout << ar1[i] << " ";
	cout << "\nSecond Array: ";
	for (int i = 0; i < n; i++)
		cout << ar2[i] << " ";
	return 0;
}
