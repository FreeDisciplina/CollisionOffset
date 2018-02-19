import matplotlib.pyplot as plt
import numpy as np

plt.rc('text', usetex=True)
plt.rc('font', family='serif')

n_t_s = [10.0000000000,  9.9787104591,  9.9541963104,  9.9943534369, 10.0014081944, 10.0195907284,  9.9929383362,  9.9844184588, 10.0182001788, 10.0416591516,  9.9307373376,  9.9801395776,  9.9322147520,  9.9585527154,  9.9701058906,  9.9083926208,]

fig, ax1 = plt.subplots()
ax1.plot(np.arange(0,16), n_t_s)
ax1.grid(True, linestyle='--', which='major', color='lightgrey', alpha=0.5)
ax1.tick_params(labelsize='large', width=3)
ax1.set_axisbelow(True)
ax1.set_title('Number of collisions on each offset ($n=29, t=20, s=4$)', fontsize=12, fontweight='bold')
ax1.set_xlabel('offset ($[0, 2^4]$)', fontsize=12)
ax1.set_ylabel('$\log_2(\#\mathrm{collisions})$', fontsize=12)

plt.savefig('n29_t20_s4_collisions.pdf')
plt.savefig('n29_t20_s4_collisions.png')
plt.show()