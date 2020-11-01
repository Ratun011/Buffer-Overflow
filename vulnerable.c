#include <stdio.h>
#include <string.h>

void user(){
	printf("Congrats jubair\n");
	printf("You have accessed in your machine\n");
}

void login(){
	char password[16];
	printf("Enter your password\n");
	scanf("%s", password);

	if(strcmp(password, "jubair")){
		printf("incorrect password\n");
	}
	else{
		user();
	}
}

int main()
{
	login();

	return 0;
}