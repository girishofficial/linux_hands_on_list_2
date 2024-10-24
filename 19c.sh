#!/bin/bash
# ================================================================================
# Name : 19c.sh
# Author : GIRISH KUMAR SAHU
# Description : Use strace to compare mknod and mkfifo commands
# Date: 20th Sep, 2024.
# ================================================================================

echo "Tracing mknod command:"
strace mknod myfifo_mknod p > strace_mknod_output.txt 2>&1
echo "mknod traced, check strace_mknod_output.txt for details"

echo "Tracing mkfifo command:"
strace mkfifo myfifo_mkfifo > strace_mkfifo_output.txt 2>&1
echo "mkfifo traced, check strace_mkfifo_output.txt for details"

# Output:
# Tracing mknod command:
# mknod traced, check strace_mknod_output.txt for details
# Tracing mkfifo command:
# mkfifo traced, check strace_mkfifo_output.txt for details


