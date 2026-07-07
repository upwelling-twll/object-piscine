#ifndef SCHOOL_HPP
# define SCHOOL_HPP

# include <iostream>

class School
{
private:
    Headmaster*			_hm;
	const std::string	_schoolName;


public:
	/*Member functions*/
    void runDayRoutine();
	void launchClasses(); //Make the headmaster ask the students and professors to attend them classes
	void requestRingBell(); //Make the headmaster ring the bell
	void recruteProfessor(); //Add a new professor to the school
	void recruteStudent(); // Add a new student to the school
	Course* getCourse(std::string p_name);//return a course with a given name
	std::vector<Student*> getStudents();//return a vector containing every student in school
	std::vector<Professor*> getProfessors(); //return a vector containing every professor in school
	Headmaster getHeadmaster(); //return the headmaster of the school
	Secretary getSecretary(); // return the secretary of the school
	void graduationCeremony(); //launch the graduation of every student that can graduate at a desired moment
*/

	/*Getters and Setters*/

	/*Constructors*/
    School(std::string name);

	/*Destructors*/
    ~School( void );

	/*Overload operators*/
	School &operator=(const School& src);
};

#endif // SCHOOL_HPP
