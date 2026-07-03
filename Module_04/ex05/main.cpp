#include "FormType.hpp"
#include "courses/Course.hpp"
#include "forms/forms.hpp"
#include "people/people.hpp"
#include "rooms/rooms.hpp"
#include "singletons.hpp"
#include "Debug.hpp"

#include <iostream>

void testObserver()
{
    SingleList<Student>& students = SingleList<Student>::getSingleList();
    SingleList<Course>& courses = SingleList<Course>::getSingleList();
    SingleList<Staff>& staff = SingleList<Staff>::getSingleList();
    SingleList<Room>& rooms = SingleList<Room>::getSingleList();

    Student harry("Harry");
    Student hermione("Hermione");
    Student ron("Ron");

    students.add(&harry);
    students.add(&hermione);
    students.add(&ron);

    Headmaster hm("Albus Dumblerode");
    Secretary sec("Percy Weasley");
    hm.setSecretary(&sec);

    Professor p1("Minerva McGonagall");
    Professor p2("Severus Snape");
    Professor p3("Filius Flitwick");
    Professor p4("Pomona Sprout");
    Professor p5("Remus Lupin");
    Professor p6("Rubeus Hagrid");

    p1.setHeadmaster(&hm);
    p2.setHeadmaster(&hm);
    p3.setHeadmaster(&hm);
    p4.setHeadmaster(&hm);
    p5.setHeadmaster(&hm);
    p6.setHeadmaster(&hm);

    staff.add(&hm);
    staff.add(&p1);
    staff.add(&p2);
    staff.add(&p3);
    staff.add(&p4);
    staff.add(&p5);
    staff.add(&p6);

    
    Course c1("Transfiguration", 100, 10);
    Course c2("Potions", 100, 10);
    Course c3("Charms", 100, 10);
    Course c4("Herbology", 50, 10);
    Course c5("Defense Against the Dark Arts", 100, 10);
    Course c6("Care of Magical Creatures", 50, 10);

    
    courses.add(&c1);
    courses.add(&c2);
    courses.add(&c3);
    courses.add(&c4);
    courses.add(&c5);
    courses.add(&c6);

    
    HeadmasterOffice hmoffice;
    SecretarialOffice soffice;
    Classroom   cr1;
    Classroom   cr2;
    
    // Classroom*   transfigurationClass = new Classroom();
    
    rooms.add(&hmoffice);
    rooms.add(&soffice);
    rooms.add(&cr1);
    rooms.add(&cr2);
    // rooms.add(transfigurationClass);
    
    // LOG_INFO(*(students.get(0)));
    // LOG_INFO(*(students.get(1)));
    // LOG_INFO(*(students.get(2)));
    
    LOG_INFO(*(rooms.get(0)));
    LOG_INFO(*(rooms.get(1)));
    LOG_INFO(*(rooms.get(2)));
    
    std::cout << "=== Test Facade ===" << std::endl;

    LOG_DBUG("Staff list size: " + std::to_string(StaffList::getSingleList().getSize()));
    
    cr1.assignCourse(&c1);
    cr2.assignCourse(&c2);
    LOG_INFO(c1);
    
    Bell bell;
    bell.attach(&harry);
    bell.attach(&hermione);
    bell.attach(&ron);
    bell.attach(&hm);
    bell.attach(&p1);
    bell.attach(&p2);
    bell.attach(&p3);
    bell.attach(&p4);
    bell.attach(&p5);
    bell.attach(&p6);

    hm.ringBell(&bell);
    
    hm.conductClasses();

    hm.ringBell(&bell);
    hm.ringBell(&bell);


} 

int main()
{
    testObserver();
    return (0);
}