# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    graphs.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erian <erian@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 19:31:59 by erian             #+#    #+#              #
#    Updated: 2025/01/12 19:47:20 by erian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
