#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10
#define MAX_QUESTION_LENGTH 100
#define MAX_ANSWER_LENGTH 50

typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char options[4][MAX_ANSWER_LENGTH];
    int correctOption;
} QuizQuestion;

void printQuestion(QuizQuestion question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; ++i) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
    printf("Enter your answer (1-4): ");
}

int main() {
    QuizQuestion questions[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Berlin", "Paris", "Madrid", "Rome"}, 2},
        {"Which planet is known as the Red Planet?", {"Venus", "Mars", "Jupiter", "Saturn"}, 2},
        {"Who wrote 'Romeo and Juliet'?", {"Charles Dickens", "William Shakespeare", "Jane Austen", "Mark Twain"}, 2},
        {"What is the largest mammal on Earth?", {"Elephant", "Blue Whale", "Giraffe", "Hippopotamus"}, 2},
        {"In which year did World War II end?", {"1943", "1945", "1947", "1950"}, 2},
        {"Which country is known as the Land of the Rising Sun?", {"China", "Japan", "South Korea", "Vietnam"}, 2},
        {"Who is the author of 'To Kill a Mockingbird'?", {"Harper Lee", "F. Scott Fitzgerald", "Mark Twain", "J.K. Rowling"}, 1},
        {"What is the currency of Brazil?", {"Peso", "Euro", "Dollar", "Real"}, 4},
        {"Which element has the chemical symbol 'O'?", {"Oxygen", "Osmium", "Omnium", "Oregano"}, 1},
        {"What is the longest river in the world?", {"Nile", "Amazon", "Yangtze", "Mississippi"}, 2}
    };

    int score = 0;

    printf("Welcome to the Quiz Game!\n");

    for (int i = 0; i < MAX_QUESTIONS; ++i) {
        printQuestion(questions[i]);

        int userAnswer;
        scanf("%d", &userAnswer);

        if (userAnswer >= 1 && userAnswer <= 4) {
            if (userAnswer == questions[i].correctOption) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is: %d. %s\n", questions[i].correctOption,
                       questions[i].options[questions[i].correctOption - 1]);
            }
        } else {
            printf("Invalid answer. Please enter a number between 1 and 4.\n");
            i--; // Decrement i to repeat the same question
        }
    }

    printf("\nQuiz completed!\n");
    printf("Your final score: %d out of %d\n", score, MAX_QUESTIONS);

    return 0;
}