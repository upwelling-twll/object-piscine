#ifndef SINGLETONS_HPP
#define SINGLETONS_HPP

template <typename T>
class SingleList
{
	private:
		std::vector<T*> _items;

		SingleList()
		{
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
					{
						LOG_WARNING("SingleList: Item already exists in the list");
						return ;
					}
				}
				_items.push_back(item);
			}
			else
				LOG_WARNING("SingleList: Cannot add item which does not exist");
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
				LOG_WARNING("SingleList: Cannot add item which does not exist");
		}

		T*	find(T* item)
		{
			if (item)
			{
				for (typename std::vector<T*>::iterator it = _items.begin(); it != _items.end(); ++it)
				{
					if (*it == item)
					{
						return (it);
					}
				}
			}
			else
			{
				LOG_WARNING("SingleList: Item not found");
				return (NULL);
			}
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

		SingleList(const SingleList&) = delete;
		void operator=(const SingleList) = delete;
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