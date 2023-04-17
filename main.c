//
//  main.c
//  Eliza Clone
//
//Trying to make a very very very very basic clone of ELIZA.
//
//
//  Created by Seth from 4/14-17/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define BUFFER_SIZE 256


int main(int argc, const char * argv[]) {
    
    //Greeting and space
    printf(" \n");
    printf("Hi, Im rose, how are you feeling?\n");
    
    //Grabbing user input, %[^\n] allows for a sentence response, ignoring white space so scanf grabs enitre string instead of just first word/letter, grabs
    //rose "gets" response as full sentence;
    char firstResponse[BUFFER_SIZE];
    printf(" \n");
    fgets(firstResponse, sizeof(firstResponse), stdin);
    
    //Initilazing keywords, bools, and emotion
    
    const char* pronouns[20] = {"I like", "I did", "I went to", "I went", "I went on a", "I went to the", "I ate", "I ate at",
    "i went to", "i went", "i like", "i did", "i went on a", "i went to the", "i ate", "i ate at", "i had", "I had", "I passed", "i passed"};
    
    const char* positiveResponses[10] = {"Happy", "happy", "Good", "good", "Alright", "alright", "aight", "Aight", "Fine", "fine"};
    
    const char* extraPositiveResponses[6] = {"Great", "great", "Amazing", "amazing", "Wonderful", "wonderful"};
    
    //Negative responses
    
    const char* negativeResponses[6] = {"Sad", "sad", "Bad", "bad", "Unhappy", "unhappy"};
    
    const char* extraNegativeResponses[2] = {"Horrible", "horrible"};
    
    const char* no[] = {"No", "Nope", "Nah", "N", "n", "no", "nope","nah"};
    
    //Emotion bools and emotion variable, along with number of Substrings
    bool positive = false;
    bool extraPositive = false;
    bool negative = false;
    bool extraNegative = false;
    
    int numSubstrs = sizeof(pronouns) / sizeof(pronouns[0]);
    
    const char* emotion;
    
    //Running loop through positive to check to see if the firstResponse is equal to any of the positive responses
    for(int i = 0; i < sizeof(positiveResponses) / sizeof(positiveResponses[0]); i++){
        if(strstr(firstResponse, positiveResponses[i]) != NULL){
            //Sets positive to true and emotion to whatever the index was
            positive = true;
            emotion = positiveResponses[i];
            break;
            
            //Checking if their is a pronoun like "Im" in response
        }
    }
    
    //Running loop through extraPositiveResponse to check to see if the firstResponse is equal to any of the extraPositive responses
    for(int i = 0; i < sizeof(extraPositiveResponses) / sizeof(extraPositiveResponses[0]); i++){
        if(strstr(firstResponse, extraPositiveResponses[i]) != NULL){
            //Sets extraPositive to true and emotion to whatever the index was
            extraPositive = true;
            emotion = extraPositiveResponses[i];
            break;
        }
    }
    
    //Running loop through negativeResponse to check to see if the firstResponse is equal to any of the negativeResponses responses
    for(int i = 0; i < sizeof(negativeResponses) / sizeof(negativeResponses[0]); i++){
        if(strstr(firstResponse, negativeResponses[i]) != NULL){
            negative = true;
            emotion = negativeResponses[i];
            break;
        }
    }
    
    for(int i = 0; i < sizeof(extraNegativeResponses) / sizeof(negativeResponses[0]); i++){
        if(strstr(firstResponse, extraNegativeResponses[i]) != NULL){
            extraNegative = true;
            emotion = extraNegativeResponses[i];
            break;
        }
    }
    
    //If user input is equal to happy, continue, else go down
    if(positive || extraPositive){
        
        if(positive){
            //Regular level emotion if regularly happy
            printf(" \n");
            printf("Why are you feeling %s?\n", emotion);
            printf(" \n");
            
        } else if (extraPositive){
            //Extra emotion if extra happy
            printf(" \n");
            printf("Thats great! Why are you feeling %s?!\n", emotion);
            printf(" \n");
        }
        
        //Setting up response for question, while loop so it doesnt immiedieatly continue to next code segments
        
        char secondResponse[BUFFER_SIZE];
        do {
            fgets(secondResponse, sizeof(secondResponse), stdin); // Sets buffer for the response string to the size allocated, and get that with stdin
            secondResponse[strcspn(secondResponse, "\n")] = '\0'; // Looks for "\n" in the string and replaes with null term
        } while (strcmp(secondResponse, "") == 0); // Keep looping until a non-empty response is provided
        
    
        //Loop to remove any of the pronouns from the previous response to make Rose's response grammatically correct
        for (int i = 0; i < numSubstrs; i++) {
            long len = strlen(pronouns[i]);  // length of current substring to be removed
            char *p = strstr(secondResponse, pronouns[i]);  // pointer to the first occurrence of current substring in str
            while (p != NULL) {
                memmove(p, p + len, strlen(p + len) + 1); // move characters after current substring to the left
                p = strstr(secondResponse, pronouns[i]);  // search for the next occurrence of current substring in str
            }
        }
        
        //Start is the leftover space added by the previous for loop
        char *start = secondResponse;
        while (*start == ' ') {
            start++;  // Skip leading spaces
        }
    
        
        //Continuning conversation
        printf(" \n");
        printf("I see, its good that%s, makes you happy\n", secondResponse);
        sleep(2);
        //Continuing conversation with one last question
        printf("Is there anything else?\n");
        printf("\n");
        
       //Creating input variable and possible parameters
        char thirdResponse[BUFFER_SIZE];
        
        //Getting third response.
        do {
            fgets(thirdResponse, sizeof(thirdResponse), stdin); //Sets buffer for the second response, to the size of the memory allocated for thirdResponse, the grabs that thirdResponse with stdin
            thirdResponse[strcspn(thirdResponse, "\n")] = '\0'; //Looks for "\n" character in string, then replaces with null term
        } while (strcmp(thirdResponse, "") == 0);
        
        
        //Checking to see if response is in the no array.
        for(int i = 0; i < sizeof(no) / sizeof(no[0]); i++){
            if(strcmp(thirdResponse, no[i]) == 0){
                printf("\n");
                printf("Ok, well thanks for talking, goodbye!\n");
                return 0;
            }
        }
       
        //Ending regarldess of user input
        printf("\n");
        printf("Thats nice, well I have to go, but I hope we can talk again!\n");
        
        //Ending app
        return 0;
    
    //--------------------------------------------------------
    //Negative Conditions
    //--------------------------------------------------------
        
        //If user input is equal to sad continue, else go down
    } else if (negative || extraNegative){
        
        if(negative){
            //Regular level emotion if just sad
            printf(" \n");
            printf("Whats wrong, why are you feeling %s?\n", emotion);
            printf(" \n");
            
        } else if (extraNegative){
            //Extra emotion if user emotion is worse
            printf(" \n");
            printf("Im sorry! Whats going on, why are you feeling %s?\n", emotion);
            printf(" \n");
        }
        
        //Setting up response for question, while loop so it doesnt immiedieatly continue to next code segments
        
        char secondResponse[BUFFER_SIZE];
        do{
            fgets(secondResponse, sizeof(secondResponse), stdin); //Sets buffer for secondResponse to size of the memory allocated for the secondResponse var, then grabs input with stdin
            secondResponse[strcspn(secondResponse, "\n")] = '\0'; //Checking for new line character in response, then replaces with null term
        } while (strcmp(secondResponse, "") == 0);
    
        
        //Loop to remove any of the pronouns from the previous response to make Rose's response grammatically correct
        for (int i = 0; i < numSubstrs; i++) {
            long len = strlen(pronouns[i]);  // length of current substring to be removed
            char *p = strstr(secondResponse, pronouns[i]);  // pointer to the first occurrence of current substring in str
            while (p != NULL) {
                memmove(p, p + len, strlen(p + len) + 1); // move characters after current substring to the left
                p = strstr(secondResponse, pronouns[i]);  // search for the next occurrence of current substring in str
            }
        }
        
        //Start is the leftover space added by the previous for loop
        char *start = secondResponse;
        while (*start == ' ') {
            start++;  // Skip leading spaces
        }
        
        //Continuning conversation
        printf(" \n");
        printf("Im sorry, that%s is making you feel %s\n", secondResponse, emotion);
        //Delay
        sleep(2);
        printf("Is their anything else?\n");
        printf("\n");
       
        //Getting third response
        char thirdResponse[BUFFER_SIZE];
        do {
            fgets(thirdResponse, sizeof(thirdResponse), stdin); //Sets buffer for thirdResponse to the size of memory allocated for the thirdResponse, then grabs input with stdnin
            thirdResponse[strcspn(secondResponse, "\n")] = '\0'; //Searches through secondResponse to see if their is a newline character, if so replaces with \0
        } while(strcmp(thirdResponse, "") == 0);
        
        //Checking to see if answer was no,
        for(int i = 0; i < sizeof(no) / sizeof(no[0]); i++){
            if(strstr(thirdResponse, no[i]) != NULL){
                printf("\n");
                printf("Ok, im sorry that you feel that way. I hope we can talk again when you feel better");
                printf(" \n");
                return 0;
            }
        }
        
        
        //Ending conversation regardless of user input
        printf("\n");
        printf("Well thats unfortunate, but I have to go. I hope we can talk again when you feel better\n");
  
        
        //Ending app
        return 0;
        
    } else {
        //If first string doesnt make sense for how they're feeling say:
        printf("\n");
        printf("I dont know how to respond to that, Ill have to talk to you later.\n");
        printf("\n");
        return 1;
    }
    return 0;
}

