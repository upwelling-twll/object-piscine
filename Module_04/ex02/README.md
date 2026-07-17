# Module_04 - Exercise 02 — Factory & Command

**Purpose**
- `Factory`: centralize creation of concrete `Form` objects in one place (the `Secretary`).
- `Command`: represent actions (forms) as objects that can be signed and executed by the `Headmaster`.

**Where**
- Key file(s): `ex02/people/Secretary.cpp`, `ex02/forms/*`, `ex02/people/Headmaster.cpp`.

**Implementation summary**
- Factory
  - `Secretary::createForm(FormType, expiration)` returns a newly allocated `Form*` (concrete type depends on `FormType`).
  - The `Secretary` acts as the factory for `CourseFinishedForm`, `NeedMoreClassRoomForm`, `NeedCourseCreationForm`, `SubscriptionToCourseForm`.

- Command
  - `Form` is the base (abstract) command interface with methods such as `beSigned()` and `execute(Headmaster*)`.
  - Concrete forms implement `execute(...)` and encapsulate the action and data required (receiver references are often the `Headmaster` or data the `Headmaster` operates on).
  - `Headmaster` acts as invoker: it `sign`s and then `execute`s the `Form`.

**Sequence (typical flow)**
1. A participant (Professor/Student) requests a form via `Headmaster::needCourse()` or similar. `Headmaster` delegates creation to `Secretary::createForm(...)`.
2. The `Secretary` (factory) returns a `Form*` (allocated with `new`).
3. `Headmaster::receiveForm(form)` stores the form (pending validation), calls `sign(form)`, and, if signed, calls `execute(form)`.
4. `form->execute(this)` performs the action, possibly mutating domain objects (courses, rooms, students).
5. After execution the form is archived (Secretary/SecretarialOffice) for history.

**Schema (simplified)**

Participant -> `Headmaster` -> `Secretary` (factory) -> `Form*` (concrete)

```
Secretary::createForm(type) -> new ConcreteForm(type)
Headmaster::receiveForm(form) -> sign -> execute(form)
ConcreteForm::execute(Headmaster*) -> performs action on school state
```

**Responsibilities**
- `Secretary` (Factory): centralizes construction details and decouples callers from concrete `Form` classes.
- `Form` (Command): encapsulates an operation and its parameters, and exposes a uniform interface. `Headmaster` invokes the command.
- `Headmaster` (Invoker/Receiver): the invoker signs and executes commands and is often the receiver that the command acts upon.

**Ownership notes**
- In the historical (raw-pointer) implementation, `Secretary::createForm()` used `new` and the created pointer was later archived and deleted by `SecretarialOffice` (or left in headmaster list). This required careful ownership discipline to avoid leaks/double-frees.
- In later exercises a migration to `std::unique_ptr` was applied to archive storage to eliminate ownership confusion.

**Pitfalls**
- Double deletion or leaks when ownership is not clearly documented. If you keep raw pointers, document and enforce the transfer semantics: factory `new`s, headmaster uses and then transfers to archive, archive `delete`s.

---
