import pandas as pd
import matplotlib.pyplot as plt

# Load data
data = pd.read_csv('processed_titanic_data.csv')

# Example Analysis
print(data.describe())

# Plot Survival Rate by Class
survival_rate = data.groupby('Pclass')['Survived'].mean()
survival_rate.plot(kind='bar')
plt.title('Survival Rate by Passenger Class')
plt.xlabel('Passenger Class')
plt.ylabel('Survival Rate')
plt.show()
