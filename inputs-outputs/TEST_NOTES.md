# Test suite notes

Ten test cases for the Large Sum program. Each `inputN.txt` pairs with `outputN.txt`.
Outputs were produced by the program and independently verified against Python's
arbitrary-precision integers.

| Test | # integers | Sum digits | What it exercises |
|------|-----------:|-----------:|-------------------|
| 1 | 0 | 1 | Empty file (0 integers) -> sum is 0 |
| 2 | 1 | 1 | Single value 0 -> sum is 0 |
| 3 | 2 | 1 | Leading zeros in input (0001+0001), full sum has no leading zeros |
| 4 | 5 | 6 | Small numbers, sum has fewer than 10 digits (2nd line = whole sum) |
| 5 | 2 | 11 | Carry lengthens the number (9999999999 + 1 = 11-digit sum) |
| 6 | 5 | 1 | Multiple zeros of varying widths -> sum is 0 |
| 7 | 1 | 50 | Single 50-digit number (max digit width, one value) |
| 8 | 100 | 52 | 100 fifty-digit numbers (original Project Euler #13 scale) |
| 9 | 200 | 53 | 200 x (fifty 9s): maximum possible magnitude under the constraints |
| 10 | 200 | 51 | 200 numbers of varying widths (1-50 digits) with some leading zeros |
