#include "people/Student.hpp"
#include "people/Staff.hpp"
#include "object/Course.hpp"
#include "rooms/Room.hpp"
#include "singleton.hpp"


int main()
{
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
    COurse herbology("Herbology", 50, 15);

    HeadmasterOffice hmoffice(1);
    SecretarialOffice soffice(2);
    Classroom   potionsClass(3);
    Classroom   transfigurationClass(4);
    Classroom   greenhouse(5);
    Room        roomofrequirement(6);

    SingleList students = getSingleList(Student);
    SingleList courses = getSingleList(Course);
    SingleList staff = getSingleList(Staff);
    SingleList rooms = getSingleList(Room);

    students.add(harry);
    students.add(hermione);
    students.add(ron);

    staff.add(filch);
    staff.add(norris);
    staff.add(hagrid);
    staff.add(mcGonagall);

    courses.add(potions);
    courses.add(transfiguration);
    courses.add(herbology);

    rooms.add(hmoffice);
    rooms.add(soffice);
    rooms.add(potionsClass);
    rooms.add(transfigurationClass);
    rooms.add(greenhouse);
    rooms.add(roomofrequirement);











}