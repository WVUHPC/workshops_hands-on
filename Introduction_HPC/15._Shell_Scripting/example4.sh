#!/bin/bash

# Escaping a newline.
# ------------------

echo ""

echo "This will print
as two lines."
# This will print
# as two lines.

echo ""

echo "This will print \
as one line."
# This will print as one line.

echo ""

echo -e "This\twill\tprint\twith\ttabs"
# This will print with tabs.

echo; echo

echo "============="


echo "\v\v\v\v"      # Prints \v\v\v\v literally.
# Use the -e option with 'echo' to print escaped characters.
echo "============="
echo "VERTICAL TABS"
echo -e "\v\v\v\v"   # Prints 4 vertical tabs.
echo "=============="

echo "QUOTATION MARK"
echo -e "\042"       # Prints " (quote, octal ASCII character 42).
echo "=============="

echo; echo "NEWLINE"
echo This is going to jump $'\n' to a new line           # Newline.

exit 0

