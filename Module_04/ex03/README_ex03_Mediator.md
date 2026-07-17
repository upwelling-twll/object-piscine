# Module_04 - Exercise 03 — Mediator

**Purpose**
- Decouple direct peer-to-peer communication between participants (professors, students, rooms, secretary) by introducing a central coordinator (`Headmaster`).

**Where**
- Key file(s): `ex03/people/Headmaster.*`, `ex03/people/Professor.*`, `ex03/people/Student.*`, `ex03/rooms/*`, `ex03/singletons.hpp`.

**Implementation summary**
- `Headmaster` is implemented as the mediator/coordinator:
  - Orchestrates class flow: collects `Professor` and `Student` lists from `SingleList<T>` singletons and instructs professors and students to prepare/attend classes.
  - Receives and processes `Form` objects, signs and executes them, and moves executed forms to the secretary archive.
- Participants (professors, students, secretary) don't modify each other directly; they ask the `Headmaster` to perform global actions or request resources (e.g., new classroom creation).

**Sequence (example: launching classes)**
1. `Headmaster::conductClasses()` reads the registered staff and student lists from the `SingleList<T>` singletons.
2. The `Headmaster` tells each `Professor` to `prepareForClass()` and each `Student` to `prepareForClass()`.
3. Professors/Students interact with `Room` instances but use `Headmaster` for requests like creating new courses or rooms.

**Schema (class view)**

Headmaster (Mediator)
- + receiveForm(Form*)
- + conductClasses()
- + ringBell()

Participants (Colleagues)
- Professor
- Student
- Secretary
- Rooms

Links
- `Headmaster` ↔ `Professor`, `Student` (commands/calls)
- `Professor`/`Student` ↔ `Room` (domain interaction) but resource requests route through `Headmaster`.

**Why this fits Mediator**
- `Headmaster` centralizes complex coordination so peers are simpler and decoupled.
- Reduces direct dependencies among `Professor`, `Student`, `Secretary`, and room types.

**Notes**
- `SingleList<T>` singletons are used to discover colleagues; `Headmaster` then invokes methods on them.
- Ownership and lifetime are still manual in this exercise (raw pointers), so care is required when passing pointers between mediator and colleagues.

---
