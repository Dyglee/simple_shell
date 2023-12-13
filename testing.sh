#!/bin/bash

# Function to run a test case
run_test() {
    local description="$1"
    local input="$2"
    local compare_with_sh=${3:-1}

    echo "Running test: $description"
    echo "$input" | ./hsh > output_hsh.txt 2> error_hsh.txt
    echo $? > status_hsh.txt

    if [ "$compare_with_sh" -eq 1 ]; then
        echo "$input" | /bin/sh > output_sh.txt 2> error_sh.txt
        echo $? > status_sh.txt

        if diff output_hsh.txt output_sh.txt && diff error_hsh.txt error_sh.txt && diff status_hsh.txt status_sh.txt; then
            echo "Test '$description' PASSED"
        else
            echo "Test '$description' FAILED"
        fi
    fi

    echo "----------------------------------------------------"
}

# Test case 1: Execute /bin/ls
run_test "Execute /bin/ls" "/bin/ls"

# Test case 2: Execute /bin/ls 3 times
run_test "Execute /bin/ls 3 times" "/bin/ls\n/bin/ls\n/bin/ls"

# Test case 3: Spaces only (small)
run_test "Spaces only (small)" "                " 0

# Test case 4: Spaces only (medium)
run_test "Spaces only (medium)" "                                                                                                                                                                                                                                                                                                                                                                                   " 0

# Copy /bin/ls to hbtn_ls and test
cp /bin/ls hbtn_ls
run_test "Execute ./hbtn_ls /var" "./hbtn_ls /var"
rm -f hbtn_ls

# Clean up
rm -f output_hsh.txt error_hsh.txt status_hsh.txt output_sh.txt error_sh.txt status_sh.txt

echo "All tests completed."

