import pandas as pd
import matplotlib.pyplot as plt

# Read the preprocessed Titanic data
data = pd.read_csv('processed_data.csv')

# Create a figure with four subplots in a 2x2 layout
fig, axes = plt.subplots(2, 2, figsize=(12, 12))

# Plot 1: Survival rate by passenger class
survival_rate_class = data.groupby('Pclass')['Survived'].mean()
survival_rate_class.plot(kind='bar', color='skyblue', edgecolor='black', ax=axes[0, 0])

axes[0, 0].set_title('Survival Rate by Passenger Class')
axes[0, 0].set_xlabel('Passenger Class')
axes[0, 0].set_ylabel('Survival Rate')
axes[0, 0].set_xticks(range(len(survival_rate_class.index)))
axes[0, 0].set_xticklabels(survival_rate_class.index, rotation=0)

# Plot 2: Survival rate by gender
survival_rate_gender = data.groupby('Sex')['Survived'].mean()
survival_rate_gender.plot(kind='bar', color='lightcoral', edgecolor='black', ax=axes[0, 1])

axes[0, 1].set_title('Survival Rate by Gender')
axes[0, 1].set_xlabel('Gender')
axes[0, 1].set_ylabel('Survival Rate')
axes[0, 1].set_xticks(range(len(survival_rate_gender.index)))
axes[0, 1].set_xticklabels(['Female', 'Male'], rotation=0)

# Plot 3: Survival rate by family size
bins = [0, 1, 3, 5, data['FamilySize'].max()]
labels = ['0', '1-2', '3-4', '5+']
data['FamilySizeGroup'] = pd.cut(data['FamilySize'], bins=bins, labels=labels, right=False)
survival_rate_family = data.groupby('FamilySizeGroup')['Survived'].mean()
survival_rate_family.plot(kind='bar', color='mediumseagreen', edgecolor='black', ax=axes[1, 0])

axes[1, 0].set_title('Survival Rate by Family Size')
axes[1, 0].set_xlabel('Family Size')
axes[1, 0].set_ylabel('Survival Rate')
axes[1, 0].set_xticks(range(len(survival_rate_family.index)))
axes[1, 0].set_xticklabels(labels, rotation=0)

# Plot 4: Survival rate by age group
bins = [0, 12, 18, 35, 60, 80]
labels = ['Child (0-12)', 'Teen (12-18)', 'Young Adult (18-35)', 'Adult (35-60)', 'Senior (60-80)']
data['AgeGroup'] = pd.cut(data['Age'], bins=bins, labels=labels)
survival_rate_age = data.groupby('AgeGroup')['Survived'].mean()
survival_rate_age.plot(kind='bar', color='orange', edgecolor='black', ax=axes[1, 1])

axes[1, 1].set_title('Survival Rate by Age Group')
axes[1, 1].set_xlabel('Age Group')
axes[1, 1].set_ylabel('Survival Rate')
axes[1, 1].set_xticks(range(len(labels)))
axes[1, 1].set_xticklabels(labels, rotation=45)

# Adjust layout and save the plot
plt.tight_layout()
plt.savefig('survival_rate_comparison.png')
plt.show()