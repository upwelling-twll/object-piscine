# Module_04 - Exercise 01 — Singleton

**Purpose**
- Centralize global lists (rooms, students, staff, courses) using a single shared place per type.

**Where**
- Key file(s): `ex01/singletons.hpp` (also similar `singletons.hpp` variations across exercises).

**Implementation summary**
- A templated class `SingleList<T>` implements the singleton instance with a Meyers-style static local object:
  - `static SingleList& getSingleList()` returns the sole instance.
  - Internally stores `std::vector<T*> _items` and exposes `add(T*)`, `remove(T*)`, `get(int)`, `getSize()`.
- Concrete typedefs (in some exercises) map template instantiations to domain names:
  - `typedef SingleList<Student> StudentList;` etc.

**Why this fits the Singleton pattern**
- `SingleList<T>` guarantees a single, globally accessible container per T.
- Access via `StudentList::getSingleList()` is concise and consistent across modules.

**Responsibilities & constraints**
- `SingleList` is not responsible for object lifetime (stores raw pointers). The codebase must coordinate ownership elsewhere.
- Thread-safety: Meyers singleton is thread-safe in C++11 and later for initialization; container methods are not synchronized.

**Schema (class view)**

SingleList<T>
- + getSingleList() : SingleList<T>&
- - std::vector<T*> _items
- + add(T*)
- + remove(T*)
- + get(int) : T*

Usage example:
- `StudentList::getSingleList().add(&harry);`

**Notes & pitfalls**
- Because stored pointers are raw, you must ensure no double deletes and consistent lifetime management (who `new`/`delete`).
- Later exercises migrated to `unique_ptr` for archives to avoid ownership confusion; `SingleList` remained pointer-based for polymorphism and ease of use.

---
