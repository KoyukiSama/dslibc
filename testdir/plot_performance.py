import matplotlib.pyplot as plt

# Performance data for C ArrayList
c_inserts = [
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000
]

c_times = [
    0.000015,
    0.000153,
    0.001439,
    0.015470,
    0.156944,
    1.507608,
    15.581097,
    151.351830
]

# Performance data for C++ std::vector
cpp_inserts = [
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000
    #100000000
]

cpp_times = [
    4e-06,
    1.2e-05,
    0.000346,
    0.047839,
    6.11206,
    640.88
    # Time for 100,000,000 inserts
]

# Plotting
plt.figure(figsize=(14, 8))

# Plot C ArrayList data
plt.plot(c_inserts, c_times, marker='o', linestyle='-', color='blue', label='C ArrayList')

# Plot C++ std::vector data
plt.plot(cpp_inserts, cpp_times, marker='s', linestyle='-', color='red', label='C++ std::vector')

# Setting log scale for both axes
plt.xscale('log')
plt.yscale('log')

# Adding labels and title
plt.xlabel('Number of Inserts', fontsize=14)
plt.ylabel('Time (seconds)', fontsize=14)
plt.title('Performance Comparison: C ArrayList vs C++ std::vector', fontsize=16)

# Adding legend
plt.legend(fontsize=12)

# Adding grid
plt.grid(True, which="both", ls="--", linewidth=0.5)

# Adjust layout for better spacing
plt.tight_layout()

# Save the plot as an image file (optional)
# plt.savefig('performance_comparison.png')

# Display the plot
plt.show()