#include <stdio.h>

#define MAXHIST 15 
#define MAXWORD 11
#define IN 1 
#define OUT 0

int main(void){
	int c,i,charNum,state;
	int histBar_len;
	int max_length; // max Number of the word that same length words
	int ovflowWord_num; 
	int count_sameLenWord[MAXWORD]; //counter num of same length word

	state = OUT;
	charNum = 0;
	ovflowWord_num = 0;
	
	// initialize array
	for(i=0;i<MAXWORD;++i){
		count_sameLenWord[i] = 0;
	}

	//read a word by one charcter
	while((c = getchar())!= EOF ){

		// when read escape sequence 
		if(c == ' ' || c == '\n' || c == '\t'){

			state = OUT; // end of word

			if(charNum >0){
				if(charNum < MAXWORD){
					++count_sameLenWord[charNum];
				}else{
					++ovflowWord_num;
				}
			}
			charNum = 0;

		}else if(state == OUT){
			state = IN; // in the middle of word
			charNum = 1;
		}
		else{
			++charNum;
		}
	}


	max_length = 0;

	// find max_length
	for(i = 1; i<MAXWORD;++i){
		if(count_sameLenWord[i]>max_length){
			max_length = count_sameLenWord[i];
		}
	}

	for(i=1;i<MAXWORD;++i){

		printf("%5d - %5d : ",i,count_sameLenWord[i]);
		
		if(count_sameLenWord[i]>0){

			if( ( histBar_len = count_sameLenWord[i] * MAXHIST / max_length ) <= 0 ){
				histBar_len = 1;
			}

		}else{
			histBar_len = 0;
		}
		while(histBar_len > 0){
			putchar('*');
			--histBar_len;
		}
		putchar('\n');
	}
	if(ovflowWord_num > 0){
		printf("There are %d words >= %d \n",ovflowWord_num,MAXWORD);
	}
}









