import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Load the CSV file
df = pd.read_csv('ressources/tab.csv')

# Define the number of curves (columns starting from Psi(0, z) to Psi(7, z))
num_curves = 8

# Extract the z values (first column)
z_values = df['z']

# Create a figure for plotting
plt.figure(figsize=(10, 6))

# Use a colormap to generate different colors for each curve
colors = plt.get_cmap('tab10')

# Plot each curve, rescaled to fit in the range (n-0.5) to (n+0.5), centered around n+0.5
for n in range(num_curves):
    # Extract the corresponding Psi(n, z) column
    y_values = df[f'Psi({n}, z)']
    
    # Rescale the y values to fit in the range n to n+1, centered at n+0.5
    y_min = y_values.min()
    y_max = y_values.max()
    
    # Normalize y values to be centered around 0.5, in the range [0, 1]
    rescaled_y = 0.5 * ((y_values - y_min) / (y_max - y_min)) + n
    
    # Choose a color from the colormap
    color = colors(n % 10)
    
    # Plot the rescaled curve and fill under it
    plt.plot(z_values, rescaled_y, label=f'Psi({n}, z)', lw=2, color=color)
    plt.fill_between(z_values, rescaled_y, n, color=color, alpha=0.3)

plt.plot(z_values, df[f'E(z)'], label=f'E(z)', lw=2, color='blue', )
plt.ylim(-0.5, 8)

# Add labels and title
plt.xlabel('z')
plt.ylabel('Psi(n, z)')
plt.title('Fonctions d\'onde Psi(n, z)')
plt.legend()

# Display the plot
plt.show()