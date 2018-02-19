import matplotlib.pyplot as plt
import numpy as np

plt.rc('text', usetex=True)
plt.rc('font', family='serif')

n_t_s = [11.0299773466, 10.9901039639, 11.0119260663, 10.9672262588, 11.0042204663, 10.9872640121, 11.0168082877, 10.9794251953, 10.9765641234, 10.9425145053, 10.8849336479, 10.9505558970, 10.9255544399, 10.9061389962, 10.9143851322, 10.9210970881,]

fig, ax1 = plt.subplots()
ax1.plot(np.arange(0,16), n_t_s)
ax1.grid(True, linestyle='--', which='major', color='lightgrey', alpha=0.5)
ax1.tick_params(labelsize='large', width=3)
ax1.set_axisbelow(True)
ax1.set_title('Number of collisions on each offset ($n=28, t=20, s=4$)', fontsize=12, fontweight='bold')
ax1.set_xlabel('offset ($[0, 2^4]$)', fontsize=12)
ax1.set_ylabel('$\log_2(\#\mathrm{collisions})$', fontsize=12)

plt.savefig('n28_t20_s4_collisions.pdf')
plt.savefig('n28_t20_s4_collisions.png')
plt.show()