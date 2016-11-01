
Programming Task #2: "Rush Hours"
=================================

Scenario: 
---------

In our server farm, there are certain times of day in which we get a higher number of requests. During these time-spans we want to respond by allocating more resources, to give better service. Outside these time-spans we want to remove resources, to save on energy.

We need to be able to know which times of day are such "Rush Hours".


Your task:
----------

Write a class which can receive time-spans that are defined as "Rush Hours", remember them, and can also answer queries about a specific time of day - whether it is considered rush hour or not.

The class provides the following interfaces:

1. void AddTimeSpan(float start_time, float end_time);
2. boolean IsRushHour(float time);


Assumptions:
------------

. When the class is initialized, there are no rush hours at all. The user can then add time-spans of rush hours using the "AddTimeSpan" interface. The user can at any time query about a specific time using the "IsRushHour" interface.

. Assume that "IsRushHour" is called very frequently, and "AddTimeSpan" is called less frequently.

. Assume that the system will live forever, and performance should not degrade over time.

. float T is a valid time of day if (T>=0.00 and T<24.00). You can not assume anything about the input. You must support any valid time.

. If the input is invalid (meaning T<0 or T>=24.00), behvaiour is not defined.

. IMPORTANT: The internal representation of time spans must be minimal. For example, if the same time span is added twice, there should be no change to the internal data structures.


Usage Example:
--------------

- Init() // System is initialized in an empty state
- IsRushHour(3.00) --> False
- IsRushHour(5.00) --> False

- AddTimeSpan(2.00, 4.00)
- IsRushHour(3.00) --> True
- IsRushHour(5.00) --> False

- AddTimeSpan(7.00, 9.00)
- IsRushHour(3.00) --> True
- IsRushHour(5.00) --> False
- IsRushHour(7.00) --> True
- IsRushHour(11.00) --> False

- AddTimeSpan(8.00, 12.00)
- IsRushHour(3.00) --> True
- IsRushHour(5.00) --> False
- IsRushHour(7.00) --> True
- IsRushHour(11.00) --> True


Please focus on correct, readable code.


Bonus Question: 
---------------

How would your solution be different if we changed the definition of "time" to be an integer, representing the time of day in seconds?
(answer in words)


Merge a range, keep already entered ranges in a set
