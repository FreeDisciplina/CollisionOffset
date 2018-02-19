import matplotlib.pyplot as plt
import numpy as np

plt.rc('text', usetex=True)
plt.rc('font', family='serif')

n_t_s = [6.8328900142, 6.8201789624, 7.0112272554, 6.8328900142, 6.7548875022, 6.4594316186, 6.5545888517, 6.3923174228, 6.3219280949, 6.3575520046, 5.7004397181, 5.7813597135, 6.0443941194, 6.0660891905, 5.7548875022, 6.0660891905,]

fig, ax1 = plt.subplots()
ax1.plot(np.arange(0,16), n_t_s)
ax1.grid(True, linestyle='--', which='major', color='lightgrey', alpha=0.5)
ax1.tick_params(labelsize='large', width=3)
ax1.set_axisbelow(True)
ax1.set_title('Number of collisions on each offset ($n=16, t=12, s=4$)', fontsize=12, fontweight='bold')
ax1.set_xlabel('offset ($[0, 2^4]$)', fontsize=12)
ax1.set_ylabel('$\log_2(\#\mathrm{collisions})$', fontsize=12)

plt.savefig('n16_t12_s4_collisions.pdf')
plt.savefig('n16_t12_s4_collisions.png')
plt.show()