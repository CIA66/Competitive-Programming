#include<bits/stdc++.h>

using namespace std;


int main(){
	
	string command;
	map <string, int> stringInt;
	map <int, string> intString;
	
	while(1){
		cin >> command;
		if(cin.eof()) break;
		if(command == "clear"){
			stringInt.clear();
			intString.clear();
		}
		
		string nama; int harga;
		if(command == "def"){
			cin >> nama >> harga;
			
			if(stringInt.find(nama) != stringInt.end()){
				int temp = stringInt[nama];
				stringInt.erase(nama);
				intString.erase(temp);
			}
			stringInt[nama] = harga;
			intString[harga] = nama;
		}
		else if(command == "calc"){
			string str; int valid = 1, total = 0, start = 1, bef = 1;
			string hasil;
			while(1){
				cin >> str;
				if(start == 1){
					hasil += str;
					start = 0;
				}
				else if(start == 0){
					hasil += " ";
					hasil += str;
				}
//				cout << hasil << endl;
				if(str == "="){
					break;
				}
				if(str == "+"){
					bef = 1;
					continue;
				}
				else if(str == "-"){
					bef = 2;
					continue;
				}
				
				
				if(stringInt.find(str) == stringInt.end()){
					// not found
					valid = 0;
				}
				else{
				  	// found
				  	if(bef == 1){
				  		total += stringInt[str];
					}
					else if(bef == 2){
						total -= stringInt[str];
					}
				  	
//				  	cout << "--" << stringInt[str] << endl;
				}
			}
			
			if(valid == 0){
				cout << hasil << " " << "unknown" << endl;
			}
			else{
//				printf("total: %d\n", total);
				if(intString.find(total) == intString.end()){
					// not found
//					printf("---\n");
					cout << hasil << " " << "unknown" << endl;
				}
				else{
				  	// found
				  	cout << hasil << " " << intString[total] << endl;
				}
			}
		}
		
	}
	
	
	return 0;
}

/*

def b 3
def a 1
calc b + a =

*/