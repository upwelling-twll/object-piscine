#include "FormType.hpp"
#include "courses/Course.hpp"
#include "forms/forms.hpp"
#include "people/people.hpp"
#include "rooms/rooms.hpp"
#include "singletons.hpp"
#include "Debug.hpp"

#include <iostream>

void testFactory()
{
    std::cout << "=== Test factory ===" << std::endl;
    Secretary sec("Percy Weasley");
   
    time_t et = time(0) + (3600 * 24); //24 hours from now
    Form* newForm = sec.createForm(FormType::NeedCourseCreation, et);
    NeedCourseCreationForm* f = dynamic_cast<NeedCourseCreationForm*>(newForm);
    LOG_INFO(*f);
    delete newForm;
    
}

void testCommand()
{
    std::cout << "=== Test command ===" << std::endl;
    Secretary sec("Percy Weasley");
    Student harry("Potter");
    StudentList::getSingleList().add(&harry);
   
    std::cout << " --- Need Course Creation Form --- " << std::endl;
    time_t et = time(0) + (3600 * 24); //24 hours from now
    Form* newForm = sec.createForm(FormType::NeedCourseCreation, et);
    NeedCourseCreationForm* f = dynamic_cast<NeedCourseCreationForm*>(newForm);
    f->setCourseName("Transfiguration"); 
    f->setNumberOfStudents(10);
    f->setClassesToGraduate(5);

    LOG_INFO(*f);
    Headmaster hm("Dumbledor");
    hm.receiveForm(f);
    hm.sign(f);
    hm.execute(f);
    LOG_INFO(*(CourseList::getSingleList().get(0)));
    delete newForm;


    std::cout << "\n --- Course Finished Form --- " << std::endl;
    Form* finishForm = sec.createForm(FormType::CourseFinished, et);
    CourseFinishedForm* ff = dynamic_cast<CourseFinishedForm*>(finishForm);
    ff->setCourse(CourseList::getSingleList().get(0));
    LOG_INFO(*ff);
    hm.receiveForm(ff);
    hm.sign(ff);
    hm.execute(ff);
    delete finishForm;

    std::cout << "\n --- Need Room Form --- " << std::endl;
    Form* roomForm = sec.createForm(FormType::NeedMoreClassRoom, et);
    NeedMoreClassRoomForm* rf = dynamic_cast<NeedMoreClassRoomForm*>(roomForm);
    LOG_INFO(*rf);
    hm.receiveForm(rf);
    hm.sign(rf);
    hm.execute(rf);
    LOG_INFO(*(RoomList::getSingleList().get(0)));
    delete roomForm;

    std::cout << "\n --- Subscribe Student To Course Form --- " << std::endl;
    Form* subscribeForm = sec.createForm(FormType::SubscriptionToCourse, et);
    SubscriptionToCourseForm* sf = dynamic_cast<SubscriptionToCourseForm*>(subscribeForm);
    LOG_INFO(*sf);
    sf->setCourse(CourseList::getSingleList().get(0));
    sf->setStudent(&harry);
    hm.receiveForm(sf);
    hm.sign(sf);
    hm.execute(sf);
    LOG_INFO(*(StudentList::getSingleList().get(0)));
    delete subscribeForm;

    int clsize = CourseList::getSingleList().getSize();
    for (int i = 0; i < clsize; ++i)
    {
        Course* c = CourseList::getSingleList().get(0);
        CourseList::getSingleList().remove(c);
        delete(c);
    }
    
    int rlsize = RoomList::getSingleList().getSize();
    for (int i = 0; i < rlsize; ++i)
    {
        Room* r = RoomList::getSingleList().get(0);
        RoomList::getSingleList().remove(r);
        delete(r);
    }
}

int main()
{
    testFactory();
    testCommand();
    return (0);
}