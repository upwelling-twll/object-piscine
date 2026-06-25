#include "people/people.hpp"
#include "objects/Course.hpp"
#include "forms/forms.hpp"
#include "rooms/rooms.hpp"
#include "singletons.hpp"
#include "Debug.hpp"
#include "FormType.hpp"


#include <iostream>

void testSingleton()
{
    std::cout << "=== Test singleton ===" << std::endl;
    Student harry("Harry");
    Student hermione("Hermione");
    Student ron("Ron");

    Staff filch("Argus");
    Staff norris("Ms Norris🐾");
    Staff hagrid("Rubeus");
    Professor mcGonagall("Minerva");
    Headmaster dumblerode("Albus");

    Course potions("Potions", 100, 30);
    Course transfiguration("Transfiguration", 50, 20);
    Course herbology("Herbology", 50, 15);

    HeadmasterOffice hmoffice(1);
    SecretarialOffice soffice(2);
    Classroom   potionsClass(3);
    Classroom   transfigurationClass(4);
    Classroom   greenhouse(5);
    Room        roomofrequirement(6);

    SingleList<Student>& students = SingleList<Student>::getSingleList();
    SingleList<Course>& courses = SingleList<Course>::getSingleList();
    SingleList<Staff>& staff = SingleList<Staff>::getSingleList();
    SingleList<Room>& rooms = SingleList<Room>::getSingleList();

    students.add(&harry);
    students.add(&hermione);
    students.add(&ron);

    staff.add(&filch);
    staff.add(&norris);
    staff.add(&hagrid);
    staff.add(&mcGonagall);

    courses.add(&potions);
    courses.add(&transfiguration);
    courses.add(&herbology);

    rooms.add(&hmoffice);
    rooms.add(&soffice);
    rooms.add(&potionsClass);
    rooms.add(&transfigurationClass);
    rooms.add(&greenhouse);
    rooms.add(&roomofrequirement);

    
   LOG_INFO(*(students.get(0)));
    // std::cout << *(students.get(1)) << std::endl;
    // std::cout << *(students.get(2)) << std::endl;

    // std::cout << *(staff.get(0)) << std::endl;
    // std::cout << *(staff.get(1)) << std::endl;
    // std::cout << *(staff.get(2)) << std::endl;

    // std::cout << *(courses.get(0)) << std::endl;
    // std::cout << *(courses.get(1)) << std::endl;
    // std::cout << *(courses.get(2)) << std::endl;

    // std::cout << *(rooms.get(0)) << std::endl;
    // std::cout << *(rooms.get(1)) << std::endl;
    // std::cout << *(rooms.get(2)) << std::endl;
}

void testFactory()
{
    std::cout << "=== Test factory ===" << std::endl;
    Secretary sec("Percy Weasley");
   
    time_t et = time(0) + (3600 * 24); //24 hours from now
    Form* newForm = sec.createForm(FormType::NeedCourseCreation, et);
    NeedCourseCreationForm* f = dynamic_cast<NeedCourseCreationForm*>(newForm);
    LOG_INFO(*f);

}

int main()
{
    testSingleton();
    testFactory();
    return (0);
}