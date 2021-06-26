# IPython log file

from netCDF4 import Dataset
import numpy as np

NATOMS=10000000

rootgrp = Dataset("MD.nc", "w", format="NETCDF4")

positions = rootgrp.createGroup("positions")
forces = rootgrp.createGroup("forces")

pxyz=positions.createDimension("XYZ", 3)
patoms=positions.createDimension("Atoms", NATOMS)

fxyz=forces.createDimension("XYZ", 3)
fatoms=forces.createDimension("Atoms", NATOMS)

pvalues=positions.createVariable("Values","f8",("Atoms", "XYZ"))

fvalues=forces.createVariable("Values","f8",("Atoms","XYZ"))

pvalues.units = "Angstrom"
fvalues.units = "eV/Angstrom"

rpos=np.random.rand(NATOMS,3)
rfor=np.random.rand(NATOMS,3)

np.savetxt("positions.dat",rpos)
np.savetxt("forces.dat",rfor)

pvalues[:,:] = rpos
fvalues[:,:] = rfor

rootgrp.close()

