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

    Course potions("Potions", 100, 0);
    Course transfiguration("Transfiguration", 1, 0);
    Course herbology("Herbology", 50, 0);

    HeadmasterOffice hmoffice;
    SecretarialOffice soffice;
    Classroom   potionsClass;
    // Classroom*   transfigurationClass = new Classroom();
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
    // rooms.add(transfigurationClass);
    rooms.add(&greenhouse);
    // rooms.add(&roomofrequirement);

    LOG_INFO(*(students.get(0)));
    // std::cout << *(students.get(1)) << std::endl;
    // std::cout << *(students.get(2)) << std::endl;

    std::cout << *(rooms.get(0)) << std::endl;
    std::cout << *(rooms.get(1)) << std::endl;
    std::cout << *(rooms.get(2)) << std::endl;

    std::cout << "=== Test Meadiator ===" << std::endl;

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

    int rsize = RoomList::getSingleList().getSize();
	for (int i = 0; i != rsize; i++)
	{
		Room* r = RoomList::getSingleList().get(0);
		RoomList::getSingleList().remove(r);
		// LOG_DBUG("DELETE: ");
		// LOG_DBUG((r));

		delete r;
	}
	int csize = CourseList::getSingleList().getSize();
	for (int i = 0; i != csize; i++)
	{
		Course* c = CourseList::getSingleList().get(0);
		CourseList::getSingleList().remove(c);
		// LOG_DBUG("DELETE: ");
		// LOG_DBUG((r));

		delete c;
	}
} 

int main()
{
    testObserver();
    return (0);
}