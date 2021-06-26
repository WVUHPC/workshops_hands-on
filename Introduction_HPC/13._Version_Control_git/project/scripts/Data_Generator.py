
# coding: utf-8

# In[13]:


get_ipython().run_line_magic('matplotlib', 'inline')
import numpy as np
import matplotlib.pyplot as plt


# In[14]:


X=np.arange(0.1,2*np.pi,0.01)


# In[15]:


Y=np.sin(X)+np.cos(10*X)


# In[25]:


plt.plot(X,Y,'.')
fig1 = plt.gcf()
fig1.savefig('../plots/wave.pdf')


# In[18]:


data=np.stack((X,Y)).T


# In[19]:


np.savetxt('../data/wave.dat', data)


# In[20]:


data.shape

