#!/bin/bash

cut -d':' -f 1 /etc/passwd | \
	awk 'NR % 2 == 0' | \
	rev | \
	sort -r | \
	sed -n ''$FT_LINE1','$FT_LINE2' p' | \
	tr '\n' ',' | \
	sed 's/,/, /g' | \
	sed 's/..$//' | \
	sed 's/$/./'

# Removes every commnets
# Prints every second line
# Reversing
# Sorts in reversing alphabetic orders
# Prints from FT_LINE1 to FT_LINE2
# Replaces new lines with comma
# Replaces ',' to ', '
# Removes last 2 character because last line have new line and it is replaces with ', '
# Adds dot to the very end

