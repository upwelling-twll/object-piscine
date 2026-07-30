#ifndef TRAINSTATE_HPP
#define TRAINSTATE_HPP
# include <iostream>
# include <string>
#include "Train.hpp"
#include "Logger.hpp"


class Train;

class TrainState //TrainState is a state, while Train is a context
{
	public:

		virtual ~TrainState() = default;

		virtual void update(Train&, double dt) = 0;

		virtual std::string_view name() const = 0;
 		// virtual void onEnter(Train& train) {}
      	// virtual void onExit(Train& train) {}
};

class AcceleratingState : public TrainState
{
	public:
		~AcceleratingState();
		
		void update(Train& train, double dt) override
		{
    		auto& log = railways::Logger::get();
			log.debug("train is updating accelerating state");
			//TODO : use train`s setSpeed method to increase speed using dt delta time 
		}

		std::string_view name() const override { return ("Accelerating");}

};

class DeceleratingState : public TrainState
{
	public:
		~DeceleratingState();
		void update(Train& train, double dt)
		{
		    auto& log = railways::Logger::get();
			log.debug("train is updating decelerating state");
			//TODO : use train`s setSpeed method to decrease speed using dt delta time 
		}

		std::string_view name() const override { return ("Decelerating");}

};

class StoppedState : public TrainState
{
	public:
		~StoppedState();
		void update(Train& train, double dt)
		{
		    auto& log = railways::Logger::get();
			log.debug("train is uon a stopped state");
			//TODO : use train`s setSpeed method to decrease speed using dt delta time 
		}

		std::string_view name() const override { return ("Stopped");}

};


#endif