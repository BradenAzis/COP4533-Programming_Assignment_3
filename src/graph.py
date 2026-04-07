import matplotlib.pyplot as plt

files = []
times = []

with open("../runtimes.txt") as f:
    for line in f:
        parts = line.split()
        files.append(parts[0])
        times.append(float(parts[1]))

plt.figure()
plt.plot(range(len(times)), times, marker='o')
plt.xlabel("Test Case Index")
plt.ylabel("Runtime (ms)")
plt.title("HVLCS Runtime Over 10 Input Files")

plt.grid(True)
plt.tight_layout()

plt.savefig("runtime_plot.png", dpi=300, bbox_inches="tight")
plt.show()
