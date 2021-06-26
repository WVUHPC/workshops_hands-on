#!/usr/bin/env python3

import matplotlib
matplotlib.use('agg')

import numpy as np
import matplotlib.pyplot as plt

indata = np.loadtxt("input.txt")
outdata = np.loadtxt("output.txt")

plt.imshow(indata, interpolation='none')
plt.savefig("input.pdf")
plt.clf()

plt.imshow(outdata, interpolation='none')
plt.savefig("output.pdf")

