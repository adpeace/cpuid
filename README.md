cpuid
=====

Prints the result of the CPUID instruction.  Call with a value for eax, e.g.:

./cpuid 0x80000007

The argument can be in hex (if preceded with 0x), or decimal otherwise.

See http://en.wikipedia.org/wiki/CPUID for more information on CPUID values and the instruction.

Compilation is trivial:

gcc -o cpuid cpuid.c
