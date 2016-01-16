# EECS 230 Homework 2

Due Thursday, January 21, at 11:59 PM

## Purpose

The primary goal of this assignment is to get you more comfortable with control statements and function calls. You will also gain some familiarity with the use of STL vectors.

## Preliminaries

We have provided you with a private GitHub repository for this homework assignment, located at `https://github.com/eecs230/`<var>NETID</var>`-hw2`, where <var>NETID</var> is your six-character Northwestern NetID. For example, if your NetID were `abc123`, your HW2 repo would be at `https://github.com/eecs230/abc123-hw2`.

Because we've already forked your repository for you, you *must not* fork it on GitHub, as this would make your homework publicly readable. (Also, you will be submitting your homework via the repo we made for you.)

To start working, you need to clone a local copy of your HW2 repo. You can do this with CLion as in [Lab 1](https://github.com/eecs230/lab1): Choose *Checkout from Version Control* from the *VCS* menu or the ``Welcome to CLion'' window, and enter your repository URL.

## Your task

For this assigment you will write three C++ programs. We've provided skeleton code to get you started in the `src/` subdirectory of this repository, so you needn't start from scratch.

### Guessing game: `guessing.cpp`

Binary search is an algorithm that searches a space by repeatedly dividing it in half. For example, when you look up a word in a dictionary, you don’t scan the pages starting at page 1—rather, you open to the middle, look at a guide word, and determine whether the word you’re looking for comes before or after that point in the dictionary. Supposing that it comes before, you then split the first half of the dictionary in half to determine whether the word is in the first or second quarter of the dictionary. Then you repeat, splitting, until you’ve zeroed in on the word.

Write a program `guessing` in which the computer guesses a number (between 1 and 128 inclusive) chosen by the user using binary search. Here is an example run of the program:

<pre>
Is the number you are thinking of greater than 64 (yes or no)?
&gt; <b><i>no</i></b>
Is the number you are thinking of greater than 32 (yes or no)?
&gt; <b><i>no</i></b>
Is the number you are thinking of greater than 16 (yes or no)?
&gt; <b><i>yes</i></b>
Is the number you are thinking of greater than 24 (yes or no)?
&gt; <b><i>yes</i></b>
Is the number you are thinking of greater than 28 (yes or no)?
&gt; <b><i>yes</i></b>
Is the number you are thinking of greater than 30 (yes or no)?
&gt; <b><i>no</i></b>
Is the number you are thinking of greater than 29 (yes or no)?
&gt; <b><i>yes</i></b>
The number you are thinking of is 30.
</pre>

It should *always* take seven questions to figure out the user's number. (Why?)

How you deal with erroneous input is up to you, provided you deal with it sensibly. Here’s what my `guessing` program does:

<pre>
Is the number you are thinking of greater than 64 (yes or no)?
&gt; <b><i>es</i></b>
Did not recognize answer.
Is the number you are thinking of greater than 64 (yes or no)?
&gt; <b><i>yes</i></b>
Is the number you are thinking of greater than 96 (yes or no)?
&gt; <b><i>yes</i></b>
Is the number you are thinking of greater than 112 (yes or no)?
&gt; <b><i>yes</i></b>
Is the number you are thinking of greater than 120 (yes or no)?
&gt; <b><i>yes</i></b>
Is the number you are thinking of greater than 124 (yes or no)?
&gt; <b><i>yes</i></b>
Is the number you are thinking of greater than 126 (yes or no)?
&gt; <b><i>yes</i></b>
Is the number you are thinking of greater than 127 (yes or no)?
&gt; <b><i>yes</i></b>
The number you are thinking of is 128.
</pre>

### Numeric methods: `my_sqrt.cpp`

In class I mentioned that the C++ standard library provides a `double sqrt(double)` function for computing square roots, and that we regard it as an abstraction—we needn’t know how it works in order to use it in our programs. That said, computing square roots is not especially mysterious. The Babylonian method, which you will use in this program, dates to antiquity.

The Babylonian method for computing square roots relies on the following insight. Suppose we are trying to compute the square root of a number <var>a</var>, and suppose we have a guess <var>x<sub>0</sub></var>. If <var>x<sub>0</sub></var> is the square root then <var>a</var>/<var>x<sub>0</sub></var> = <var>x<sub>0</sub></var>; but otherwise, the true square root of <var>a</var> lies somewhere between <var>x<sub>0</sub></var> and <var>a</var>/<var>x<sub>0</sub></var>. (If <var>x<sub>0</sub></var> is less than the true square root of <var>a</var> then <var>a</var>/<var>x<sub>0</sub></var> is greater, and vice versa.) We can thus produce a better estimate, <var>x<sub>1</sub></var>, by computing the arithmetic mean (average) of <var>x<sub>0</sub></var> and <var>a</var>/<var>x<sub>0</sub></var>:

  - <var>x<sub>1</sub></var> = (<var>x<sub>0</sub></var> + <var>a</var>/<var>x<sub>0</sub></var>)/2.
  
In theory, if <var>x<sub>1</sub></var> equals <var>a</var>/<var>x<sub>1</sub></var> then we’ve computed the square root. In computational practice, square roots are approximate, so if <var>x<sub>1</sub></var> is *close enough to* <var>a</var>/<var>x<sub>1</sub></var> then it’s close enough to the true square root (since the true square root is in between the two). Otherwise, <var>x<sub>1</sub></var> is an improved estimate, and we can improve it further by iterating the formula:

  - <var>x<sub>n+1</sub></var> = (<var>x<sub>n</sub></var> + <var>a</var>/<var>x<sub>n</sub></var>)/2.
 
In `my_sqrt.cpp` write a function,

    double my_sqrt(double input, double epsilon);
    
that computes the square root of `input` to an accuracy of `epsilon`. It does this by using 1 for the initial estimate <var>x<sub>0</sub></var>, then iterating the Babylonian method formula until the [absolute value](http://www.cplusplus.com/reference/cmath/abs/) of the difference between an estimate <var>x<sub>n</sub></var> and <var>a</var>/<var>x<sub>n</sub></var> is less than `epsilon`.

Then write `main` for `my_sqrt.cpp` so that it reads a `double` from the user, computes its square root to a tolerance (epsilon) of `1e-8`, and prints the result. Here are three sample runs of my solution:

<pre>
Please enter a number:
&gt; <b><i>9</i></b>
The square root of 9 is 3.
</pre>

<pre>
Please enter a number:
&gt; <b><i>10</i></b>
The square root of 10 is 3.16228.
</pre>

<pre>
Please enter a number:
&gt; <b><i>-1</i></b>
runtime error: Number was negative.
</pre>


### Making change: `change.cpp`

#### The greedy change algorithm

Suppose we have 1-, 5-, 10-, and 25-cent coins in our cash register, and we need to make change for <var>n</var> cents. One (suboptimal) algorithm to do this is as follows. First, check how many times the largest denomination, 25 cents, fits into <var>n</var>: <var>n</var> <tt>/</tt> 25 (integer division). Then the amount remaining to make change for is <var>n</var> <tt>%</tt> 25 (integer remainder). We then divide that amount by 10 to find out how many 10-cent coins to use, and the remainder gives us the amount to make change for using 5- and 1-cent coins.

Here is a run of a program that uses this algorithm to make change, in this case for 97 cents:
 
<pre>
Enter coin denominations (0 when done):
&gt; <b><i>1 5 10 25 0</i></b>
Enter amount to make change for:
&gt; <b><i>97</i></b>
Change is:
3 coin(s) of denomination 25
2 coin(s) of denomination 10
0 coin(s) of denomination 5
2 coin(s) of denomination 1
</pre>

Of course, different currencies (and different cash registers) have different denominations of coins. Suppose we still have 1-, 5-, and 25-cent coins, but no 10-cent coins. Then we can use the program to make change for 97 cents without using 10-cent coins:

<pre>
Enter coin denominations (0 when done):
&gt; <b><i>1 5 25 0</i></b>
Enter amount to make change for:
&gt; <b><i>97</i></b>
Change is:
3 coin(s) of denomination 25
4 coin(s) of denomination 5
2 coin(s) of denomination 1
</pre>

Note, also, that making change isn’t always possible:

<pre>
Enter coin denominations (0 when done):
&gt; <b><i>2 0</i></b>
Enter amount to make change for:
&gt; <b><i>3</i></b>
runtime error: Could not make change.
</pre>

#### What you have to do

In `change.cpp` we’ve applied the divide-and-conquer strategy to factor (divide) your program into four helper functions:

  - `vector<int> read_denominations()`,
  - `int read_amount()`,
  - `vector<int> make_change(vector<int> denominations, int amount)`, and
  - `void print_change(vector<int> denominations, vector<int> change)`.

We’ve written `main` for you using the above four functions; your job is to complete (conquer) the four functions so that the whole program works.

## Reference

### How to exit with an error message

Starting with this assignment, we will use `error` rather than `simple_error` to report run-time errors. It throws an exception that we then catch outside `main` (as in *CCC/2e*).  So to bail out you should now write something like

    error("I give up!");
    
(but with a more specific error message, of course).

## Grading

For this assignment, you will be graded on

 - whether your code implements the specification (functional correctness), and

 - the clarity of your code, in particular good factoring into single-purpose functions.

## Submission

See [the submission instructions](http://users.eecs.northwestern.edu/~jesse/course/eecs230/homework). The tag for Homework 2 is `hw2`. Note that the time of your push to GitHub will count as your submission time.
