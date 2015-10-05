/*
Made By Andrew Hingst (5043535)
This is a program designed to take a text file and feed the output of how frequent
words appear, as well as order of first appearance. It can hold a maximum of 30
words, and each word can only be a maximum 20 letters (including the terminating 'null' character).
It will not accept punctuation, numbers and empty space ('and4rew'would appear as 2 words, and & rew).
*/


#include <cstdio>
#include <cctype>
#include <iostream>
#include <string.h>

using namespace std;

int checkWord(char buffer[], char dictionary[][20], int max);

int main() {

char ch; 				//initialize variables
int newLine= 0;
int numWord = 0;
int currentLet = 0;
const int WORDS = 30;
const int LETTERS = 20;
const int MAXLET = LETTERS-2;
const int MAXWORD = WORDS-1;
char dictionary[WORDS][LETTERS];
char buffer[LETTERS+1];
int count[WORDS];

int tmp = 0;


cout << "Gathering Words From File...\n \n \n";

while( cin.good() ) //loop until the end of the file
{
	//cout << " good input " << endl;//TEST LINE
 ch = cin.get();
 if ( isalpha(ch) ) //Checks to see if it's a valid alphabetical character (No Nums, Punct, or Spaces)
    {
		if(currentLet < MAXLET){ //load a word into the buffer, make sure it's not too big.
			buffer[currentLet] = ch;
			currentLet++;
			//cout << "Valid Letter Copied to "<<currentLet<<endl; //TESTLINE
		} else cout << "ERROR: Too many letters. Dumping extra letter."<<endl;
		buffer[currentLet] = '\0';
		newLine = 1;
    }
 	else if (newLine)
			//cout<<"Found Word"<<endl; //TEST LINE
          	{
              //cout << "  <" << buffer <<">  \n";//TEST LINE
              tmp = checkWord(buffer, dictionary, numWord);
			  if(tmp == -1){ //if the value returned by checking the word is not there
				if(numWord <= MAXWORD){
                    strcpy(dictionary[numWord],buffer);
					count[numWord] = 1;
					numWord++;
				} else cout << "ERROR: Too Many Words detected. Dropping excess word." << endl; //Display an error showing too many words, but continue to check for more duplicates.
			} else {
				count[tmp]++;
			}
              	newLine = 0;
				currentLet = 0;
				for(int i = 0; i < strlen(buffer); i++) buffer[i] = '\0';
          }

 	
	}

//Begin to output the proper information.
	cout << "Word:               Frequency: \n";
	cout << "-------------------------------\n";
	for(int i = 0; i < numWord; i++){
		cout << dictionary[i];
		for(int j = 0; j < MAXLET-strlen(dictionary[i]); j++) cout << " ";
		cout << count[i] << endl;
	}




return 0;
}


//Checks for the word that is loaded in Buffer to Dictionary. Max is the words currently in dictionary.
//Return the space if there is a duplicate.
int checkWord(char buffer[], char dictionary[][20], int max){

int i = 0;

for(i = 0; i < max; i++){
	if(!strcmp(buffer, dictionary[i])) return i;
}
return -1;
}









































