# -*- coding: utf-8 -*-
import pylab
import numpy as np
import matplotlib.pyplot as plt
pylab.minorticks_on()
pylab.grid(color="black", which="major", linewidth=1)
pylab.grid(color="purple", which="minor", linestyle=":", linewidth=0.5)
data=np.loadtxt ("points.txt")
plt.plot(data[:,0], data[:,1],color='red')
plt.plot(data[:,0], data[:,2],color= 'blue')
plt.plot(data[:,1], data[:,2],color= 'green')
plt.title("red- y(x), blue- y'(x), green- y'(y)")
plt.ylabel("y(x)")
plt.xlabel("x")

pylab.show()

