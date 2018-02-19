import matplotlib.pyplot as plt
import numpy as np

plt.rc('text', usetex=True)
plt.rc('font', family='serif')

n_t_s = [9.0028150156, 9.0579917228, 8.9943534369, 9.0223678130, 9.0334230015, 9.0140204703, 8.9744145898, 8.9744145898, 9.0334230015, 8.9425145053, 8.8579809951, 9.0279059966, 8.8795832496, 8.9628960053, 8.9886846868, 9.0195907284,]

fig, ax1 = plt.subplots()
ax1.plot(np.arange(0,16), n_t_s)
ax1.grid(True, linestyle='--', which='major', color='lightgrey', alpha=0.5)
ax1.tick_params(labelsize='large', width=3)
ax1.set_axisbelow(True)
ax1.set_title('Number of collisions on each offset ($n=30, t=20, s=4$)', fontsize=12, fontweight='bold')
ax1.set_xlabel('offset ($[0, 2^4]$)', fontsize=12)
ax1.set_ylabel('$\log_2(\#\mathrm{collisions})$', fontsize=12)

plt.savefig('n30_t20_s4_collisions.pdf')
plt.savefig('n30_t20_s4_collisions.png')
plt.show()