#ifndef SINGLELIST_HPP
#define SINGLELIST_HPP

template <typename T>
class SingleList
{
	public:
		static SingleList& getSingleList()
		{
			ststic SingleList newList;
			return newList;
		}
};

#endif