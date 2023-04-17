# Very simple chatbot

Hello, this is a very basic project that I decided to make while learing another programming language,
I heard about the ELIZA psychotherapist chatbot made in the 60's and decided I wanted to make a very basic six question version of the chatbot.
I also wanted to learn C, so I thought instead of watching/reading a bunch of boring tutorials, why not actually make a project while learning the language.

# Whats in it?

This project has most of the basic programming concepts in them, because I was using this project as a way of learning C
So nothing too fancy like NLP, or tokenizing strings.

# How does it work?

Its a mixture of string analysis, manipulation, and feeding the user back with what they said.
 
The code uses various predefined arrays of keywords and responses to determine the emotion expressed by the user's input.

Here's how the program works:

I defined arrays of positive and negative keywords and responses, as well as additional extra positive and extra negative keywords and responses.
Ive initialized boolean variables to help keep track of the user's emotion.
It use loops and string manipulation functions to check if the user's input contains any of the predefined positive or negative keywords, and sets the corresponding boolean variables accordingly.
If the keywords are positive, it will jump down the positive route and the chatbots responses will be more happy, whereas if they are negative then it will jump down the negative route.

For example, if the user says "Im good", the chatbot will respond with "Why are you feeling good", and so on, else if the user says something like "Im sad",  the chatbot will respond with 
"Whats wrong, why are you feeling sad." __Depending on the emotion detected it will asks and phrase questions and responses differently.

Then the program prompts the user for a response to other questions, based on the emotion detected.
It then uses another loop to ensure that the user provides a non-empty response, so the code doesnt jump ahead and the user has time to answer.
It then string manipulation functions to remove any of the predefined keywords from the user's response in order to make the chatbot's response more grammatically sound.
Then it generates a response based on the user's input and emotion, and then displays its response to the user
It repeats the process of prompting for a response, analyzing it, and generating a response until the user provides an empty response.
Then after all questions have been answered the program ends.

_For a more precise view of how certain things work, read the many comments I left behind
