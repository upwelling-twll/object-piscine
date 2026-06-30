#include "FormType.hpp"
#include "courses/Course.hpp"
#include "forms/forms.hpp"
#include "people/people.hpp"
#include "rooms/rooms.hpp"
#include "singletons.hpp"
#include "Debug.hpp"

#include <iostream>

void testMediator()
{
    Student harry("Harry");
    Student hermione("Hermione");
    Student ron("Ron");

    // Staff filch("Argus");
    // Staff norris("Ms Norris🐾");
    // Staff hagrid("Rubeus");
    Professor mcGonagall("Minerva");
    Headmaster dumblerode("Albus");
    Secretary sec("Percy Weasley");
    dumblerode.setSecretary(&sec);

    Course potions("Potions", 100, 30);
    Course transfiguration("Transfiguration", 1, 20);
    Course herbology("Herbology", 50, 15);

    HeadmasterOffice hmoffice;
    SecretarialOffice soffice;
    Classroom   potionsClass;
    Classroom*   transfigurationClass = new Classroom();
    Classroom   greenhouse;
    // Room        roomofrequirement;

    SingleList<Student>& students = SingleList<Student>::getSingleList();
    SingleList<Course>& courses = SingleList<Course>::getSingleList();
    SingleList<Staff>& staff = SingleList<Staff>::getSingleList();
    SingleList<Room>& rooms = SingleList<Room>::getSingleList();

    students.add(&harry);
    students.add(&hermione);
    students.add(&ron);

    // staff.add(&filch);
    // staff.add(&norris);
    staff.add(&dumblerode);
    staff.add(&mcGonagall);

    courses.add(&potions);
    courses.add(&transfiguration);
    courses.add(&herbology);

    rooms.add(&hmoffice);
    rooms.add(&soffice);
    rooms.add(&potionsClass);
    rooms.add(transfigurationClass);
    rooms.add(&greenhouse);
    // rooms.add(&roomofrequirement);

    LOG_INFO(*(students.get(0)));
    // std::cout << *(students.get(1)) << std::endl;
    // std::cout << *(students.get(2)) << std::endl;

    // std::cout << *(staff.get(0)) << std::endl;
    // std::cout << *(staff.get(1)) << std::endl;
    // std::cout << *(staff.get(2)) << std::endl;

    // std::cout << *(courses.get(0)) << std::endl;
    // std::cout << *(courses.get(1)) << std::endl;
    // std::cout << *(courses.get(2)) << std::endl;

    std::cout << *(rooms.get(0)) << std::endl;
    std::cout << *(rooms.get(1)) << std::endl;
    std::cout << *(rooms.get(2)) << std::endl;

    std::cout << "=== Test Meadiator ===" << std::endl;

    LOG_DBUG("Staff list size: " + std::to_string(StaffList::getSingleList().getSize()));
    mcGonagall.setHeadmaster(&dumblerode);
    mcGonagall.assignCourse(&transfiguration);
    transfiguration.assign(&mcGonagall);
    harry.addCourse(&transfiguration);
    hermione.addCourse(&transfiguration);
    
    transfiguration.subscribe(&harry);
    transfiguration.subscribe(&hermione);

    // transfiguration.setClassroom(transfigurationClass);
    // transfigurationClass->assignCourse(&transfiguration);
    LOG_INFO(transfiguration);
    dumblerode.launchCourses();

    LOG_INFO("Harry attended transfiguration " + std::to_string(harry.getAttendance(&transfiguration)) + " times");
    dumblerode.launchCourses();
    // dumblerode.launchCourses();
    LOG_INFO("Harry attended transfiguration " + std::to_string(harry.getAttendance(&transfiguration)) + " times");

} 

int main()
{
    testMediator();
    return (0);
}