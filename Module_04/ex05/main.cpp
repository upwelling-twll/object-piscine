#include "FormType.hpp"
#include "courses/Course.hpp"
#include "forms/forms.hpp"
#include "people/people.hpp"
#include "rooms/rooms.hpp"
#include "singletons.hpp"
#include "Debug.hpp"
#include "courses/CourseBlueprint.hpp"
#include "school/School.hpp"
#include <iostream>



void testFacade()
{
    std::cout << "=== Test Facade ===" << std::endl;
    
    School* hogwarts = new School("Hogwarts");
   
    Student harry("Harry");
    Student hermione("Hermione");
    Student ron("Ron");

    hogwarts->recruteStudent(&harry);
    hogwarts->recruteStudent(&hermione);
    hogwarts->recruteStudent(&ron);

    Professor p1("Minerva McGonagall");
    Professor p2("Severus Snape");
    Professor p3("Filius Flitwick");
    Professor p4("Pomona Sprout");
    Professor p5("Remus Lupin");
    Professor p6("Rubeus Hagrid");

   hogwarts->recruteProfessor(&p1);
   hogwarts->recruteProfessor(&p2);
   hogwarts->recruteProfessor(&p3);
   hogwarts->recruteProfessor(&p4);
   hogwarts->recruteProfessor(&p5);
   hogwarts->recruteProfessor(&p6);

   hogwarts->runDayRoutine();
   hogwarts->requestRingBell(Event::RingBell);
   hogwarts->graduationCeremony();
   hogwarts->runDayRoutine();

    delete hogwarts;
} 

int main()
{
    testFacade();


    return (0);
}