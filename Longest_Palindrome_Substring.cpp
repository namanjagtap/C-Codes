// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code maxlengths
class Solution {
  public:
    
    string printLPS(string s, int start, int maxlength){
        string result;
        for(int i=start;i<=maxlength;i++){
            result+=s[i];
        }
        return result;
    }
    string longestPalin (string s) { 
        int start = 0, maxlength = 1;
        int l, h;
        
        for(int i=1;i<s.length();i++){
            l = i-1;
            h = i;
            while(l>=0 && h<s.length() && s[l]==s[h]){
                if(h-l+1>maxlength){
                    start = l;
                    maxlength = h-l+1;
                }
                l--;
                h++;
            }
            
            l = i-1;
            h = i+1;
            while(l>=0 && h<s.length() && s[l]==s[h]){
                if(h-l+1>maxlength){
                    start = l;
                    maxlength = h-l+1;
                }
                l--;
                h++;
            }
        }
        return printLPS(s, start, start+maxlength-1);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}