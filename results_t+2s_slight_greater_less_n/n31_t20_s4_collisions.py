import matplotlib.pyplot as plt
import numpy as np

plt.rc('text', usetex=True)
plt.rc('font', family='serif')

n_t_s = [8.0660891905, 7.9657842847, 8.1032878084, 8.0334230015, 8.0334230015, 7.9772799235, 8.1241213118, 7.9008668080, 7.9307373376, 7.9829935747, 7.8826430494, 7.9772799235, 8.1799090900, 7.8948177633, 7.9600019321, 7.9600019321,]

fig, ax1 = plt.subplots()
ax1.plot(np.arange(0,16), n_t_s)
ax1.grid(True, linestyle='--', which='major', color='lightgrey', alpha=0.5)
ax1.tick_params(labelsize='large', width=3)
ax1.set_axisbelow(True)
ax1.set_title('Number of collisions on each offset ($n=31, t=20, s=4$)', fontsize=12, fontweight='bold')
ax1.set_xlabel('offset ($[0, 2^4]$)', fontsize=12)
ax1.set_ylabel('$\log_2(\#\mathrm{collisions})$', fontsize=12)

plt.savefig('n31_t20_s4_collisions.pdf')
plt.savefig('n31_t20_s4_collisions.png')
plt.show()