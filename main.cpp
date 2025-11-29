// ------------- FILE HEADER -------------
// Author ✅: Phoenix Morgan
// Assignment ✅: 8
// Date ✅: 11/26/25
// Citations: zybooks chapter 8


// ------------- ZYBOOKS SCORES -------------
// Chapter ✅: 8
// Participation ✅: 
// Challenge ✅:
// Labs ✅: 100%


// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count ✅:
// Links (Optional): 


// ------------- DESIGN DOCUMENT -------------
// A. INPUT ✅: 
// B. OUTPUT ✅:
// C. CALCULATIONS ✅:
// D. LOGIC and ALGORITHMS ✅:
//    (Optional) flow chart link or file name: 


// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS ✅: 
// (Optional) Additional tests count:   


// ------------- CODE -------------
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

// Function prototypes
void welcome();
int readInt(string prompt);
void readScore(string prompt, double &num);
double assignAverage(int numAssigns);
void getInput(double &midtermScore, double &finalExamScore);
double calcFinalScore(double assignAvg, double midterm, double finalExam);
void calcLetterGrade(double finalScore, char &letter);

const double ASSIGN_WEIGHT = 0.6;
const double MIDTERM_WEIGHT = 0.2;
const double FINAL_WEIGHT = 0.2;

int main() {
    welcome();

    int numAssignments = readInt("Enter the number of assignments (0 to 10): ");

    double assignAvg = assignAverage(numAssignments);

    double midtermScore = 0.0;
    double finalExamScore = 0.0;
    getInput(midtermScore, finalExamScore);

    double finalScore = calcFinalScore(assignAvg, midtermScore, finalExamScore);

    char letter = 'F';
    calcLetterGrade(finalScore, letter);

    cout << fixed << setprecision(1);
    cout << "Your Final Numeric score is " << finalScore << endl;
    cout << "Your Final Grade is " << letter << endl;
    cout << "Thank you for using my Grade Calculator!" << endl;

    return 0;
}

// Function definitions

void welcome() {
    cout << "Welcome to my Final Grade Calculator!" << endl;
    cout << "Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!" << endl;
    cout << "The number of assignments must be between 0 and 10." << endl;
    cout << "All scores entered must be between 0 and 4." << endl;
}

int readInt(string prompt) {
    int value;
    bool valid;

    do {
        cout << prompt;
        cin >> value;

        valid = true;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valid = false;
        }

        if (valid && (value < 0 || value > 10)) {
            valid = false;
        }

        if (!valid) {
            cout << "Illegal Value! Please try again!!" << endl;
        }

    } while (!valid);

    return value;
}

void readScore(string prompt, double &num) {
    bool valid;

    do {
        cout << prompt;
        cin >> num;

        valid = true;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valid = false;
        }

        if (valid && (num < 0.0 || num > 4.0)) {
            valid = false;
        }

        if (!valid) {
            cout << "Illegal Score! Please try again!" << endl;
        }

    } while (!valid);
}

double assignAverage(int numAssigns) {
    if (numAssigns == 0) {
        return 0.0;
    }

    double sum = 0.0;
    double score = 0.0;

    for (int i = 1; i <= numAssigns; i++) {
        string prompt = "Enter score " + to_string(i) + ": ";
        readScore(prompt, score);
        sum += score;
    }

    return sum / numAssigns;
}

void getInput(double &midtermScore, double &finalExamScore) {
    readScore("Enter your midterm exam score: ", midtermScore);
    readScore("Enter your final exam score: ", finalExamScore);
}

double calcFinalScore(double assignAvg, double midterm, double finalExam) {
    return assignAvg * ASSIGN_WEIGHT +
           midterm * MIDTERM_WEIGHT +
           finalExam * FINAL_WEIGHT;
}

void calcLetterGrade(double finalScore, char &letter) {
    if (finalScore >= 3.3 && finalScore <= 4.0) {
        letter = 'A';
    }
    else if (finalScore >= 2.8 && finalScore < 3.3) {
        letter = 'B';
    }
    else if (finalScore >= 2.0 && finalScore < 2.8) {
        letter = 'C';
    }
    else if (finalScore >= 1.2 && finalScore < 2.0) {
        letter = 'D';
    }
    else {
        letter = 'F';
    }
}

// Function implementations (if any)


