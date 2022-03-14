#include<iostream>
using namespace std;

// check for a sorted array
bool sorted(int arr[], int n){
    if(n==1){
        return true;
    }
    bool restArray = sorted(arr+1,n-1);
    return (arr[0]<arr[1]&&restArray); 
}
// print number in decreasing order
void dec(int n){
    if(n==1){
        cout<<"1"<<endl;
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}
// print number in asending order
void inc(int n){
    if(n==1){
        cout<<"1"<<endl;
        return;
    }
    inc(n-1);
    cout<<n<<endl;
}
void badte(int n){
    if(n==1){
        cout<<"1"<<endl;
        return;
    }
    cout<<n<<endl;
        badte(n-1);

}

int firstOcc(int n, int arr[], int i, int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstOcc(n, arr, i+1, key);
}

int lastOcc(int n, int arr[], int i, int key){
    if(i==n){
        return -1;
    }
    int restArray = lastOcc(n, arr, i+1, key);
    if(restArray!=-1){
        return restArray;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}

void reverse(string s){
    if(s.length()==0){
        return;
    }
    string ros = s.substr(1);
    reverse(ros);
    cout<<s[0];
}

void replacePi(string s){
    if(s.length()==0){
        return;
    }
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        replacePi(s.substr(2));
    }
    else{
        cout<<s[0];
        replacePi(s.substr(1));
    }
}

void towerOfHanoi(int n, char src, char dest, char helper){
    if (n==0)
    {
        return;
    }
    
    towerOfHanoi(n-1,src, helper, dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1,helper, dest, src);
}

string removeDup(string s){
    if(s.length()==0){
        return "";
    }
    char ch = s[0];
    string ans = removeDup(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    return (ch+ans);

}

int main(){
    int n = 5;
    int arr[]={1, 4, 3, 4, 5};
    // inc(5);
    // dec(5);
    // badte(n);
    // cout<<firstOcc(n,arr,0,4)<<endl;
    // cout<<lastOcc(n,arr,0,4)<<endl;
    // string s = "binod";
    // reverse(s);
    // replacePi("pipppiiip");
    towerOfHanoi(3,'A','C','B');
    // cout<<removeDup("nnnnammmmmaaaaan");

    return 0;
}