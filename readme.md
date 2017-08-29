# Automated College Timetable Generator
This automated college timetable generator generates a timetable (schedule of classes) for all batches (across semesters) belonging to a department of a college.
This project was aimed at creating a timetable generator which automates timetable generation for our college.

### To execute:
- Run the `timetable.sh` for Linux or run `timetable.bat` for Windows.
- Follow the prompts. 

### Format for inputs:
Currently there is no UI for entering inputs.

- Open `get_inputs.h` in the `Inputs` directory of the respective `Oddsem`/`Evensem` directory.
- Enter all the courses of the department in the `entercourselist` function in the format `listofcourses->pb(new Course("Course name","Faculty name",Semester,Number of classes per week,'Section'));`. Here each section has a different course as a different faculty handles it. Also take care to use the same faculty name in another entry if the faculty takes another course.
- Enter the sections per semester in the `entersectionlist` function in the format `listofsections->pb(new Section(listofcourses,'Section',Semester Number));`. Here `listofcourses` is a pointer to the vector containing the list of courses and should be left as is.
- Enter all the labs offered by the department in the `enterlablist` function in the format `listoflabs->pb(new Lab("Lab name","Faculty1 name","Faculty2 name",Number of labs per week,Semester,"Batch1","Batch2"));`. This has been optimized to suit our college's requirements and can be changed according to requirements. In our college we have two faculty members handling a lab which consists of two batches (one faculty per batch). The faculty name should be same throughout for a particular individual.
- Enter the batches for labs in the `enterbatchlist` function in the format `listofbatches->pb(new Batch(listoflabs,"Batch name",Semester,Strength of batch));`. `listofbatches` is a pointer and should be left as is. We need batch strength so that at a given time slot we don't end up allocating more batches than the available resources (computers).
- Enter all the semesters in the `entersemesterlist` function in the format `listofsemesters->pb(new Semester(listofcourses,listofsections,listoflabs,listofbatches,Semester));`. Here only `Semester` has to be provided.
- There is a function called `Maths_Constraints` because in our college, the Math subjects were handled by the Math department and they allocated faculty in particular slots according to their convenience. So this has to be input to the program as constraint. Add the following piece of code `pair <string,pair<int,int> > * temppair=new pair<string,pair<int,int> >;`
    `temppair->first="Section";(temppair->second).first=Day of week;(temppair->second).second=Hour of day;`
`mathscourse->pb(temppair);`
Here `Day of week` is an integer between 1 for Monday through 6 for Saturday and `Hour of day` is an integer for the slot in the day from 1 through 7.
Functions like this can be added to handle constraints of this kind.
- There is also a function called `Teacher_Unavailable` which handles constraints like teacher being unavailable for a particular slot on a particular day. Add the following piece of code `temppair=new pair<string,pair<int,int> >;`
`temppair->first="Faculty name";(temppair->second).first=Day of week;(temppair->second).second=Hour of day;`
`teacherunav->pb(temppair);`.
- There is a function called `Course_Hardcode` where courses can be hardcoded into particular slots if so desired. Add the following code `temppair=new pair<pair<string,string>,pair<int,int> >;`
    `(temppair->first).first="Course name";(temppair->first).second="SemesterSection";(temppair->second).first=Day of week;(temppair->second).second=Hour of day;`
    `coursehardcode->pb(temppair);`
- There is also a function called `Lab_Hardcode` where labs can be hardcoded into particular slots. Add the following code `temppair=new pair<pair<string,string>,pair<pair<string,string>,pair<int,int> > >;`
    `(temppair->first).first="Lab name";(temppair->first).second="SemesterSection";
    (temppair->second).first.first="Batch1";(temppair->second).first.second="Batch2";` `(temppair->second).second.first=Day of week;(temppair->second).second.second=Hour of day;`
    `labhardcode->pb(temppair);`

### Outputs:
The raw output will be displayed on the terminal.
To view the formatted output (done by `CODE.h`) open the file `TimeTableEvenSem.txt` (or `TimeTableOddSem.txt`) which gets created in the project root directory. The output will satisfy all the constraints imposed.

### Classes:
The various classes are `Course`, `Section`, `Lab`, `Batch`, `Professor` and `Semester`.

### Notes:
Some of the references that we used are:

- [http://www.codeproject.com/Articles/23111/Making-a-Class-Schedule-Using-a-Genetic-Algorithm](http://www.codeproject.com/Articles/23111/Making-a-Class-Schedule-Using-a-Genetic-Algorithm)
- [http://lalescu.ro/liviu/fet/](http://lalescu.ro/liviu/fet/)
- [http://www.academia.edu/6574306/Application_of_Genetic_Algorithm_for_Solving_University_Timetabling_Problems_a_case_study_of_Thai_Universities](http://www.academia.edu/6574306/Application_of_Genetic_Algorithm_for_Solving_University_Timetabling_Problems_a_case_study_of_Thai_Universities)
- [http://www.ijimt.org/papers/46-M431.pdf](http://www.ijimt.org/papers/46-M431.pdf)

Based on these references and a lot of other reading material, the choice was between `Genetic Algorithms`, `Hill Climbing`, `Simulated Annealing`, `Tabu Search` and `Memetic algorithms`. I chose to use the Genetic Algorithm approach. Although, the Genetic Algorithm approach works really well for a generic problem, on testing, it wasn't yielding satisfactory results in our college's specific case. Hence I decided to stick to a simple Heuristic based approach. (There are a lot of genetic approach related terminology in the code and these were just left over from the testing done using the genetic approach and such terminology should be ignored)

We have a set of `hard constraints` that need to be satisfied and a set of `soft constraints` which the generator must strive to satisfy but failing to do so doesn't mean an unusable timetable.

Apart from the usual hard constraints that any timetabling problem will have like there should be no course collision, a professor mustn't be assigned to two slots simultaneusly, etc, the other important hard constraints kept which were taken care of were - all hard inputs of slots must be satisfied, the number of batches assigned to a lab during a particular slot shouldn't exceed the lab capacity, there should be only a certain number of classes of a subject per day, a teacher should only work for a certain number of slots per day, etc.

Some soft constraints which were taken care of include, the classes of a particular section should be in continuous slots and there should be no gap in between, a teacher should have a gap of a slot between teaching two slots, the classes should preferably begin at 9am, the labs should be fully utilised most of the time, etc.

Oddsem are semesters 1,3,5 and 7 while Evensem are semesters 2,4,6 and 8. They have been separately handled as they exhibit a slight difference in their set of constraints.

### Working:
- Initially, an empty vector is created which consists of all the slots of all the semesters across a week.
- All the hard inputs are then filled in.
- The lab slots are then assigned randomly but following a set of heuristics and constraint satisfaction is ensured after evaluation of the generated schedule.
- The partial schedule is displayed and the user is asked whether he is satisfied with the generated lab schedule.
- If not satisfied, the process is repeated, else if satisfied, the algorithm goes ahead with the filling of courses.
- Since a randomized approach is being used, the algorithm may get stuck if a chain of wrong choices are made. If this happens, the process begins again automatically.
- After the filling of lab slots, the filling of courses begins and this too is done randomly according to certain heuristics. Evaluation of the generated schedule is done to see constraint satisfaction. This filling of slots is done semester wise.
- The formatted output is generated in a text file.
- The end result is a scheduling which satisfies all the hard constraints and strives to satisfy as much of the soft constraints as possible.

`oddsem.cpp`/`evensem.cpp` are the main code files which call other functions from other files. The flow could be followed from here.
 

