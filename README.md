# Get_next_line
Get_next_line - 42 Project

Read a line on a fd.
Static variable used to keep the remain of the buffer after a line.
Bonus can read on multiple fd and keep multiple opened fd remains.
Linked list buffers for performance. O(n) -> n = line size / buffer size
Linked list indexed by fd for multi-fd remains.
fsanitize address and leaks checked.
