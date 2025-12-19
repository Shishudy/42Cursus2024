#!/bin/bash

EXEC=./SedIsForLosers
RED="\033[31m"
GREEN="\033[32m"
NC="\033[0m"

pass() { echo -e "${GREEN}[PASS]${NC} $1"; }
fail() { echo -e "${RED}[FAIL]${NC} $1"; }

rm -f *.replace test_*.txt

echo "🔧 Building program..."
make re > /dev/null 2>&1 || { echo "❌ Build failed"; exit 1; }

########################################
# Test 1: Simple replacement
########################################
echo "hello world" > test_1.txt
$EXEC test_1.txt world 42
grep -q "hello 42" test_1.txt.replace && pass "T1 Simple replacement" || fail "T1"

########################################
# Test 2: Multiple replacements per line
########################################
echo "world world world" > test_2.txt
$EXEC test_2.txt world 42
grep -q "42 42 42" test_2.txt.replace && pass "T2 Multiple replacements" || fail "T2"

########################################
# Test 3: No occurrences
########################################
echo "hello universe" > test_3.txt
$EXEC test_3.txt world 42
diff test_3.txt test_3.txt.replace > /dev/null && pass "T3 No occurrences" || fail "T3"

########################################
# Test 4: s1 == s2
########################################
echo "hello world" > test_4.txt
$EXEC test_4.txt world world
grep -q "hello world" test_4.txt.replace && pass "T4 s1 == s2" || fail "T4"

########################################
# Test 5: Overlapping patterns
########################################
echo "aaaaa" > test_5.txt
$EXEC test_5.txt aa X
# Expected: "XXa"
grep -q "XXa" test_5.txt.replace && pass "T5 Overlapping patterns" || fail "T5"

########################################
# Test 6: s1 longer than line
########################################
echo "short" > test_6.txt
$EXEC test_6.txt verylongstring X
diff test_6.txt test_6.txt.replace > /dev/null && pass "T6 s1 longer than line" || fail "T6"

########################################
# Test 7: Empty file
########################################
touch test_7.txt
$EXEC test_7.txt foo bar
[ -f test_7.txt.replace ] && pass "T7 Empty file" || fail "T7"

########################################
# Test 8: File with only newlines
########################################
printf "\n\n\n" > test_8.txt
$EXEC test_8.txt foo bar
diff test_8.txt test_8.txt.replace > /dev/null && pass "T8 Only newlines" || fail "T8"

########################################
# Test 9: Very long line
########################################
# Create a very long single line (~60k chars)
printf '%s' "$(yes abc | head -n 20000 | tr -d '\n')" > test_9.txt
$EXEC test_9.txt abc XYZ
grep -q "XYZXYZXYZ" test_9.txt.replace && pass "T9 Very long line" || fail "T9"

########################################
# Test 10: Binary-ish content
########################################
printf "a\0b\0c\n" > test_10.txt
$EXEC test_10.txt a Z
[ -f test_10.txt.replace ] && pass "T10 Binary-ish content" || fail "T10"

########################################
# Test 11: Special characters
########################################
echo '!@#$%^&*() world []{}' > test_11.txt
$EXEC test_11.txt world OK
grep -q "OK" test_11.txt.replace && pass "T11 Special characters" || fail "T11"

########################################
# Test 12: Empty s1 (must fail safely)
########################################
echo "hello" > test_12.txt
$EXEC test_12.txt "" X 2>/dev/null && fail "T12 Empty s1 (should fail)" || pass "T12 Empty s1 handled"

########################################
# Test 13: File does not exist
########################################
$EXEC does_not_exist.txt foo bar 2>/dev/null && fail "T13 Missing file" || pass "T13 Missing file handled"

########################################
# Test 14: Large file stress test
########################################
for i in {1..10000}; do echo "line world $i"; done > test_14.txt
$EXEC test_14.txt world 42
grep -q "line 42 9999" test_14.txt.replace && pass "T14 Large file" || fail "T14"

echo "✅ Tests completed"