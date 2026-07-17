# Disclaimers for 42 students

This module was developed based on subject **version 1.01**, which leaves a lot of freedom and is not always clear in specific cases. The architecture is built on my assumptions; some choices made the design more complex, but they also produced a natural and realistic flow (hopefully).

- ex00–ex05: `Room` is a strange class defined in `datas.cpp`, but it is never explicitly mentioned in the evaluation sheet (summer 2026) or the subject text. In ex04 and ex05, I move students and staff between classrooms and offices for each break, lunch, and graduation ceremony. Therefore, people move between rooms only in these last two exercises.

- ex00–ex05: `HeadmasterOffice` and `SecretaryOffice` are used only in ex04 and ex05. In the `School` constructor, the Headmaster and Secretary are placed in their respective offices and leave them for events. `SecretaryOffice` is also used as an archive: after the Headmaster executes a form, the form is sent to the Secretary, which forwards it to `SecretaryOffice` (if it is not already there) and adds it to the archive. The archive is destroyed with `SecretaryOffice` destructor, which frees all pointers allocated for forms.

- ex02–ex05: My form flow is: a student needs a course → the student requests a form from the Headmaster → the Headmaster requests the form from the Secretary → the Headmaster receives the form → the Headmaster sends the form to the student → the student fills the form using getters and setters → the student returns the form to `Headmaster::receiveForm()` for signing and execution.

- ex02: When a form is sent to the requester (student or professor) to be filled, the requester receives it in `main.cpp`, fills it with data, and sends it back to the Headmaster.

- ex02: When a student finishes all classes required by a course (`Course::classesToGraduate`), they graduate only from that course and then search for a new one.

- ex05: When a student finishes all classes required by a course, they graduate only from that course, their level increases by 1, and they search for a new course. During graduation ceremony, all students arrive in a specific room. The Headmaster chooses only students with the required grade level for final graduation. Graduates receive `isGraduate = true`. After the ceremony ends, all students leave the room. Finally, the school unsubscribes graduates from courses they did not finish and removes them from the relevant lists and vectors.

- ex03–ex05: `CourseBlueprint` is used to fill `NeedCourseCreationForm`. When a professor needs a new course, they check if any course in `CourseBlueprint` is not already created by comparing the blueprint list with existing courses in `CourseList::SingleList`. If an unused course is found, that data is used to fill the form; otherwise the professor cannot create a new course, or (in older versions) will create a `Dancing` course.

- ex03–ex05: when Student needs to `SubscribeStudentToCourse` they checks for an unattended course from `CourseList::SingleList`, starting from a random index. This makes the school use more courses and avoids strictly sequential graduation order, testing of the program becomes more entertaining.

- ex04: The subject table says "Files to turn in: <...> ex04/observer.hpp". In C++ Observer pattern theory resources, the observer is the subscriber for events while the subject handles events. The subject stores state and a list of observers to notify when that state changes. From this point of view, `observer.hpp` is not necessary because all `Staff` and `Student` instances observe `Bell`. Therefore my implementation uses `IPerson` as the observer interface, while `Bell` is the subject.

# Ideas

- ex00–ex05: `HeadmasterOffice` and `SecretaryOffice` can be used like real offices. When a student or staff member needs to work with forms, they go to the appropriate room:
  - students and professors go to `HeadmasterOffice` for `Headmaster::requestForm()`, `Headmaster::receiveForm()`, etc.
  - the Headmaster goes to `SecretaryOffice` for `Secretary::createForm()`, `Secretary::archiveForm()`, and other form-related operations and returns back to HeadmaterOffice to do thir own job.


# Module 04 — Design Patterns in Hogwarts School

This module demonstrates six fundamental design patterns through a school simulation system. Each exercise implements specific patterns and shows how they work together.

## Exercises & Patterns

### [Exercise 01 — Singleton](README_ex01_Singleton.md)
**Pattern**: Singleton  
**Concept**: Centralized, globally accessible instances of collections.  
**Key Class**: `SingleList<T>` — manages a single static container per type (students, staff, courses, rooms).

---

### [Exercise 02 — Factory & Command](README_ex02_Factory_Command.md)
**Patterns**: Factory, Command  
**Concepts**:
- **Factory**: `Secretary::createForm()` centralizes form object creation.
- **Command**: `Form` represents actions that can be signed and executed by the `Headmaster`.

**Key Classes**: `Secretary` (factory), `Form` hierarchy, `Headmaster` (invoker/receiver).

---

### [Exercise 03 — Mediator](README_ex03_Mediator.md)
**Pattern**: Mediator  
**Concept**: `Headmaster` orchestrates interactions between participants (professors, students, secretary, rooms).  
**Key Class**: `Headmaster` — centralizes coordination and eliminates direct peer-to-peer coupling.

---

### [Exercise 04 & 05 — Observer & Facade](README_ex04-05_Observer_Facade.md)
**Patterns**: Observer, Facade

#### Observer (ex04)
- `Bell` is the subject; `IPerson` observers react to break events.
- `Student`, `Staff` implement `update(Break)` and move between rooms (courtyard/dining/staff rest) based on break type.

#### Facade (ex05)
- `School` provides a high-level API hiding subsystem complexity.
- Orchestrates `Headmaster`, `Secretary`, `Bell`, rooms, and participants.
- Methods like `runDayRoutine()` and `requestRingBell()` simplify client interaction.

**Key Classes**: `Bell` (subject), `IPerson` (observer interface), `School` (facade).

---

## Key Relationships

```
School (Facade)
├── Headmaster (Mediator)
├── Secretary (Factory)
├── Bell (Subject)
│   └── IPerson observers (Student, Staff)
└── SingleList<T> (Singleton)
    ├── SingleList<Student>
    ├── SingleList<Staff>
    ├── SingleList<Professor>
    ├── SingleList<Course>
    └── SingleList<Room>
```

## Ownership & Memory Management

- **Historical approach (ex01-ex04)**: Raw pointers with documented ownership transfer (Factory → Headmaster → Archive).
- **Modern approach (ex05)**: `std::unique_ptr` for archives to eliminate double-free and leak risks.

Each README explains the ownership model and pitfalls relevant to that exercise.

---

## Notes on this module

 How patterns combine:
   - `SingleList` (Singleton) provides global discovery
   - `Secretary` (Factory) creates `Form` objects
   - `Form` (Command) encapsulates actions like subscribing students to courses, adding rooms, adding new courses, graduating students, assigning professors to courses
   - `Headmaster` (Mediator) coordinates participants
   - `Bell` (Observer) notifies participants of events like breaks, lunch, graduation ceremony
   - `School` (Facade) provides simple public interface to run day routine, recrute people, graduate students


---
