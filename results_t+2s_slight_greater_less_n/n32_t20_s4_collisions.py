import matplotlib.pyplot as plt
import numpy as np

plt.rc('text', usetex=True)
plt.rc('font', family='serif')

n_t_s = [6.9886846868, 7.0223678130, 7.1189410727, 7.0443941194, 7.0768155971, 6.9425145053, 7.0768155971, 6.8201789624, 7.2191685205, 7.1292830169, 7.0000000000, 7.1799090900, 7.1699250014, 7.0112272554, 7.1497471195, 7.0768155971,]

fig, ax1 = plt.subplots()
ax1.plot(np.arange(0,16), n_t_s)
ax1.grid(True, linestyle='--', which='major', color='lightgrey', alpha=0.5)
ax1.tick_params(labelsize='large', width=3)
ax1.set_axisbelow(True)
ax1.set_title('Number of collisions on each offset ($n=32, t=20, s=4$)', fontsize=12, fontweight='bold')
ax1.set_xlabel('offset ($[0, 2^4]$)', fontsize=12)
ax1.set_ylabel('$\log_2(\#\mathrm{collisions})$', fontsize=12)

plt.savefig('n32_t20_s4_collisions.pdf')
plt.savefig('n32_t20_s4_collisions.png')
plt.show()