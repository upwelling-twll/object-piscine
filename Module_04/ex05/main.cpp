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

    Headmaster dumblerode("Albus");
    Secretary sec("Percy Weasley");
    dumblerode.setSecretary(&sec);
    Professor mcGonagall("Minerva");
    
    staff.add(&dumblerode);
    staff.add(&mcGonagall);
    
    Course potions("Potions", 100, 10);
    Course transfiguration("Transfiguration", 1, 10);
    Course herbology("Herbology", 50, 10);
    
    courses.add(&potions);
    courses.add(&transfiguration);
    courses.add(&herbology);
    
    HeadmasterOffice hmoffice;
    SecretarialOffice soffice;
    Classroom   potionsClass;
    Classroom   greenhouse;
    // Classroom*   transfigurationClass = new Classroom();
    
    rooms.add(&hmoffice);
    rooms.add(&soffice);
    rooms.add(&potionsClass);
    rooms.add(&greenhouse);
    // rooms.add(transfigurationClass);
    
    // LOG_INFO(*(students.get(0)));
    // LOG_INFO(*(students.get(1)));
    // LOG_INFO(*(students.get(2)));
    
    LOG_INFO(*(rooms.get(0)));
    LOG_INFO(*(rooms.get(1)));
    LOG_INFO(*(rooms.get(2)));
    
    std::cout << "=== Test Facade ===" << std::endl;

    LOG_DBUG("Staff list size: " + std::to_string(StaffList::getSingleList().getSize()));
    
    potionsClass.assignCourse(&potions);
    greenhouse.assignCourse(&herbology);
    mcGonagall.setHeadmaster(&dumblerode);
    LOG_INFO(transfiguration);
    
    Bell bell;
    bell.attach(&harry);
    bell.attach(&hermione);
    bell.attach(&ron);
    bell.attach(&dumblerode);
    bell.attach(&mcGonagall);
    dumblerode.ringBell(&bell);
    
    dumblerode.conductClasses();

    dumblerode.ringBell(&bell);
    dumblerode.ringBell(&bell);


} 

int main()
{
    testObserver();
    return (0);
}