// ------------- DESIGN -------------
/* 
Program Name: Grade calculator.

Program Description: This program will take the number of assignments and scores of a user
and calculate their final letter grade for the course. 

Design:
A. INPUT
Define the input variables including name data type. 
int num
int value
int midtermScore
int finalExamScore


B. OUTPUT
Define the output variables including data types. 
double finalScore
char letter

C. CALCULATIONS
Describe calculations used by algorithms in step D.  
List all formulas. 
If there are no calculations needed, state there are no calculations.

assignAvg * ASSIGN_WEIGHT +
midterm * MIDTERM_WEIGHT +
finalExam * FINAL_WEIGHT;

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts. 
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs. 
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt
DECLARE Integer numAssignments
DECLARE Double assignAvg
DECLARE Double midtermScore
DECLARE Double finalExamScore
DECLARE Double finalScore
DECLARE Char letter

CALL welcome

SET numAssignments = readInt("Enter the number of assignments (0 to 10): ")

SET assignAvg = assignAverage(numAssignments)

CALL getInput(midtermScore, finalExamScore)

SET finalScore = calcFinalScore(assignAvg, midtermScore, finalExamScore)

SET letter = 'F'
CALL calcLetterGrade(finalScore, letter)

DISPLAY "Your Final Numeric score is ", finalScore
DISPLAY "Your Final Grade is ", letter
DISPLAY "Thank you for using my Grade Calculator!"

END PROGRAM

FUNCTION Void welcome()
   DISPLAY "Welcome to my Final Grade Calculator!"
   DISPLAY "Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!"
   DISPLAY "The number of assignments must be between 0 and 10."
   DISPLAY "All scores entered must be between 0 and 4."
END FUNCTION

FUNCTION Integer readInt(String prompt)
   DECLARE Integer value
   DECLARE Boolean valid

   DO
      DISPLAY prompt
      INPUT value
      SET valid = true

      IF input for value is invalid THEN
         CLEAR the invalid input
         SET valid = false
      END IF

      IF valid AND (value < 0 OR value > 10) THEN
         SET valid = false
      END IF

      IF NOT valid THEN
         DISPLAY "Illegal Value! Please try again!!"
      END IF
   WHILE valid == false

   RETURN value
END FUNCTION

FUNCTION Void readScore(String prompt, REF Double num)
   DECLARE Boolean valid

   DO
      DISPLAY prompt
      INPUT num
      SET valid = true

      IF input for num is invalid THEN
         CLEAR the invalid input
         SET valid = false
      END IF

      IF valid AND (num < 0.0 OR num > 4.0) THEN
         SET valid = false
      END IF

      IF NOT valid THEN
         DISPLAY "Illegal Score! Please try again!"
      END IF
   WHILE valid == false
END FUNCTION

FUNCTION Double assignAverage(Integer numAssigns)
   IF numAssigns == 0 THEN
      RETURN 0.0
   END IF

   DECLARE Double sum
   DECLARE Double score
   DECLARE Integer i

   SET sum = 0.0
   SET score = 0.0

   FOR i = 1 TO numAssigns
      DECLARE String prompt
      SET prompt = "Enter score " + i + ": "
      CALL readScore(prompt, score)
      SET sum = sum + score
   END FOR

   RETURN sum / numAssigns
END FUNCTION

FUNCTION Void getInput(REF Double midtermScore, REF Double finalExamScore)
   CALL readScore("Enter your midterm exam score: ", midtermScore)
   CALL readScore("Enter your final exam score: ", finalExamScore)
END FUNCTION

FUNCTION Double calcFinalScore(Double assignAvg, Double midterm, Double finalExam)
   DECLARE Double result

   SET result = assignAvg * ASSIGN_WEIGHT +
                midterm * MIDTERM_WEIGHT +
                finalExam * FINAL_WEIGHT

   RETURN result
END FUNCTION

FUNCTION Void calcLetterGrade(Double finalScore, REF Char letter)
   IF finalScore >= 3.3 AND finalScore <= 4.0 THEN
      SET letter = 'A'
   ELSE IF finalScore >= 2.8 AND finalScore < 3.3 THEN
      SET letter = 'B'
   ELSE IF finalScore >= 2.0 AND finalScore < 2.8 THEN
      SET letter = 'C'
   ELSE IF finalScore >= 1.2 AND finalScore < 2.0 THEN
      SET letter = 'D'
   ELSE
      SET letter = 'F'
   END IF
END FUNCTION



SAMPLE RUNS
Copy from assignment document.
Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 6
Enter score 1: 3.4 
Enter score 2: 4 
Enter score 3: 2.5 
Enter score 4: 3.3
Enter score 5: 3.1
Enter score 6: 2.5
Enter your midterm exam score: 3.5
Enter your final exam score: 4
Your Final Numeric score is 3.4
Your Final Grade is A
Thank you for using my Grade Calculator!


Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 3
Enter score 1: 3 
Enter score 2: 4 
Enter score 3: 2.5 
Enter your midterm exam score: 2.5
Enter your final exam score: 2
Your Final Numeric score is 2.8
Your Final Grade is B
Thank you for using my Grade Calculator!


Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 12
Illegal Value! Please try again!!
Enter the number of assignments (0 to 10): 5
Enter score 1: 3.4 
Enter score 2: 4 
Enter score 3: 2.5 
Enter score 4: 5.5
Illegal Score! Please try again!
Enter score 4: 3.5
Enter score 5: 3.1
Enter your midterm exam score: 3.5
Enter your final exam score: 4
Your Final Numeric score is 3.5
Your Final Grade is A
Thank you for using my Grade Calculator!
*/