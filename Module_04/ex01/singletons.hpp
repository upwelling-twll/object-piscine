#ifndef SINGLETONS_HPP
#define SINGLETONS_HPP

template <typename T>
class SingleList
{
	private:
		std::vector<T*> _items;

		SingleList()
		{
			// _items = new std::vector<T*>;
		}

	public:
		static SingleList& getSingleList()
		{
			static SingleList newList;
			return newList;
		}

		void 	add(T* item)
		{
			if (item)
			{
				for (typename std::vector<T*>::iterator it = _items.begin(); it != _items.end(); ++it)
				{
					if (*it == item)
						throw std::runtime_error("Item already exists in the list");
				}
				_items.push_back(item);
			}
			else
				throw (std::runtime_error("Cannot add item which does not exist"));
		}

		void	remove(T* item)
		{
			if (item)
			{
				for (typename std::vector<T*>::iterator it = _items.begin(); it != _items.end(); ++it)
				{
					if (*it == item)
					{
						_items.erase(it);
						return;
					}
				}
			}
			else
				throw (std::runtime_error("Cannot add item which does not exist"));
		}

		T*  get(int i)
		{
			return (_items[i]);
		}

		int	getSize()
		{
			return (_items.size());
		}

		~SingleList()
		{
			_items.clear();
		}
};


// std::ostream& operator<<(std::ostream &output_stream, Professor& src)
// {
// 	for (typename std::vector<T*>::iterator it = _items.begin(); it != _items.end(); ++it)
// 	{
// 		std::cout << *it << std::endl;
// 	}
// }

typedef SingleList<Student> StudentList;
typedef SingleList<Staff> StaffList;
typedef SingleList<Course> CourseList;
typedef SingleList<Room> RoomList;


#endif