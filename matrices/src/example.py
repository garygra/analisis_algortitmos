#! /usr/bin/python

import numpy as np


####################################
## VECTOR ADDITION/SUBSTRACTION
####################################
x = np.array([3,2])
y = np.array([5,1])
z = x + y
print z

####################################
## SCALAR PRODUCT / DOT PRODUCT
####################################
x = np.array([1,2,3])
y = np.array([-7,8,9])
print np.dot(x,y)
dot = np.dot(x,y)
x_modulus = np.sqrt((x*x).sum())
y_modulus = np.sqrt((y*y).sum())
cos_angle = dot / x_modulus / y_modulus # cosine of angle between x and y
angle = np.arccos(cos_angle)
print angle
print angle * 360 / 2 / np.pi # angle in degrees

####################################
## Using the * operator
####################################
# Array mult is element by element
x = np.array( ((2,3), (3, 5)) )
y = np.array( ((1,2), (5, -1)) )
print x * y
# mat mult is matrix multiplication
x = np.matrix( ((2,3), (3, 5)) )
y = np.matrix( ((1,2), (5, -1)) )
print x * y

####################################
## Matrix product (vec * mat)
####################################
# Use np dot to combine arrays and mats
x = np.array( ((2,3), (3, 5)) )
y = np.matrix( ((1,2), (5, -1)) )
print np.dot(x,y)

# Or transform array to mat
print np.mat(x) * y
####################################
## Cross product
####################################
x = np.array([0,0,1])
y = np.array([0,1,0])

print np.cross(x,y)
print np.cross(y,x)

####################################
## 
####################################

####################################
## 
####################################

####################################
## 
####################################