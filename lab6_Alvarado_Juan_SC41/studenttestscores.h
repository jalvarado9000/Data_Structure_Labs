#ifndef STUDENTTESTSCORES_H
#define STUDENTTESTSCORES_H
#include <string>
using namespace std;

const double DEFAULT_SCORE = 0.0;//global variable

class StudentTestScore
{
private:
	string studentName;	//The student's name
	double* testScores; //Point to array of test scores
	int numTestScores;	//Number of test scores

	// Private member function to create an
	// array of test scores.
	void createTestScoresArray(int size)
	{
		numTestScores = size;
		testScores = new double[size];
		for (int i = 0; i < size; i++)
			testScores[i] = DEFAULT_SCORE;
	}

public:
	// Constructor
	StudentTestScore(string name, int numScore)
	{
		studentName = name;
		createTestScoresArray(numScore);
	}

	// Copy constructor
	// YOU MUST IMPLEMENT THIS FUNCTION
	StudentTestScore(const StudentTestScore& obj)
	{
	    //copying the studentName object
		studentName = obj.studentName;    \
		//creates a new class array
       createTestScoresArray(obj.numTestScores);

       //copies the content from the old array to the new array.
       for(int i = 0;i<numTestScores;i++)
        testScores[i] = obj.testScores[i];
	}

	// Destructor
	// YOU MUST IMPLEMENT THIS FUNCTION
	~StudentTestScore()
	{
	    //deletes the array
		delete [] testScores;
	}

	// The setTestScore function sets a specific
	// test score's value.
	void setTestScore(double score, int index)
	{
		testScores[index] = score;
	}

	// Set the student's name.
	void setStudentName(string name)
	{
		studentName = name;
	}

	// Get the student's name.
	string getStudentName() const
	{
		return studentName;
	}

	// Get the number of test scores.
	int getNumTestScores() const
	{
		return numTestScores;
	}

	// Get a specific test score.
	double getTestScore(int index) const
	{
		return testScores[index];
	}

	// Overloaded = operator
	// YOU MUST IMPLEMENT THIS FUNCTION
	const StudentTestScore operator=(const StudentTestScore& right)
	{
		 //checks if the object being assingn is not the same
       if(this != &right){

          //if no t copies the new values
         studentName = right.studentName;
         numTestScores = right.numTestScores;

         //deletes the current array
         delete [] testScores;
         //creates a new array
         testScores = new double[numTestScores];

         //copy array content
         for(int i = 0;i<numTestScores;i++)
          testScores[i] = right.testScores[i];
       }
       return *this;

	}
};
#endif
