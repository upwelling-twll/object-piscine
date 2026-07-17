# Module_04 - Exercises 04 & 05 — Observer (ex04) and Facade (ex05)

This README covers the Observer implementation (ex04) and the Facade role implemented in ex05 (the `School`).

---

## Observer (ex04)

**Purpose**
- Implement a publish/subscribe mechanism where the `Bell` publishes break events and `IPerson`-derived objects (students, staff, headmaster, secretary) observe and react.

**Where**
- Key file(s): `ex04/bell/Bell.*`, `ex04/bell/ISubject.hpp`, `ex04/people/IPerson.*`, `ex04/people/Student.*`, `ex04/people/Staff.*`.

**Implementation summary**
- `ISubject` interface declares `attach(IPerson*)`, `detach(IPerson*)`, `notify(Break)`.
- `Bell` implements `ISubject` and keeps `std::list<IPerson*> _observers`.
  - `attach()` adds observers; `detach()` removes them; `notify(Break)` calls `update(Break)` on observers.
  - `doEvent(Event)` toggles break state and calls `notify(...)` with appropriate `Break` enum value (`BreakStarted`, `BreakEnded`, `LunchStarted`, `LunchEnded`).
- `IPerson` declares `virtual void update(Break)`; `Student`, `Staff` implement `update()` and move between rooms depending on break type.

**Sequence (bell rings)**
1. `School` or `Headmaster` requests a bell event (via `Bell::doEvent(Event::RingBell)` or `Event::LunchTime`).
2. `Bell` updates internal `_breakTime` state and calls `notify(...)` with the appropriate `Break` value.
3. Each observer's `update(Break)` executes behavior: exit/enter rooms, find dining/courtyard/ staff rest room, etc.

**Schema (simplified)**

Bell (Subject)
- + attach(IPerson*)
- + detach(IPerson*)
- + notify(Break)

IPerson (Observer)
- + update(Break)

Concrete observers: `Student`, `Staff`, `Headmaster`, `Secretary`.

**Notes**
- Observers are stored as raw pointers for polymorphism. Ensure attached objects outlive their attachment or are detached before destruction.
- `Professor` inherits `Staff`, which already implements `update()`. Override `update()` in `Professor` only if special behavior is required.

---

## Facade (ex05)

**Purpose**
- Provide a simple, high-level `School` interface that aggregates and orchestrates subsystems: Headmaster, Secretary, Room creation, Bell, and overall day routine.

**Where**
- Key file(s): `ex05/School.*`, `ex05/bell/Bell.*`, `ex05/people/Headmaster.*`, `ex05/people/Secretary.*`.

**Implementation summary**
- `School` acts as a facade with methods like:
  - `runDayRoutine()` — high-level orchestration (launch classes, ring bell, etc.)
  - `launchClasses()` — collects professors & students, asks `Headmaster` to conduct classes
  - `requestRingBell(Event)` — delegates to `Headmaster::ringBell(&bell, event)` or directly `_bell.doEvent(event)`
  - `recruteProfessor()` / `recruteStudent()` — register observers with `Bell` and add them to `SingleList`s
- Internally `School` sets up rooms, attaches `Headmaster` and `Secretary` to the `Bell`, and uses `SingleList` containers for global discovery.

**Schema (high-level flow)**

```
Client -> School -> {Headmaster, Secretary, Bell, Rooms}
School: runDayRoutine()
  -> launchClasses() -> Headmaster.conductClasses(...)
  -> requestRingBell(Event) -> Headmaster.ringBell(&bell, Event) -> Bell.notify(Break)
Observers (Student/Staff) react to Bell notifications
```

**Why Facade**
- `School` hides a lot of setup/coordination complexity: room creation, attaching observers to `Bell`, headmaster/secretary wiring, and provides a compact API for the user.

**Notes on integration with Observer**
- `School::recruteProfessor()` and `recruteStudent()` attach new people to the `Bell` so they become observers automatically.
- `School` remains responsible only for high-level orchestration; the `Bell` and `IPerson` objects encapsulate the notification and reaction behaviors respectively.

---

## Closing notes
- Across exercises the major patterns are mapped to concrete classes consistently:
  - Singleton: `SingleList<T>` for globally accessible collections
  - Factory: `Secretary::createForm()`
  - Command: `Form` family + `Headmaster` invoker/receiver
  - Mediator: `Headmaster` coordinating participants
  - Observer: `Bell` (subject) + `IPerson` observers
  - Facade: `School` as simple public API over the subsystem

- Ownership: If you keep raw pointers, document transfer-of-ownership (factory -> headmaster -> archive) and ensure a single owner is responsible for `delete`. Alternatively, convert archive/storing containers to `std::unique_ptr` to avoid double-free and leaks (this was done in `ex05`).

---
