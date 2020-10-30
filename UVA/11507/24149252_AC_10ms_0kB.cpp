#include<stdio.h>
#include<string.h>

const char *arah(const char before[], const char lipet[]){
	if(strcmp(before, "+x") == 0 && strcmp(lipet, "+y") == 0) return "+y";
	else if(strcmp(before, "+x") == 0 && strcmp(lipet, "-y") == 0) return "-y";
	else if(strcmp(before, "+x") == 0 && strcmp(lipet, "+z") == 0) return "+z";
	else if(strcmp(before, "+x") == 0 && strcmp(lipet, "-z") == 0) return "-z";
	
	else if(strcmp(before, "-x") == 0 && strcmp(lipet, "+y") == 0) return "-y";
	else if(strcmp(before, "-x") == 0 && strcmp(lipet, "-y") == 0) return "+y";
	else if(strcmp(before, "-x") == 0 && strcmp(lipet, "+z") == 0) return "-z";
	else if(strcmp(before, "-x") == 0 && strcmp(lipet, "-z") == 0) return "+z";
	/////////////////////
	else if(strcmp(before, "+y") == 0 && strcmp(lipet, "+y") == 0) return "-x";
	else if(strcmp(before, "+y") == 0 && strcmp(lipet, "-y") == 0) return "+x";
	else if(strcmp(before, "+y") == 0 && strcmp(lipet, "+z") == 0) return "+y";
	else if(strcmp(before, "+y") == 0 && strcmp(lipet, "-z") == 0) return "+y";
	
	else if(strcmp(before, "-y") == 0 && strcmp(lipet, "+y") == 0) return "+x";
	else if(strcmp(before, "-y") == 0 && strcmp(lipet, "-y") == 0) return "-x";
	else if(strcmp(before, "-y") == 0 && strcmp(lipet, "+z") == 0) return "-y";
	else if(strcmp(before, "-y") == 0 && strcmp(lipet, "-z") == 0) return "-y";
	////////////////////
	else if(strcmp(before, "+z") == 0 && strcmp(lipet, "+y") == 0) return "+z";
	else if(strcmp(before, "+z") == 0 && strcmp(lipet, "-y") == 0) return "+z";
	else if(strcmp(before, "+z") == 0 && strcmp(lipet, "+z") == 0) return "-x";
	else if(strcmp(before, "+z") == 0 && strcmp(lipet, "-z") == 0) return "+x";
	
	else if(strcmp(before, "-z") == 0 && strcmp(lipet, "+y") == 0) return "-z";
	else if(strcmp(before, "-z") == 0 && strcmp(lipet, "-y") == 0) return "-z";
	else if(strcmp(before, "-z") == 0 && strcmp(lipet, "+z") == 0) return "+x";
	else if(strcmp(before, "-z") == 0 && strcmp(lipet, "-z") == 0) return "-x";
}



int main(){
	

	int L;
	while(1){
		scanf("%d", &L); getchar();
		if(L == 0) break;
		
		char before[6] = "+x", now[6]; 
		for(int j = 1; j <= L-1; j++){
			scanf("%s", now);
			if(strcmp(now, "No") == 0) continue;
			strcpy(before, arah(before, now));
		}
		printf("%s\n", before);
	}
	
	return 0;
}


/*

3
+z -z
3
+z +y
2
+z
4
+z +y +z
5
No +z No No
0


*/