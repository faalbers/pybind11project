import sys, os, cv2
scriptPath = os.getcwd().replace(os.sep, '/')
modulePath = sys.argv[1]
print('Script Path: %s' % scriptPath)
print('Module Path: %s' % modulePath)

sys.path.append(sys.argv[1])
import franklib_bindings

print('franklib_bindings.add(1,2): %s' % franklib_bindings.add(1,2))

b = franklib_bindings.PyBase(5)
print('b = franklib_bindings.PyBase(5)')
print('b.multiply(12.34): %s' % b.multiply(12.34))
# testing getter and setter for property
print('b.multiplier: %s' % b.multiplier)
# if the C++ code does not include #include <pybind11/stl.h>
# this might spew out a type mismatch error to do so
print('b.multiply_list([1,2,3,4]): %s' % b.multiply_list([1,2,3,4]))
b.multiplier = 10
print('b.multiplier = 10')
print('b.multiply_list([1,2,3,4]): %s' % b.multiply_list([1,2,3,4]))
print('b.multiply_two(1,2): ', end = '')
print(b.multiply_two(1,2) )
print('b.multiply_two_l(3,4): ', end = '')
print(b.multiply_two_l(3,4))
print('b.makeImageNumPy(): ')
print(b.makeImageNumPy())
# writing image out of data
# using as a function
cv2.imwrite('makeImageNumpy.jpg', b.makeImageNumPy())
print("cv2.imwrite('makeImageNumpy.jpg', b.makeImageNumPy())")
# using as a property
cv2.imwrite('image.jpg', b.image)
print("cv2.imwrite('image.jpg', b.image)")

# 0 is test passed, > 0 is test failed
sys.exit(0)
