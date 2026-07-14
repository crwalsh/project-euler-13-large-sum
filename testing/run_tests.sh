#!/usr/bin/env bash
#
# run_tests.sh - compile largesum.cpp and check it against every
#                inputN.txt / outputN.txt pair in this directory.
#
# Usage:  ./run_tests.sh
#
# For each test it copies inputN.txt to input.txt (what the program reads),
# runs the program, and diffs the program's output against outputN.txt.
# Prints a PASS/FAIL line per test and an overall summary. Exit status is
# 0 only if every test passes.

set -u

SRC="largesum.cpp"
BIN="./largesum"

# --- compile -----------------------------------------------------------------
echo "Compiling $SRC ..."
if ! g++ -std=c++17 -O2 -Wall -Wextra -o largesum "$SRC"; then
    echo "COMPILE FAILED"
    exit 1
fi
echo "Compiled OK"
echo

# --- preserve any existing input.txt so we don't clobber it ------------------
RESTORE=0
if [ -f input.txt ]; then
    cp input.txt .input.txt.bak
    RESTORE=1
fi
cleanup() {
    if [ "$RESTORE" -eq 1 ]; then
        mv .input.txt.bak input.txt
    else
        rm -f input.txt
    fi
}
trap cleanup EXIT

# --- run every test ----------------------------------------------------------
pass=0
fail=0

for infile in $(ls input[0-9]*.txt 2>/dev/null | sort -V); do
    n="${infile#input}"; n="${n%.txt}"
    expected="output${n}.txt"

    if [ ! -f "$expected" ]; then
        printf "SKIP  test %-3s (no %s)\n" "$n" "$expected"
        continue
    fi

    cp "$infile" input.txt
    actual="$($BIN)"

    if diff -q <(printf '%s' "$actual") "$expected" >/dev/null 2>&1 \
       || [ "$actual" = "$(cat "$expected")" ]; then
        printf "PASS  test %s\n" "$n"
        pass=$((pass + 1))
    else
        printf "FAIL  test %s\n" "$n"
        echo "      --- expected ---"
        sed 's/^/      /' "$expected"
        echo "      --- got ---"
        printf '%s\n' "$actual" | sed 's/^/      /'
        fail=$((fail + 1))
    fi
done

echo
echo "-----------------------------------"
echo "Passed: $pass    Failed: $fail"
if [ "$fail" -eq 0 ] && [ "$pass" -gt 0 ]; then
    echo "ALL TESTS PASSED"
    exit 0
else
    exit 1
fi
