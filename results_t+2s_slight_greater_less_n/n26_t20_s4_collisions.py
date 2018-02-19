import matplotlib.pyplot as plt
import numpy as np

plt.rc('text', usetex=True)
plt.rc('font', family='serif')

n_t_s = [13.0003521775, 12.9683067944, 12.9412310503, 12.9531051506, 12.9057630496, 12.8933015309, 12.8761332000, 12.8503822057, 12.8421538846, 12.7913664147, 12.7712831196, 12.7458843691, 12.7328033944, 12.7228075312, 12.7028220118, 12.6801397178,]

fig, ax1 = plt.subplots()
ax1.plot(np.arange(0,16), n_t_s)
ax1.grid(True, linestyle='--', which='major', color='lightgrey', alpha=0.5)
ax1.tick_params(labelsize='large', width=3)
ax1.set_axisbelow(True)
ax1.set_title('Number of collisions on each offset ($n=26, t=20, s=4$)', fontsize=12, fontweight='bold')
ax1.set_xlabel('offset ($[0, 2^4]$)', fontsize=12)
ax1.set_ylabel('$\log_2(\#\mathrm{collisions})$', fontsize=12)

plt.savefig('n26_t20_s4_collisions.pdf')
plt.savefig('n26_t20_s4_collisions.png')
plt.show()