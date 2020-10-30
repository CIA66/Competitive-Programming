#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

char couple(char x){
	if(x == '}') return '{';
	if(x == ']') return '[';
	if(x == ')') return '(';
	return '*';
}
int main(){
	
	int n;
	char str[1006];
	scanf("%d", &n);
	while(n--){
		getchar();
		scanf("%s", str);
		stack <char> st;
		int len = strlen(str);
		bool valid = true;
		for(int i = 0; i < len; i++){
			
			if(str[i] == '{' || str[i] == '(' || str[i] == '['){
				st.push(str[i]);
			}
			else if(st.empty()){
				valid = false;
				break;
			}
			else if(st.top() != couple(str[i])){
//				printf("%c %c", st.top(), couple(str[i]));
				valid = false;
				break;
			}
			else if(st.top() == couple(str[i])){
				st.pop();
			}
//				printf("%d\n", st.size());
		}
		if(st.size() != 0 || !valid) printf("NO\n");
		else if(valid) printf("YES\n");
		while(!st.empty()){
			st.pop();
		}
	}
	
	
	return 0;
}

/*

3
{[()]}
{[(])}
{{[[(())]]}}

*/