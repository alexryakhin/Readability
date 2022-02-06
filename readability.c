#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int getLettersCountFor(string s);
int getWordsCountFor(string s);
int getSentenceCountFor(string s);
float averageNumPerHundred(int number, int count);

int main(void) {
    // so there should be a programm that calculates read level of a given string

    // get the string from the user
    string text;
    text = get_string("Text: ");

    int strLn = strlen(text) -1;

    if (!ispunct(text[strLn])) {
        printf("Error. The sentence should have some sort of period sign.\n");
        return 1;
    }

    int lettersCount = getLettersCountFor(text);

    int wordsCount = getWordsCountFor(text);

    int sentencesCount = getSentenceCountFor(text);

    float L = averageNumPerHundred(lettersCount, wordsCount);

    float S = averageNumPerHundred(sentencesCount, wordsCount);

    // formula is
    // index = 0.0588 * L - 0.296 * S - 15.8

    float grade = 0.0588 * L - 0.296 * S - 15.8;

    // Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

    // check if grade < 0
    if (grade < 0) {
        printf("Before Grade 1\n");
    } else if (grade > 16) {
        printf("Grade 16+\n");
    } else {
        // print the grade back but rounded.
        printf("Grade %i\n", (int) round(grade));
    }
    return 0;
}

int getLettersCountFor(string s) {
    int count = 0;
    for (int i = 0, n = strlen(s); i < n; i++) {
        if isalpha(s[i]) {
            count ++;
        }
    }
    return count;
}

int getWordsCountFor(string s) {
    int count = 1;
    for (int i = 0, n = strlen(s); i < n; i++) {
        if (s[i] == ' ') {
            count ++;
        }
    }
    return count;
}

int getSentenceCountFor(string s) {
    int count = 0;
    for (int i = 0, n = strlen(s); i < n; i++) {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?') {
            count ++;
        }
    }
    return count;
}

float averageNumPerHundred(int number, int count) {
    float multiplier = 100 / (float) count;
    return number * multiplier;
}
