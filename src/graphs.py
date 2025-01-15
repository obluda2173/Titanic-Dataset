import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Read the preprocessed Titanic data
data = pd.read_csv('processed_data.csv')

# Set a consistent color palette
colors = sns.color_palette("colorblind", 4)

# Create a figure with four subplots stacked vertically
fig, axes = plt.subplots(4, 1, figsize=(12, 24))

# Plot 1: Survival rate by passenger class
survival_rate_class = data.groupby('Pclass')['Survived'].mean()
survival_rate_class.plot(kind='bar', color=colors[0], edgecolor='black', ax=axes[0])

axes[0].set_title('Survival Rate by Passenger Class', fontsize=14)
axes[0].set_xlabel('Passenger Class', fontsize=12)
axes[0].set_ylabel('Survival Rate', fontsize=12)
axes[0].bar_label(axes[0].containers[0], fmt='%.2f', fontsize=10, padding=3)

# Plot 2: Survival rate by gender
survival_rate_gender = data.groupby('Sex')['Survived'].mean()
survival_rate_gender.plot(kind='bar', color=colors[1], edgecolor='black', ax=axes[1])

axes[1].set_title('Survival Rate by Gender', fontsize=14)
axes[1].set_xlabel('Gender', fontsize=12)
axes[1].set_ylabel('Survival Rate', fontsize=12)
axes[1].set_xticklabels(['Female', 'Male'], rotation=0, fontsize=10)
axes[1].bar_label(axes[1].containers[0], fmt='%.2f', fontsize=10, padding=3)

# Plot 3: Survival rate by family size
bins = [0, 1, 3, 5, data['FamilySize'].max()]
labels = ['0', '1-2', '3-4', '5+']
data['FamilySizeGroup'] = pd.cut(data['FamilySize'], bins=bins, labels=labels, right=False)
survival_rate_family = data.groupby('FamilySizeGroup')['Survived'].mean()
survival_rate_family.plot(kind='bar', color=colors[2], edgecolor='black', ax=axes[2])

axes[2].set_title('Survival Rate by Family Size', fontsize=14)
axes[2].set_xlabel('Family Size', fontsize=12)
axes[2].set_ylabel('Survival Rate', fontsize=12)
axes[2].set_xticks(range(len(labels)))
axes[2].set_xticklabels(labels, rotation=0, fontsize=10)
axes[2].bar_label(axes[2].containers[0], fmt='%.2f', fontsize=10, padding=3)

# Plot 4: Survival rate by age group
bins = [0, 12, 18, 35, 60, 80]
labels = ['Child (0-12)', 'Teen (12-18)', 'Young Adult (18-35)', 'Adult (35-60)', 'Senior (60-80)']
data['AgeGroup'] = pd.cut(data['Age'], bins=bins, labels=labels)
survival_rate_age = data.groupby('AgeGroup')['Survived'].mean()
survival_rate_age.plot(kind='bar', color=colors[3], edgecolor='black', ax=axes[3])

axes[3].set_title('Survival Rate by Age Group', fontsize=14)
axes[3].set_xlabel('Age Group', fontsize=12)
axes[3].set_ylabel('Survival Rate', fontsize=12)
axes[3].set_xticks(range(len(labels)))
axes[3].set_xticklabels(labels, rotation=45, fontsize=10)
axes[3].bar_label(axes[3].containers[0], fmt='%.2f', fontsize=10, padding=3)

# Adjust layout and save the plot
plt.tight_layout()
plt.savefig('survival_rate_analysis.png', format='png', dpi=300)
plt.show()
