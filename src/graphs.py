import pandas as pd
import matplotlib.pyplot as plt

# Read the preprocessed Titanic data
data = pd.read_csv('processed_data.csv')

# Create a figure with two subplots
fig, axes = plt.subplots(1, 2, figsize=(12, 6))

# Plot 1: Survival rate by passenger class
survival_rate_class = data.groupby('Pclass')['Survived'].mean()
survival_rate_class.plot(kind='bar', color='skyblue', edgecolor='black', ax=axes[0])

axes[0].set_title('Survival Rate by Passenger Class')
axes[0].set_xlabel('Passenger Class')
axes[0].set_ylabel('Survival Rate')
axes[0].set_xticks(range(len(survival_rate_class.index)))
axes[0].set_xticklabels(survival_rate_class.index, rotation=0)

# Plot 2: Survival rate by gender
survival_rate_gender = data.groupby('Sex')['Survived'].mean()
survival_rate_gender.plot(kind='bar', color='lightcoral', edgecolor='black', ax=axes[1])

axes[1].set_title('Survival Rate by Gender')
axes[1].set_xlabel('Gender')
axes[1].set_ylabel('Survival Rate')
axes[1].set_xticks(range(len(survival_rate_gender.index)))
axes[1].set_xticklabels(['Female', 'Male'], rotation=0)

# Adjust layout and save the plot
plt.tight_layout()
plt.savefig('survival_rate_comparison.png')
plt.show()