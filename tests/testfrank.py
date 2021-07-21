import sys
sys.path.append(sys.argv[1])

import franklib_bindings

print('Result: %s' % franklib_bindings.add(1,2))

b = franklib_bindings.PyBase(10)
print(b.multiply(12.34))
# if the C++ code does not include #include <pybind11/stl.h>
# this might spew out a type mismatch error to do so
print(b.multiply_list([1,2,3,4]))
print(b.multiply_two(1,2))
print(b.multiply_two_l(3,4))

# 0 is test passed, > 0 is test failed
sys.exit(0)
