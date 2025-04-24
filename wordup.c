//Shawn Alphonso
//Date:4/21/2025
//Purpose: Project 10
#include<stdio.h>
#define wordlength 5

void getword(char* word);
void lowercase(char* guess);
void userguess(char* guess,int attempts);
void checkguess(char* guess,char* word,char levels[][wordlength+1],char mark[][wordlength+1],int attempts);
void won(int attempts,char* guess,char* word,int* win);
void checkletters(char* guess,int* v);
void alpha(char* guess,int* u);

int main(){

int attempts=0;
char word[wordlength+1];
char guess[wordlength+1];
int v=0,u=0;
int win =0;
char levels[6][wordlength+1];
char mark[6][wordlength+1];

	getword(word);
		while(attempts<6){
			do{
				v=0;
				u=0;
		
				userguess(guess,attempts);
				lowercase(guess);
				checkletters(guess,&v);
		 		alpha(guess,&u);
		
		
			}while(v==0||u==0);
		
			checkguess( guess,word,levels,mark,attempts);
		        won(attempts,guess,word,&win);
				if(win==1){
					break;
					 }		
	 


			attempts++;
		}

return 0;
}

void getword(char* word){

FILE* ptr = fopen("mystery.txt","r");
	if(ptr==NULL){
		printf("Error");
	return;
	}
		fscanf(ptr,"%s",word);
		fclose(ptr);
}

void lowercase(char* guess){
	for(int i=0;guess[i]!='\0';i++){
		if(guess[i]>='A'&& guess[i]<='Z'){
			guess[i]=guess[i]+32;
		}
	}
}

void userguess(char* guess,int attempt){
	
	printf("\nGuess %d Enter your guess: ",attempt+1);
	scanf("%s",guess);
	
	printf("\n==================\n");
	
	
	}

void checkletters(char* guess,int* v){
int length =0;
	for(int i=0;guess[i]!='\0';i++){
	length++;
	
	
	}
	
	
	if(length>wordlength){
	printf("Your Guess is too long\n");
		*v=0;
		
		
	}else if(length<wordlength){
		printf("Too short\n");
		*v=0;
	
	}else{
		*v=1;
		
	}	
		
		
		
}
	
void alpha(char* guess,int* u){
*u=1;
	for(int i=0;guess[i]!='\0';i++){
		char c=guess[i];

		if((c>='A'&& c<= 'Z')||(c>='a' && c<='z')){
		
		}else{
			printf("Alphabets only\n");
			*u=0;
		break;
			
			
		}
	}
		
		
}

void checkguess(char* guess,char* word,char levels[][wordlength+1],char mark[][wordlength+1],int attempts){

	for(int i=0;i<wordlength;i++){
		mark[attempts][i]=' ';
		levels[attempts][i]=guess[i];
			
			if(guess[i]==word[i]){
			
		 		levels[attempts][i]=guess[i]-32;
			
			}else{
				int f=0;
		
				for(int j=0;j<wordlength;j++){
					if(guess[i]==word[j] && i!=j){
						f=1;
				
					}
				}	
						if(f==1){	
							mark[attempts][i]='^';
						}		
			}
				
	}
	
	for(int i=0;i<=attempts;i++){
		for(int j=0;j<wordlength;j++){
			printf("%c",levels[i][j]);
		}
			printf("\n");
		for(int k=0;k<wordlength;k++){
	
			printf("%c",mark[i][k]);
		}
			printf("\n");
	}
	
}

void won(int attempts,char* guess,char* word,int* win){
int match=1;
*win=0;
	for(int i=0;i<wordlength;i++){
		if(guess[i]!=word[i]){
			match =0;
		}
	
	}
	if(match==1){
		printf("\n            %s      \n",word);
		printf("     you won in %d tries  \n",attempts+1);
		printf("            Nice          \n");
			*win = 1;
	}else if(attempts==5){
		printf("           You lost   \n");
	}
			
}
			
