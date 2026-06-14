#ifndef SINGLELIST_HPP
#define SINGLELIST_HPP

template <typename T>
class SingleList
{
	public:
		static SingleList& getSingleList()
		{
			static SingleList newList;
			return newList;
		}
};

#endif