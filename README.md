# COP4533-Programming_Assignment_3
Braden Azis

## How to Run

Firstly activate environment:
``` source .venv/bin/activate ```

If you're just wanting to pass in a specific input file, pipe it in.

Example:
    ``` ./hvlcs < inputs/test.txt ```

If you're wanting to rerun the empirical runtime script, first UNCOMMENT the last line in ```HVLCS.cpp``` which outputs the runtime to stderr. 
Once doing so, can run the shell script to export the runtimes of each input into the ```runtimes.txt``` file:

``` ./run_tests.sh ```

Once runtimes.txt is generated, simply run the ```graph.py``` and the runtime plot will be visible.

## Question 1

![runtime_plot](./runtime_plot.png)


## Question 2

![recurrence_relation](./Recurrence_Relation.png)

