## INTRODUCTION:
- Code supplement for the paper "Stochastic Berthing Appointment Scheduling in Seaports".

## REQUIREMENTS:
- Linux Environment.
- CPLEX 20.1.0 or higher (https://www.ibm.com/analytics/cplex-optimizer).
- See how to write C++ applications using CPLEX with Concert Technology (https://www.ibm.com/docs/en/icos/12.7.1.0?topic=tutorials-tutorial). 

## DATASETS:
- The instance data are provided in the folder "instances". 
- For a detailed explanation of the instance data, find the "README" file in the folder "instances". 
- Detailed computational results are provided in the folder "results".

## CODE:
- Code of all algorithms used in our computational experiments is provided in the folder "sourcecode". 
- List of .cpp files in the subfolder "src":
  1. A0：   The BPBC algorithm introduced in Section 5 without any of the enhancement strategies from Section 6 in the paper.
  2. A1:    Algorithm A0 incorporating the label truncation strategies proposed in Section 6.1 in the paper.
  3. A2:    Algorithm A0 incorporating the enhancement strategies proposed in Section 6.2 in the paper.
  4. A3:    Algorithm A0 incorporating all the enhancement strategies proposed in Section 6 in the paper.


- List of .h files in the subfolder "inc":
  1. Avgminmax02.h:         user-defined C++ library header file for mathematical functions

## USAGE:
- To run an algorithm for solving an instance:
  1. Copy the instance data from the "data" folder;
  2. Load the data into the code for the algorithm between lines "//input data starts here" and "//input data ends here";
  3. Build and run the code
