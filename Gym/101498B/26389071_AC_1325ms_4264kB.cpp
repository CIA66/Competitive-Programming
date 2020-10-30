#include<bits/stdc++.h>

using namespace std;

void LengthLCP(string x, string y){
    
	int fr[26] = {0}; 
       
    int a = x.length(); // length of x 
    int b = y.length(); // length of y 
       
    for (int i=0; i<b ;i++){
        // creating frequency array of 
        // characters of y 
        fr[y[i] - 97] += 1; 
    } 
    // storing the length of  
    // longest common prefix 
    int c = 0; 
       
    for (int i=0; i<a ;i++){
        // checking if the frequency of the character at 
        // position i in x in b is greater than zero or not 
        // if zero we increase the prefix count by 1 
        if (fr[x[i] - 97] > 0){ 
            c += 1; 
            fr[x[i] - 97] -= 1; 
        } 
        else
            break; 
    } 
    cout<<(c)<<endl; 
}

int main(){
	
	int T;
	scanf("%d", &T);
	while(T--){
		string s1, s2; 
		cin >> s1 >> s2;
		LengthLCP(s1, s2);
		
	}
	return 0;
}