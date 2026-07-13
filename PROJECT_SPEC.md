# Large Sum — Project Euler #13, Modified Assignment

## Project overview

Project Euler Problem 13, **Large Sum**, asks for the first ten digits of the sum of one hundred 50-digit integers. This assignment generalizes that problem: the program must read a variable collection of large non-negative integers, calculate their complete sum without using built-in arbitrary-precision integer support, and report both the full sum and its first ten digits.

Original problem: [Project Euler #13 — Large Sum](https://projecteuler.net/problem=13)

## Program requirements

The program must be written in Java, C, or C++ and use the corresponding required filename:

- `LargeSum.java`
- `largesum.c`
- `largesum.cpp`

Python is not permitted. Big-integer facilities such as Java's `BigInteger`, or equivalent arbitrary-precision built-ins or libraries in any language, are also not permitted. The program must perform the large-number arithmetic itself.

## Input

The program reads from a file named `input.txt`, located in the same directory as the source/program.

- The file contains between 0 and 200 non-negative integers.
- Each integer appears on its own line.
- Each integer contains between 1 and 50 decimal digits.
- Input lines contain only the digits `0` through `9` and newline characters.
- Leading zeros may appear in the input.
- The file may be empty.
- The file may be assumed to exist; file-error handling is optional.

The grader may replace `input.txt` with additional test cases, so the program must work for any input satisfying these constraints rather than only the original Project Euler data.

## Required output

The program must print exactly two lines, with capitalization and spacing exactly as shown:

```text
Full sum: <complete sum>
First 10 digits: <first ten digits of the sum>
```

For example:

```text
Full sum: 1238561234576829475628947856287458923478362
First 10 digits: 1238561234
```

The full sum must not contain leading zeros. If the sum has fewer than ten digits, the second line contains the entire sum. If the input file is empty or the sum is zero, both reported values must be `0`.

For example, adding `0001` and `0001` produces:

```text
Full sum: 2
First 10 digits: 2
```

## Deliverables

Submit one ZIP archive containing:

1. The source file with the required language-specific filename.
2. Ten test input files named `input1.txt` through `input10.txt`.
3. Ten matching expected-output files named `output1.txt` through `output10.txt`.

The tests should cover meaningful variations of the requirements, including boundary and edge cases. Every team member's name must appear in the source-code comments and in the Canvas submission comments. Only one submission is required per team.

## Completion criteria

The finished project is a command-line program that correctly sums every valid test file, including values too large for ordinary numeric types, and produces the exact two-line output format required above. The submitted test suite documents the inputs tried and the expected result for each one.
