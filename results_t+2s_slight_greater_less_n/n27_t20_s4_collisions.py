import matplotlib.pyplot as plt
import numpy as np

plt.rc('text', usetex=True)
plt.rc('font', family='serif')

n_t_s = [12.0147179299, 11.9929383362, 11.9632573566, 11.9675865273, 11.9218409371, 11.9574648468, 11.9012440325, 11.9255544399, 11.9439799143, 11.8872206155, 11.8841705191, 11.8525295094, 11.8478403556, 11.8360503551, 11.8443134612, 11.8301190254,]

fig, ax1 = plt.subplots()
ax1.plot(np.arange(0,16), n_t_s)
ax1.grid(True, linestyle='--', which='major', color='lightgrey', alpha=0.5)
ax1.tick_params(labelsize='large', width=3)
ax1.set_axisbelow(True)
ax1.set_title('Number of collisions on each offset ($n=27, t=20, s=4$)', fontsize=12, fontweight='bold')
ax1.set_xlabel('offset ($[0, 2^4]$)', fontsize=12)
ax1.set_ylabel('$\log_2(\#\mathrm{collisions})$', fontsize=12)

plt.savefig('n27_t20_s4_collisions.pdf')
plt.savefig('n27_t20_s4_collisions.png')
plt.show()