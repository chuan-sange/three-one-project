

int main(int n, char **arg){
	
	int i;
	
	char a[20] = "tcc -c ";
	char b[50] = "tlink c0s main ";
	char c[20] = ",";
	char d[20] = ",,cs.lib ";
	
	strcat(a, arg[1]);
	system(a);
	
	for(i = 0; arg[1][i] != '\0'; i++){
		if(arg[1][i] == '.'){
			arg[1][i] = '\0';
		}
	}
	
	strcat(b, arg[1]);
	strcat(b, c);
	
	strcat(b, arg[1]);
	strcat(b, d);   /*tlink c0s main xx,xx,,cs.lib*/
	
	system(b);
	
	
}