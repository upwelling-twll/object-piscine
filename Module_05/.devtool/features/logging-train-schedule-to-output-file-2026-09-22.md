---
id: "logging-train-schedule-to-output-file-2026-09-22"
status: "backlog"
priority: "medium"
assignee: null
epic: null
dueDate: null
created: "2026-09-22T08:56:03.150Z"
modified: "2026-09-22T09:03:20.348Z"
completedAt: null
labels: []
order: "a2"
---
# Logging each train schedule to output file

provide an estimate of the average travel time between two points in the\
network\
\
Your program must provide a file for each travel, containing informations about it. Those\
file must be named "TrainName_TrainDepartureTime.result".\
The output file must start follow this format :\
Train : TrainAB1\
Final travel time : XXhXXm\
You must provide an estimated time for the full travel, based on the acceleration force of\
the train and the distance to run.\
Once you have given those informations, the output file must provide information\
about what the train have been doing during its travel, following this format :\
\[00h00\] - \[ CityA\]\[RailNodeA\] - \[53.00km\] - \[Speed up\] - \[x\]\[ \]\[ \]\[ ... \]\[ \]\[ \]\[ \]\
\[00h05\] - \[ CityA\]\[RailNodeA\] - \[52.50km\] - \[Maintain\] - \[x\]\[ \]\[ \]\[ ... \]\[ \]\[ \]\[ \]\
\[00h10\] - \[ CityA\]\[RailNodeA\] - \[51.00km\] - \[Maintain\] - \[x\]\[ \]\[ \]\[ ... \]\[ \]\[ \]\[ \]\
...\
...\
\[XXhXX\] - \[ CityA\]\[RailNodeA\] - \[38.01km\] - \[Maintain\] - \[ \]\[ \]\[ \]\[ ... \]\[ \]\[ \]\[x\]\
\[XXhXX\] - \[RailNodeA\]\[RailNodeB\] - \[30.00km\] - \[Maintain\] - \[x\]\[ \]\[ \]\[ ... \]\[ \]\[ \]\[ \]\[ \]\[ \]\[ \]\[ \]\[ \]\
...\
\[XXhXX\] - \[RailNodeC\]\[ CityB\] - \[01.00km\] - \[ Braking\] - \[ \]\[ \]\[ \]\[x\]\[ \]\
\[XXhXX\] - \[RailNodeC\]\[ CityB\] - \[00.90km\] - \[ Braking\] - \[ \]\[ \]\[ \]\[x\]\[ \]\
...\
\[XXhXX\] - \[RailNodeC\]\[ CityB\] - \[00.00km\] - \[ Stopped\] - \[ \]\[ \]\[ \]\[ \]\[x\]\
Each line of this output file must contain the following informations:

1. The time since start
2. The node where the train started
3. The node where the train will arrive
4. The distance left to the final destination of the travel
5. An indication of what the train is doing (Speeding up, maintaining speed, bracking,\
   stopped, or whatever you may need)
6. A simple graph, representing the rail state, from the starting node to the destination\
   node This graph must represent the percent of completion of the distance between\
   those node, and must be represented by one cell per km. If there is another train\
   blocking the way, it must be represented by a ’O’