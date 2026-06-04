#ifndef WORKSHOPBASE_HPP
# define WORKSHOPBASE_HPP

# include <iostream>

class Worker;

class WorkshopBase
{
public:
	virtual void releaseWorker(Worker* worker) = 0;
	virtual void onToolDiscarded(Worker* worker) = 0;

	/*Destructors*/
    virtual ~WorkshopBase( void ) {};

};

#endif // WORKSHOPBASE_HPP
